#include "headers/libraries.h"

#include "headers/copier.h"
#include "headers/reader.h"
#include "headers/writer.h"

void copier::copyFor(fstream& source, fstream& target, int times)
  {
  for(int i = 0; i < times; i += 1)
    copier::copyLine(source, target);
  }

void copier::copyLine(fstream& source, fstream& target)
  {
  string line = reader::readString(source);
  writer::writeString(target, line);
  }