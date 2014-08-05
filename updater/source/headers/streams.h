#ifndef STREAMS_H
  #define STREAMS_H

  #include "libraries.h"

  #define CHANGES_FILE "edits.txt"
  #define TEMP_A "tempA.txt"
  #define TEMP_B "tempB.txt"

  namespace streams
    {
    extern fstream changesFile;
    extern fstream tempA;
    extern fstream tempB;
    extern fstream oldConfig;
    extern fstream newConfig;

    void openAll();
    void closeAll();
    void closeTemp();
    void handleErrors();
    void restart(fstream&);
    }

  #endif