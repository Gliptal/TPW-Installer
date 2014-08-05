#ifndef READER_H
  #define READER_H

  #include "libraries.h"

  namespace reader
    {
    void skipLine(fstream&);
    int readInteger(fstream&);
    char readChar(fstream&);
    string readString(fstream&);
    string readWord(fstream&);
    }

  #endif