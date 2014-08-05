#include "headers/libraries.h"

#include "headers/errors.h"

void errors::printAndKill(string error)
  {
  cout << endl
       << error << endl
       << endl
       << "press enter to close the program" << endl
       << endl;

  cin.ignore();
  exit(1);
  }