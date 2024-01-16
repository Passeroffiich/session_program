#include "sort.h"
#include <iostream>

using namespace std;

int compare_by_lastname(session_structure* first, session_structure* second)
{
	string first_lastname = first->student_fio.last_name;
	string second_lastname = second->student_fio.last_name;
	return first_lastname.compare(second_lastname);
}

int compare_by_discipline(session_structure* first, session_structure* second)
{
	string first_discipline = first->discipline;
	string second_discipline = second->discipline;
	if (first_discipline.compare(second_discipline) == 0) {
		int first_grade = first->grade;
		int second_grade = second->grade;
		return first_grade < second_grade;
	}
	return first_discipline.compare(second_discipline);
}

void merge(session_structure* arr[], int l, int m, int r, int (*check)(session_structure* first, session_structure* second)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    session_structure** L = new session_structure * [n1];
    session_structure** R = new session_structure * [n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (check(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(session_structure* array[], int l, int r, int (*check)(session_structure* first, session_structure* second)) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(array, l, m, check);
        merge_sort(array, m + 1, r, check);
        merge(array, l, m, r, check);
    }
}

void insertion_sort(session_structure* array[], int size, int (*check)(session_structure* first, session_structure* second)) {
    for (int i = 1; i < size; i++) {
        session_structure* key = array[i];
        int j = i - 1;

        while (j >= 0 && check(array[j], key) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}