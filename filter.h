#ifndef FILTER_H
#define FILTER_H

#include "session_structure.h"

session_structure** filter(session_structure* array[], int size, bool (*check)(session_structure* element), int& result_size);

bool filter_session_by_discipline(session_structure* element);

bool filter_session_by_grade(session_structure* element);

#endif