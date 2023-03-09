#pragma once
#include "main_menu.h"
#include "Users.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class point_of_entry
{
public:
	static int compare_data_for_login(string input_data, string file_name); 
	static int compare_data_for_login(string file_name, string input_data_1, string input_data_2, string separator);
	static streamoff determine_file_size(string file_name);
	static int entry_check();
	static bool input_validation(string received_data, int length_data);
	static string encrypt(string received_data, int length_data);
	static string de_encrypt(string received_data, int length_data);
	static void ClearScreen();
	static int OK_or_EXIT_or_BACK();
	static void clear_reg_list();
	static void reg_menu();
	static void login_menu();
	static int login_or_reg_menu();
};

