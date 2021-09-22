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
		int num; 
		int n = 0; //summas un n(ciparu skaita) atskaite sākas no 0
		double sum = 0.0; 
		double result = 0.0; //summa ir double, jo rezultāts (vid.arit.= sum/n) var būt decimāldaļa

		cout << "Ievadi skaitli: ";
		cin >> num; 

		while (num > 0) { 
			int digit = num % 10; //definē pēdējo ciparu
			num = num / 10;
			sum = sum + digit; //kopējā ciparu summa (atskaites summa + pēdējais cipars)
			n = n++; //kopējais n(skaits)
		}

		if (n > 0) result = sum / n; 
		cout << "Videjais aritmetiskais: " << result << endl;

		cout << "Vai turpinat (1) vai beigt (0)?  ";
		cin >> a;
	} while (a == 1);

	cout << "Paldies \n";
}


/*
*| Datu ievade |  Vēlamā reakcija | Rezultāts C++ | Rezultāts Python             | Vai pareizi? |
*|-------------|------------------|---------------|------------------------------|--------------|
*| 126         | 3                | 3             | 3.0                          | +            |
*| 127         | 3.33(3)          |  3.33333      | 3.3333333333333335           | +            |
*| 9           | 9                |  9            | 9.0                          | +            |
*| 0           | 0                | 0             | name 'result' is not defined | -            |
*/

