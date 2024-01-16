#ifndef SORT_H
#define SORT_H

#include "session_structure.h"

int compare_by_lastname(session_structure* first, session_structure* second);

int compare_by_discipline(session_structure* first, session_structure* second);

void merge_sort(session_structure* array[], int low, int high, int (*check)(session_structure* first, session_structure* second));

void insertion_sort(session_structure* array[], int size, int (*check)(session_structure* first, session_structure* second));

#endif