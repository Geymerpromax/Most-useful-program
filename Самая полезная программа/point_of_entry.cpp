#include "point_of_entry.h"
#include "main_menu.h"
#include "Users.h"

using namespace std;

// ��������� ������ c ���������� � ������ �� ���������� �����:
int point_of_entry::compare_data_for_login(string file_name, string input_data)
{
	setlocale(LC_ALL, "Russian");
	fstream file;
	file.open(file_name, fstream::in | fstream::out | fstream::app);
	if (!(file.is_open()))
	{
		cout << "������ �������� �����\n��������� ����� �������!";
		system("pause");
		exit(0);
	}
	string buf;
	
	while(!file.eof())
	{
		file >> buf;
		if (input_data == buf)
		{
			file.close();
			return 0;
		}
	}
	file.close();
	return 1;
}
int point_of_entry::compare_data_for_login(string file_name, string input_data_1, string input_data_2, string separator)
{
	string value;
	value = input_data_1 + separator + input_data_2;
	fstream file;
	file.open(file_name, fstream::in | fstream::out | fstream::app);
	if (!(file.is_open()))
	{
		cout << "������ �������� �����\n��������� ����� �������!";
		system("pause");
		exit(0);
	}
	string buf;

	while (getline(file, buf))
	{
		if (value == buf)
		{
			file.close();
			return 0;
		}
	}
	file.close();
	return 1;
}

// ����������� ������� �����:
streamoff point_of_entry::determine_file_size(string file_name)
{
	fstream file;
	file.open(file_name, fstream::in | fstream::out | fstream::app);
	if (!(file.is_open()))
	{
		point_of_entry::ClearScreen();
		cout << "������ �������� �����\n��������� ����� �������!";
		system("pause");
		exit(0);
	}
	streamoff size = file.tellg();
	file.close();
	return size;
}

// �������� �� ���� � �������:
int point_of_entry::entry_check()
{
	if (point_of_entry::determine_file_size("check_login.txt") == 0)
	{
		fstream file;
		file.open("check_login.txt", fstream::in | fstream::out | fstream::app);
		if (!(file.is_open()))
		{
			point_of_entry::ClearScreen();
			cout << "������ �������� �����\n��������� ����� �������!";
			system("pause");
			exit(0);
		}
		file << 0;
		file.close();
	}
	
	switch (point_of_entry::compare_data_for_login("0", "check_login.txt"))
	{
	case(0):
		point_of_entry::login_or_reg_menu();
	case(1):
		cout << "����� ����������!" << endl;
		main_menu::Main();
	default:
		cout << "������\n��������� ����� �������!";
		system("pause");
		exit(0);
	}
}

// �������� �������� �������� �� ����������� � ���������� �����:
bool point_of_entry::input_validation(string received_data, int length_data)
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

// ����
string point_of_entry::encrypt(string received_data, int length_data)
{
	string base = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdef" };
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

// �� ����
string point_of_entry::de_encrypt(string received_data, int length_data)
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

// ���� �����������:
void point_of_entry::reg_menu()
{
	ClearScreen();
	cout << "���� �����������:" << endl;
	int name_limit = 15;
	cout << "������� ��� �����, �� ����� " << name_limit << " ��������, ����������� ������ ��������� ����� ������: "; string name; cin >> name; cout << endl;

	if ((name.length() > name_limit) or (input_validation(name, int(name.length())) == false ))
	{
		ClearScreen();
		if (OK_or_EXIT_or_BACK() == 1)
		{
			reg_menu();
		}
		else
		{
			ClearScreen();
			login_or_reg_menu();
		}
	}
	int password_limit = 15;
	cout << "������� ������, �� ����� " << password_limit << " ��������, ����������� ������ ��������� ����� ������: "; string password; cin >> password; cout << endl;
	if ((password.length() > password_limit) or input_validation(password, int(password.length())) == false)
	{
		ClearScreen();

		if (OK_or_EXIT_or_BACK() == 1)
		{
			reg_menu();
		}
		else
		{
			ClearScreen();
			login_or_reg_menu();
		}
	}
	fstream reg_list;
	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list << encrypt(name, int(name.length())) << " " << encrypt(password, int(password.length())) << endl;
	reg_list.close();
	fstream check_login;
	check_login.open("check_login.txt", fstream::in | fstream::out);
	check_login << 1;
	check_login.close();
}

// ���� �����:
void point_of_entry::login_menu()
{
	ClearScreen();
	cout << "���� �����:" << endl;
	int name_limit = 10;
	cout << "������� ��� �����: "; string name; cin >> name; cout << endl;
	if ((name.length() > name_limit) or (input_validation(name, int(name.length())) == false))
	{
		ClearScreen();
		if (OK_or_EXIT_or_BACK() == 1)
		{
			login_menu();
		}
		else
		{
			ClearScreen();
			login_or_reg_menu();
		}
	}
	int password_limit = 10;
	cout << "������� ������: "; string password; cin >> password; cout << endl;
	if ((password.length() > password_limit) or input_validation(password, int(password.length())) == false)
	{
		if (OK_or_EXIT_or_BACK() == 1)
		{
			ClearScreen();
			login_menu();
		}
		else
		{
			ClearScreen();
			login_or_reg_menu();
		}
	}
	int total = point_of_entry::compare_data_for_login("reg_list.txt", encrypt(name, int(name.length())), encrypt(password, int(password.length())), " ");
	fstream check_login;
	switch (total)
	{
	case(0):
		check_login.open("check_login.txt", fstream::in | fstream::out);
		check_login << 1;
		check_login.close();
		cout << "����� ����������!" << endl;
		main_menu::Main();
	case(1):
		if (OK_or_EXIT_or_BACK() == 1)
		{
			login_menu();
		}
	default:
		break;
	}
}

// ����� ���� ����� ��� �����������
int point_of_entry::login_or_reg_menu()
{

	cout << "1. �����" << endl << "2. ������������������" << endl << "3. �����" << endl;
	cout << "�������� ���� �� ������� ����: ";
	char choice;
	cin >> choice;
	int res = choice - '\0';
	switch (res)
	{
	case 49:
		login_menu();
		break;
	case 50:
		reg_menu();
		break;
	case 51:
		exit(0);
	default:
		ClearScreen();
		cout << "�������� �����, ���������� ��� ���!" << endl;
		login_or_reg_menu();

	}
	return 0;
}

// ������� ������
void point_of_entry::ClearScreen()
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

// ��������� ������
int point_of_entry::OK_or_EXIT_or_BACK()
{
	fstream reg_list;
	cout << "������!" << endl;
	cout << "1. ����������� ��� ���" << endl << "2. �����" << endl << "3. ����� �� ���������" << endl;
	cout << "�������� ���� �� ������� ����: ";
	char choice;
	cin >> choice;
	int res = choice - '\0';
	switch (res)
	{
	case 49:
		return 1;
	case 50:
		return 0;
	case 51:
		system("pause");
		exit(0);
	default:
		ClearScreen();
		cout << "�������� �����, ���������� ��� ���!" << endl;
		OK_or_EXIT_or_BACK();
		return 0;
	}
}

// �����
void point_of_entry::clear_reg_list()
{
	fstream reg_list;
	reg_list.open("reg_list.txt", fstream::in | fstream::out | fstream::app);
	reg_list.clear(true);
	reg_list.close();
}

