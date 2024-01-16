#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

int get_grade(char* str)
{
    int grade;
    grade = std::stoi(str);
    return grade;
}


void readFromFile(const char* file_name, session_structure* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            session_structure* item = new session_structure;
            file >> item->student_fio.last_name;
            file >> item->student_fio.first_name;
            file >> item->student_fio.middle_name;
            file >> tmp_buffer;
            item->exam_date = convert(tmp_buffer);
            file >> tmp_buffer;
            item->grade = get_grade(tmp_buffer);
            file.read(tmp_buffer, 1);
            file.getline(item->discipline, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка чтения файла";
    }
}