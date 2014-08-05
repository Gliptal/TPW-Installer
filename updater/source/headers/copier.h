#ifndef COPIER_H
  #define COPIER_H

  #include "libraries.h"

  namespace copier
    {
    void copyFor(fstream&, fstream&, int);
    void copyLine(fstream&, fstream&);
    }

  #endif