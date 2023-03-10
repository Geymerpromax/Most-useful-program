#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"

void Users::set_pers_info()
{
	Users client;
	cout << "Введите фамилию, имя, отчество: ";
	cin >> client.surname;
	/*
	if ((password.length() > password_limit) or input_validation_eu(password, int(password.length())) == false)
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
	*/
	cin >> client.name; point_of_entry::input_validation_ru(client.name, client.name.length());
	cin >> client.patronymic; point_of_entry::input_validation_ru(client.patronymic, client.patronymic.length());

	cout << "Введите дату рождения (день, месяц, год) через пробел: ";
	cin >> client.day >> client.month >> client.year;
	fstream file;
	file.open("users_data.txt", fstream::in | fstream::out | fstream::app);
	if (!(file.is_open()))
	{
		point_of_entry::ClearScreen();
		cout << "Ошибка открытия файла\nПрограмма будет закрыта!";
		system("pause");
		exit(0);
	}

	file << client.surname << " " << client.name << " " << client.patronymic << " " << client.day << "." << client.month << "." << client.year;
	file.close();
}

void Users::get_pers_info()
{

}