#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"
using namespace std;
// ������� ����
int main_menu::Main()
{
	cout << "������� ����"			    << endl
		 << "1. �������"				<< endl
		 << "2. ����� �� ��������"		<< endl
		 << "3. "						<< endl
		 << "0. ����� �� ���������"		<< endl
		 << "�������� ���� �� ������� ����: ";
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
		return 0;
	case 51:
		return 0;
	case 48:
		system("pause");
		exit(0);
	default:
		cout << "\n�������� �����, ���������� ��� ���!" << endl;
		point_of_entry::ClearScreen();
		main_menu::Main();
	}
	system("pause");
	exit(0);

}

void main_menu::profile()
{
	cout << "������� ����" << endl
		<< "1. �������� ������" << endl
		<< "2. �������� ������" << endl
		<< "3. �����" << endl
		<< "0. �����" << endl
		<< "�������� ���� �� ������� ����: ";
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
		cout << "\n�������� �����, ���������� ��� ���!" << endl;
		point_of_entry::ClearScreen();
		main_menu::profile();
	}
	system("pause");
	exit(0);
}


