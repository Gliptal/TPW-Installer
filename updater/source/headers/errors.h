#ifndef ERRORS_H
  #define ERRORS_H

  #include "libraries.h"

  #define ERROR_ARGUMENTS "arguments number is wrong, please provide both target and source files"
  #define ERROR_STREAMS_EDITS "edits.txt is either corrupted or missing"
  #define ERROR_STREAMS_SOURCE "the source config file is either corrupted or missing"
  #define ERROR_STREAMS_TARGET "the target config file is either corrupted or missing"
  #define ERROR_MODE "wrong number of specified edits or mode is not defined, please use\n\t- 'a' add a line\n\t- 'r' remove a line\n\t- 'c' change a line"
  #define ERROR_OFFSET "type of offset is not defined, please use\n\t- 'a' after the specified line\n\t- 'b' before the specified line"
  #define ERROR_SEARCH "searched line was not found, please check your spelling"

  namespace errors
    {
    void printAndKill(string);
    }

  #endif