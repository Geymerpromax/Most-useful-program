#include "main_menu.h"
#include "point_of_entry.h"
#include "Users.h"

void Users::set_pers_info()
{
	Users client;
	cout << "¬ведите фамилию, им€, отчество: ";
	cin >> client.fullname.surname// >> client.fullname.name >> client.fullname.patronymic;

	cout << "¬ведите дату рождени€ (день, мес€ц, год) через пробел: "; 
	cin >>// client.DateofBirth.day >> client.dateofbirth.month >> client.dateofbirth.year;
	
}

void Users::get_pers_info()
{

}
