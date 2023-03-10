#pragma once
#include "main_menu.h"
#include "point_of_entry.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
class Users
{
public:
	static void set_pers_info();
	static void get_pers_info();
private:
	string surname;
	string name;
	string patronymic;
	int day;
	int month;
	int year;
	int age;
};
