#include "headers/libraries.h"

#include "headers/writer.h"

void writer::writeString(fstream& target, string line)
  {
  target << line << endl;
  }