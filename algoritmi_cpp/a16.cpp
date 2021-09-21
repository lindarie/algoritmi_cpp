/* Linda Rieksta, lr21050
*A16. Dots naturāls skaitlis. Atrast dotā skaitļa ciparu vidējo aritmētisko. Skaitļa dalīšana ciparos jāveic skaitliski.
* Programma izveidota: 2021/09/20
*/

#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	do
	{
		int num; //mainigo deklaracija
		int n = 0; //atskaiti sak no 0
		float sum = 0.0; // int sum dalot ar int n rezultatu nevar iegut float
		float result = 0.0; // vid. arit. var but decimaldala

		cout << "Ievadi skaitli: ";
		cin >> num; //datu ievade

		while (num > 0) { //cikls, kas atdala ciparus
			int digit = num % 10;
			num = num / 10;
			sum = sum + digit; //skaita ciparu summu
			n = n++; //skaita n
		}

		if (n > 0) result = sum / n; //aprekina vid. arit.
		cout << "Videjais aritmetiskais: " << result << endl;

		cout << "Vai turpinat (1) vai beigt (0)?  ";
		cin >> a;
	} while (a == 1);

	cout << "Paldies \n";
}


/* ______________________________________________________________________________________________________________________
*| Datu ievade | Vēlamā reakcija |    Rezultāts C++      | Rezultāts Python                              | Vai pareizi?  |
*| ____________|_________________|_____________________ _|_______________________________________________|_______________|
*|     126     |        3        |            3          |       3.0                                     |        +      |
*|    126.0    |kļūdas paziņojums| 3 (un pārtrauc ciklu) |invalid literal for int() with base 10: '126.0'|      - / +    |
*|     127     |    3.3333(3)    |         3.33333       |                                               |      + /      |
*|      9      |        9        |            9          |       9.0                                     |        +      |
*|     -25     |kļūdas paziņojums|            0          | name 'result' is not defined                  |      - / +    |
*|      0      |        0        |            0          |        0                                      |        +      |
*|_____________|_________________|_______________________|_______________________________________________|_______________|
*/

