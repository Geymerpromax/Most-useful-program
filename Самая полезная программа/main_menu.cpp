#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"
using namespace std;
// Ãëàâíîå ìåíþ
int main_menu::Main()
{
	cout << "Ãëàâíîå ìåíþ"			    << endl
		 << "1. Ïðîôèëü"				<< endl
		 << "2. Âûéòè èç àêêàóíòà"		<< endl
		 << "3. "						<< endl
		 << "0. Âûéòè èç ïðîãðàììû"		<< endl
		 << "Âûáåðèòå îäèí èç ïóíêòîâ ìåíþ: ";
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
		cout << "\nÍåâåðíûé âûáîð, ïîïðîáóéòå åù¸ ðàç!" << endl;
		point_of_entry::ClearScreen();
		main_menu::Main();
	}//
	system("pause");
	exit(0);

}

void main_menu::profile()
{
	cout << "Ãëàâíîå ìåíþ" << endl
		<< "1. Ïîêàçàòü äàííûå" << endl
		<< "2. Èçìåíèòü äàííûå" << endl
		<< "3. Íàçàä" << endl
		<< "0. Âûõîä" << endl
		<< "Âûáåðèòå îäèí èç ïóíêòîâ ìåíþ: ";
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
		cout << "\nÍåâåðíûé âûáîð, ïîïðîáóéòå åù¸ ðàç!" << endl;
		point_of_entry::ClearScreen();
		main_menu::profile();
	}
	system("pause");
	exit(0);
}


