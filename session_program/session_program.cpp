#include <iostream>

#include "session_structure.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
#include "processing.h"

using namespace std;

void output(session_structure* session)
{
    cout << session->student_fio.last_name << ' ';
    cout << session->student_fio.first_name << ' ';
    cout << session->student_fio.middle_name << ' ';
    cout << session->exam_date.day << '.';
    cout << session->exam_date.month << '.';
    cout << session->exam_date.year << ' ';
    cout << session->grade << ' ';
    cout << session->discipline << ' ';
    cout << '\n';
}

void show_menu()
{
    cout << "------Меню------" << '\n';
    cout << "1. Вывод всех результатов" << '\n';
    cout << "2. Вывести всех студентов и их оценки по дисциплине «История Беларуси»" << '\n';
    cout << "3. Вывести всех студентов и дисциплины с оценками выше 7 баллов" << '\n';
    cout << "4. Сортировка вставками по возрастанию фамилии" << '\n';
    cout << "5. Сортировка вставками по возрастанию названия дисциплины" << '\n';
    cout << "6. Сортировка слиянием по возрастанию фамилии" << '\n';
    cout << "7. Сортировка слиянием по возрастанию названия дисциплины" << '\n';
    cout << "Для завершения введите -1" << '\n';
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #8. Итоги сессии\n";
    cout << "Савастеев Артем Денисович\n";
    cout << '\n';
    int size;
    int filter_size = 0;
    int choise;
    session_structure* session_list[MAX_FILE_ROWS_COUNT];
    session_structure** session_filter = new session_structure * [0];
    show_menu();
    cin >> choise;
    try
    {
        readFromFile("data.txt", session_list, size);
        while (choise != -1)
        {
            switch (choise) {
            case 1:
                system("cls");
                cout << "----------Список всех результатов----------" << '\n';
                for (int i = 0; i < size; i++)
                {
                    output(session_list[i]);
                }
                cout << "----------Количество дней сессии----------" << '\n';
                cout << get_session_days(session_list, size) << "\n";
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 2:
                system("cls");
                cout << "----------Оценки всех студентов по Истории Беларуси----------" << '\n';
                session_filter = filter(session_list, size, filter_session_by_discipline, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(session_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 3:
                system("cls");
                cout << "----------Студенты и дисциплины с оценками выше 7 баллов----------" << '\n';
                session_filter = filter(session_list, size, filter_session_by_grade, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(session_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 4:
                system("cls");
                cout << "----------Сортировка вставками по возрастанию фамилии----------" << '\n';
                insertion_sort(session_list, size, compare_by_lastname);
                for (int i = 0; i < size; i++)
                {
                    output(session_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 5:
                system("cls");
                cout << "----------Сортировка вставками по возрастанию названия дисциплины----------" << '\n';
                insertion_sort(session_list, size, compare_by_discipline);
                for (int i = 0; i < size; i++)
                {
                    output(session_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 6:
                system("cls");
                cout << "----------Сортировка слиянием по возрастанию фамилии----------" << '\n';
                merge_sort(session_list, 0, size - 1, compare_by_lastname);
                for (int i = 0; i < size; i++)
                {
                    output(session_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 7:
                system("cls");
                cout << "----------Сортировка слиянием по возрастанию названия дисциплины----------" << '\n';
                merge_sort(session_list, 0, size - 1, compare_by_discipline);
                for (int i = 0; i < size; i++)
                {
                    output(session_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            default:
                cout << "Такого пункта нет!" << '\n';
                show_menu();
                cin >> choise;
                break;
            }
        }
        for (int i = 0; i < size; i++)
        {
            delete session_list[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
}
