#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "user.h"


using namespace std;

class Worker
{

};
void reg_menu();

string encrypt(string received_login, string received_password, int name_length, int password_length)
{
	string base = {"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ0123456789абвгде"};
	string value_password = "";
	string value_login = "";
	string value = "";
	string* sent_login = new string[name_length];
	string* sent_password = new string[password_length];

	int counter = 0;
	for (int i = 0; i < name_length; i++)
	{
		for (int j = 0; j < 73; j++)
		{
			if (received_login[i] == base[j])
			{
				sent_login[i] = base[j + 1];
				counter++;
				break;
				
			}
		}
		if (counter == name_length)
		{
			break;
		}
	}
	counter = 0;
	for (int i = 0; i < password_length; i++)
	{
		for (int j = 0; j < 73; j++)
		{
			if (received_password[i] == base[j])
			{
				sent_password[i] = base[j + 1];
				counter++;
				break;
			}
		}
		if (counter == password_length)
		{
			break;
		}
	}
	for (int i = 0; i < password_length; i++)
	{
		value_password += sent_password[i];
		value_login += sent_login[i];
		value = value_password + " " + value_login;
	}
	
	
	delete[] sent_password;
	delete[] sent_login;
	return value;
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

	int rows = 2;//
	int cols = 3;//
	
	char **array = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		*array = new char[cols];
	}
	
	/*string array[2][3];*/
	fstream reg_list;
	int sum = 0;
	string value;

	reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::in | fstream::out | fstream::app);
	while (!reg_list.eof())
	{
		reg_list >> value;
		sum++;
	}
	sum /= 3;
	reg_list.close();

	reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::in | fstream::out | fstream::app);
	if (!reg_list.is_open())
	{
		//cout << "Файл не открыт!";
		return -1;
	}
	else
	{
		//cout << "Все ОК! Файл открыт!";

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				//reg_list.getline(array[i][j], 20, ' ');
				//getline(reg_list, array[i][j]);
			}
		}

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
	}
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

	cout << "1. ОК" << endl << "2. ВЫХОД" << endl;
	cout << "Выберите один из пунктов меню: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		return 1;
	case 2:

		reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::in | fstream::out | fstream::app);

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
	reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list.clear(true);
	reg_list.close();
}

void reg_menu()
{
	ClearScreen();
	cout << "Меню регистрации:" << endl;
	int name_limit = 10;
	cout << "Введите ваш логин, не более " << name_limit << " символов: "; string name; cin >> name; cout << endl;
	if (name.length() > name_limit)
	{
		ClearScreen();
		cout << "Введено более " << name_limit << " символов!" << endl << "Попробуйте ещё раз!" << endl;
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}
	int password_limit = 10;
	cout << "Введите пароль, не более " << password_limit << " символов: "; string password; cin >> password; cout << endl;
	if (password.length() > password_limit)
	{
		ClearScreen();
		cout << "Введено более " << password_limit << " символов!" << endl << "Попробуйте ещё раз!" << endl;
		int _return = OK_or_EXIT();
		if (_return == 1)
		{
			reg_menu();
		}
	}
	fstream reg_list;
	reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list << encrypt(name, password, int(name.length()), int(password.length())) << endl;
	reg_list.close();
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
		ClearScreen();
		cout << "Меню входа:" << endl;
		cout << "1. " << endl << "2. " << endl;
		cout << "Выберите один из пунктов меню: ";
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
	//reg_list.open(/*"C:\\Users\\Руслан\\Desktop\\*/"reg_list.txt", fstream::app);
	//reg_list << "sad" << endl;
	//reg_list.close();
	//abort();

	return 0;
}