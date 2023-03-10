#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"
using namespace std;
// Сравнение данных c клавиатуры и данных из текстового файла:
int main_menu::Main()
{
	cout << "Главное меню" << endl
		<< "1. Профиль" << endl
		<< "2. Выйти из аккаунта" << endl
		<< "3. " << endl
		<< "0. Выйти из программы" << endl
		<< "Выберите один из пунктов меню: ";
	char choice;
	cin >> choice;
	int res = choice - '\0';
	switch (res)
	{
	case 49:
		point_of_entry::ClearScreen();
		main_menu::profile();
		return 1;
	case 50:
		main_menu::out_of_profile();
		return 0;
	case 51:
		return 0;
	case 48:
		system("pause");
		exit(0);
	default:
		cout << "\nНеверный выбор, попробуйте ещё раз!" << endl;
		point_of_entry::ClearScreen();
		main_menu::Main();
	}//
	system("pause");
	exit(0);

}

void main_menu::profile()
{
	cout << "Главное меню" << endl
		<< "1. Показать данные" << endl
		<< "2. Изменить данные" << endl
		<< "3. Назад" << endl
		<< "0. Выход" << endl
		<< "Выберите один из пунктов меню: ";
	char choice;
	cin >> choice;
	int res = choice - '\0';
	switch (res)
	{
	case 49:
		point_of_entry::ClearScreen();
	case 50:

	case 51:
		point_of_entry::ClearScreen();
		main_menu::Main();
	case 48:
		system("pause");
		exit(0);
	default:
		cout << "\nНеверный выбор, попробуйте ещё раз!" << endl;
		point_of_entry::ClearScreen();
		main_menu::profile();
	}
	system("pause");
	exit(0);
}

void main_menu::out_of_profile()
{
	fstream file;
	file.open("check_login.txt", fstream::in | fstream::out);
	if (!(file.is_open()))
	{
		point_of_entry::ClearScreen();
		cout << "Ошибка открытия файла\nПрограмма будет закрыта!";
		system("pause");
		exit(0);
	}
	file << 0;
	file.close();
	point_of_entry::ClearScreen();
	cout << "Выполнен выход из акаунта: " << endl;
	point_of_entry::login_or_reg_menu();
}

