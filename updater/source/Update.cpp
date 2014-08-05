#include "headers/libraries.h"
#include "headers/errors.h"

#include "headers/update.h"
#include "headers/streams.h"
#include "headers/reader.h"
#include "headers/writer.h"
#include "headers/copier.h"

string oldConfigName;
string newConfigName;

fstream* source;
fstream* target;

void checkArguments(int);
void applyArguents(char**);
void setStreams(int, int);
void getEdit(char&, string&, char&, string&);
void makeEdit(char&, char&, string&, int&);
int reachEdit(string);
void reachEnd();
int findOldLineNumber(string&);

int main(int argc, char** argv)
  {
  checkArguments(argc);
  applyArguents(argv);

  streams::openAll();
  streams::handleErrors();
  source = &streams::oldConfig;
  target = &streams::newConfig;

  int totalEdits = reader::readInteger(streams::changesFile);

  if (totalEdits == 0)
    reachEnd();
  else
    {
    for (int i = 1; i <= totalEdits; i += 1)
      {
      char mode;
      string newData;
      char offset = ' ';
      string oldData;

      setStreams(i, totalEdits);

      getEdit(mode, newData, offset, oldData);

      int lineNumber = reachEdit(oldData);
      makeEdit(mode, offset, newData, lineNumber);
      reachEnd();

      streams::closeTemp();
      }
    }

  streams::closeAll();

  return 0;
  }

void checkArguments(int argc)
  {
  if (argc != 2+1)
    errors::printAndKill(ERROR_ARGUMENTS);
  }

void applyArguents(char** argv)
  {
  oldConfigName = argv[1];
  newConfigName = argv[2];
  }

void setStreams(int reachedEdit, int totalEdits)
  {
  if (totalEdits >= 2)
    {
    if (reachedEdit == 1)
      {
      streams::tempA.open(TEMP_A, fstream::out);

      source = &streams::oldConfig;
      target = &streams::tempA;
      }
    else if (reachedEdit == totalEdits && reachedEdit%2 == 0)
      {
      streams::tempA.open(TEMP_A, fstream::in);

      source = &streams::tempA;
      target = &streams::newConfig;
      }
    else if (reachedEdit == totalEdits && reachedEdit%2 != 0)
      {
      streams::tempB.open(TEMP_B, fstream::in);

      source = &streams::tempB;
      target = &streams::newConfig;
      }
    else if (reachedEdit%2 == 0)
      {
      streams::tempA.open(TEMP_A, fstream::in);
      streams::tempB.open(TEMP_B, fstream::out);

      source = &streams::tempA;
      target = &streams::tempB;
      }
    else if (reachedEdit%2 != 0)
      {
      streams::tempB.open(TEMP_B, fstream::in);
      streams::tempA.open(TEMP_A, fstream::out);

      source = &streams::tempB;
      target = &streams::tempA;
      }
    }
  }

void getEdit(char& mode, string& newData, char& offset, string& oldData)
  {
  reader::skipLine(streams::changesFile);

  mode = reader::readChar(streams::changesFile);

  switch(mode)
    {
    case EDIT_ADD:
      newData = reader::readString(streams::changesFile);
      offset = reader::readChar(streams::changesFile);
      oldData = reader::readString(streams::changesFile);
      break;

    case EDIT_REMOVE:
      oldData = reader::readString(streams::changesFile);
      break;

    case EDIT_CHANGE:
      oldData = reader::readString(streams::changesFile);
      newData = reader::readString(streams::changesFile);
      break;

    default:
      errors::printAndKill(ERROR_MODE);
      break;
    }
  }

void makeEdit(char& mode, char& offset, string& newData, int& lineNumber)
  {
  switch(mode)
    {
    case EDIT_ADD:
      switch(offset)
        {
        case OFFSET_AFTER:
          copier::copyLine(*source, *target);

          writer::writeString(*target, newData);
          break;

        case OFFSET_BEFORE:
          writer::writeString(*target, newData);
          break;

        default:
          errors::printAndKill(ERROR_OFFSET);
          break;
        }
      break;

    case EDIT_REMOVE:
      reader::skipLine(*source);
      break;

    case EDIT_CHANGE:
      writer::writeString(*target, newData);
      reader::skipLine(*source);
      break;
    }
  }

int reachEdit(string oldData)
  {
  int lineNumber = findOldLineNumber(oldData);
  streams::restart(*source);

  copier::copyFor(*source, *target, lineNumber-1);

  return lineNumber;
  }

void reachEnd()
  {
  while (!(*source).eof())
    copier::copyLine(*source, *target);
  }

int findOldLineNumber(string& wantedData)
  {
  int lineNumber = 0;
  string currentData;

  do
    {
    lineNumber += 1;
    currentData = reader::readWord(*source);
    }
  while (currentData != wantedData && !(*source).eof());

  if ((*source).eof())
    errors::printAndKill(ERROR_SEARCH);

  return lineNumber;
  }

