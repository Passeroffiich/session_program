#include "filter.h"
#include <cstring>
#include <iostream>

session_structure** filter(session_structure* array[], int size, bool (*check)(session_structure* element), int& result_size) {
	session_structure** result = new session_structure * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;

}

bool filter_session_by_discipline(session_structure* element)
{
	return strcmp(element->discipline, "История Беларуси") == 0;
}

bool filter_session_by_grade(session_structure* element)
{
	if (element->grade >= 7) {
		return true;
	}
	return false;
}