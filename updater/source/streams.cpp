#include "headers/libraries.h"
#include "headers/errors.h"

#include "headers/streams.h"
#include "headers/update.h"

fstream streams::changesFile;
fstream streams::tempA;
fstream streams::tempB;
fstream streams::oldConfig;
fstream streams::newConfig;

void streams::openAll()
  {
  changesFile.open(CHANGES_FILE, fstream::in);
  oldConfig.open(oldConfigName, fstream::in);
  newConfig.open(newConfigName, fstream::out);
  }

void streams::closeAll()
  {
  changesFile.close();
  oldConfig.close();
  newConfig.close();
  }

void streams::closeTemp()
  {
  tempA.close();
  tempB.close();
  }

void streams::handleErrors()
  {
  if (changesFile.bad())
    errors::printAndKill(ERROR_STREAMS_EDITS);

  if (oldConfig.bad())
    errors::printAndKill(ERROR_STREAMS_SOURCE);

  if (newConfig.bad())
    errors::printAndKill(ERROR_STREAMS_TARGET);
  }

void streams::restart(fstream& file)
  {
  file.seekg (0, ios_base::beg);
  file.seekg (0, ios_base::beg);
  }