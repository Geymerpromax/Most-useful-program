#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"

void Users::set_pers_info()
{
	Users client;
	cout << "������� �������, ���, ��������: ";
	cin >> client.fullname.surname// >> client.fullname.name >> client.fullname.patronymic;

	cout << "������� ���� �������� (����, �����, ���) ����� ������: "; 
	cin >>// client.DateofBirth.day >> client.dateofbirth.month >> client.dateofbirth.year;
	
}

void Users::get_pers_info()
{

}
