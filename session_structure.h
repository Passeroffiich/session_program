#ifndef CONFERENCE_STRUCTURE_H
#define CONFERENCE_STRUCTURE_H

#include <string>

#include "constants.h"

struct student
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct date {
    int day;
    int month;
    int year;
};

struct session_structure
{
    student student_fio;
    date exam_date;
    int grade;
    char discipline[MAX_STRING_SIZE];
};

#endif