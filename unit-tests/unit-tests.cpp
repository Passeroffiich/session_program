#include "pch.h"
#include "CppUnitTest.h"

#include "../session_program/session_structure.h"
#include "../session_program/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	session_structure* create_session(int day, int month, int year)
	{
		session_structure* session = new session_structure;
		session->exam_date.day = day;
		session->exam_date.month = month;
		session->exam_date.year = year;
		return session;
	}
	void delete_sessions(session_structure* array[], int size)
	{
		for (int i = 0; i < size; i++) {
			delete array[i];
		}
	}
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			session_structure* sessions[3];
			sessions[0] = create_session(1, 12, 2023);
			sessions[1] = create_session(15, 12, 2023);
			sessions[2] = create_session(25, 12, 2023);
			int expected_days = 24;
			Assert::AreEqual(expected_days, get_session_days(sessions, 3));
			delete_sessions(sessions, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			session_structure* sessions[3];
			sessions[0] = create_session(1, 12, 2023);
			sessions[1] = create_session(15, 1, 2024);
			sessions[2] = create_session(25, 1, 2024);
			int expected_days = 55;
			Assert::AreEqual(expected_days, get_session_days(sessions, 3));
			delete_sessions(sessions, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			session_structure* sessions[3];
			sessions[0] = create_session(1, 12, 2023);
			sessions[1] = create_session(15, 1, 2023);
			sessions[2] = create_session(25, 1, 2023);
			int expected_days = 320;
			Assert::AreEqual(expected_days, get_session_days(sessions, 3));
			delete_sessions(sessions, 3);
		}
	};
}
