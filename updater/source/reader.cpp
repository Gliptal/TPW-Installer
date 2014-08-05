#include "headers/libraries.h"

#include "headers/reader.h"

static string stream;

void reader::skipLine(fstream& file)
  {
  getline(file, stream);
  }

int reader::readInteger(fstream& file)
  {
  getline(file, stream);

  return atoi(stream.c_str());
  }

char reader::readChar(fstream& file)
  {
  getline(file, stream);

  return stream[0];
  }

string reader::readString(fstream& file)
  {
  getline(file, stream);

  return stream;
  }

string reader::readWord(fstream& file)
  {
  getline(file, stream);
  stream = stream.substr(0, stream.find(" "));

  return stream;
  }