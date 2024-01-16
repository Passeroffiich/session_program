#ifndef FILE_READER_H
#define FILE_READER_H

#include "session_structure.h"

void readFromFile(const char* file_name, session_structure* array[], int& size);

#endif