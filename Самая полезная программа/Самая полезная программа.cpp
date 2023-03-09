#include "point_of_entry.h"
#include "main_menu.h"
#include "Users.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
	system("chcp 1251");
	system("cls");
	point_of_entry::entry_check();
	return 0;
}