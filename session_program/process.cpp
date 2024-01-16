#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "processing.h"

using namespace std;

std::chrono::system_clock::time_point parse_date(const date& d) {
	tm tm = {};
	tm.tm_mday = d.day;
	tm.tm_mon = d.month - 1; 
	tm.tm_year = d.year - 1900; 
	return chrono::system_clock::from_time_t(mktime(&tm));
}

int get_session_days(session_structure* array[], int size)
{
	auto lowest_date = parse_date(array[0]->exam_date);
	auto highest_date = parse_date(array[0]->exam_date);
	auto current_date = parse_date(array[0]->exam_date);
	for (int i = 0; i < size; i++) {
		current_date = parse_date(array[i]->exam_date);
		if (lowest_date > current_date) {
			lowest_date = current_date;
		}
		else if (highest_date < current_date) {
			highest_date = current_date;
		}
	}
	auto duration = highest_date - lowest_date;
	return chrono::duration_cast<chrono::hours>(duration).count() / 24;
}
