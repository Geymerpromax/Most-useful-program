#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "user.h"
using namespace std;
void reg_menu();
void main_menu();
void ClearScreen();
int Get_reg_list();
int OK_or_EXIT();
void clear_reg_list();
void reg_menu();
void login_menu();
int login_or_reg_menu();

class Worker
{

};

void main_menu()
{
	cout << "Добро пожаловать в программу";
	exit(0);
}

bool input_validation(string received_data, int length_data)
{
	string base = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
	string* sent_data = new string[length_data];
	int counter = 0;
	for (int i = 0; i < length_data; i++)
	{
		for (int j = 0; j < 62; j++)
		{
			
			if (received_data[i] == base[j])
			{
				counter++;
				break;
			}
			
			if (j == 61)
			{
				delete[] sent_data;
				return false;
			}
			
		}
		if (counter == length_data)
		{
			break;
		}
	}

	delete[] sent_data;
	return true;
}

string encrypt(string received_data, int length_data)
{
	string base = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdef"};
	string value_data = "";
	string* sent_data = new string[length_data];
	int counter = 0;
	for (int i = 0; i < length_data; i++)
	{
		for (int j = 0; j < 62; j++)
		{
			if (received_data[i] == base[j])
			{
				sent_data[i] = base[j + 1];
				counter++;
				break;
				
			}
		}
		if (counter == length_data)
		{
			break;
		}
	}

	for (int i = 0; i < length_data; i++)
	{
		value_data += sent_data[i];
	}
	
	delete[] sent_data;
	return value_data;
}

string de_encrypt(string received_data, int length_data)
{
	string base = { "9abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
	string value_data = "";
	string* sent_data = new string[length_data];
	int counter = 0;
	for (int i = 0; i < length_data; i++)
	{
		for (int j = 1; j < 62; j++)
		{
			if (received_data[i] == base[j])
			{
				sent_data[i] = base[j - 1];
				counter++;
				break;

			}
		}
		if (counter == length_data)
		{
			break;
		}
	}

	for (int i = 0; i < length_data; i++)
	{
		value_data += sent_data[i];
	}

	delete[] sent_data;
	return value_data;
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int Get_reg_list()
{

	int rows = 2;
	int cols = 3;
	
	char **array = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		*array = new char[cols];
	}
	
	/*string array[2][3];*/
	fstream reg_list;
	int sum = 0;
	string value;

	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	while (!reg_list.eof())
	{
		reg_list >> value;
		sum++;
	}
	sum /= 3;
	reg_list.close();

	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);

	
	reg_list.close();
		/*
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j];
				if ((j == 0) or (j == 1))
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		*/
	
	/*
	for (int i = 0; i < 20; i++)
	{
		delete[] array[i];
		array[i] = nullptr;
	}
	delete[] array;
	array = nullptr;
	*/
	return 0;
	
}

int OK_or_EXIT()
{
	fstream reg_list;
	cout << "Ошибка!" << endl << "Попробуйте ещё раз!" << endl;
	cout << "1. ОК" << endl << "2. ВЫХОД" << endl;
	cout << "Выберите один из пунктов меню: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		return 1;
	case 2:

		reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);

		reg_list.close();
		exit(0);
		
	default:
		ClearScreen();
		cout << "Неверный выбор, попробуйте ещё раз!" << endl;
		OK_or_EXIT();
	}
}

void clear_reg_list()
{
	fstream reg_list;
	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list.clear(true);
	reg_list.close();
}

void reg_menu()
{
	ClearScreen();
	cout << "Меню регистрации:" << endl;
	int name_limit = 10;
	cout << "Введите ваш логин, не более " << name_limit << " символов, используйте только латинские буквы ицифры: "; string name; cin >> name; cout << endl;

	if ((name.length() > name_limit) or (input_validation(name, int(name.length())) == false))
	{
		ClearScreen();
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}
	int password_limit = 10;
	cout << "Введите пароль, не более " << password_limit << " символов, используйте только латинские буквы ицифры: "; string password; cin >> password; cout << endl;
	if ((password.length() > password_limit) or input_validation(password, int(password.length())) == false)
	{
		ClearScreen();
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}
	fstream reg_list;
	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list << encrypt(name, int(name.length()));
	reg_list << " ";
	reg_list << encrypt(password,  int(password.length()));
	reg_list << endl;
	reg_list.close();
}

void login_menu()
{
	ClearScreen();
	cout << "Меню Входа:" << endl;
	int name_limit = 10;
	cout << "Введите ваш логин: "; string name; cin >> name; cout << endl;

	if ((name.length() > name_limit) or (input_validation(name, int(name.length())) == false))
	{
		ClearScreen();
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}
	int password_limit = 10;
	cout << "Введите пароль: "; string password; cin >> password; cout << endl;
	if ((password.length() > password_limit) or input_validation(password, int(password.length())) == false)
	{
		ClearScreen();
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}

	fstream reg_list;
	string value1, value2;
	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	
	value1 = encrypt(name, int(name.length())) + " " + encrypt(password, int(password.length()));
	for (int i = 0; ; i++)
	{
		getline(reg_list, value2);
		if (value1 == value2)
		{
			main_menu();
		}
		else
		{
			if (OK_or_EXIT() == 1)
			{
				reg_list.close();
				login_menu();
			}

		}
		/*
		if (reg_list.fail())
		{
			break;
		}
		*/
	}
}

int login_or_reg_menu()
{

	cout << "1. Войти" << endl << "2. Зарегестрироваться" << endl << "3. Выход" << endl;
	cout << "Выберите один из пунктов меню: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		login_menu();
		break;
	case 2:
		reg_menu();
		break;
	case 3:
		exit(0);
	default:
		ClearScreen();
		cout << "Неверный выбор, попробуйте ещё раз!" << endl;
		login_or_reg_menu();

	}
	return 0;
}

int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "ru");
	cout << "Приветствуем в нашей программе!" << endl;
	login_or_reg_menu();
	//Get_reg_list();

	//fstream reg_list;
	//reg_list.open("reg_list.txt", fstream::app);
	//reg_list << "sad" << endl;
	//reg_list.close();
	//abort();

	return 0;
}
