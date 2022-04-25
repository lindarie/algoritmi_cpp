/* Autors: Linda Rieksta
G7. Uzrakst�t funkciju, kas  izmet no saraksta tos elementus, kuri liel�ki par iepriek��jo 
(iepriek��jais elements ir tas, kur� nor�da uz n�ko�o PIRMS izme�anas).
Programma izveidota: 05.04.2022
*/

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void print(list<int>aa) {
	for (auto it = aa.begin(); it != aa.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

void deleteElements(list<int>&aa) {
	aa.reverse(); //sarakst� elementi tiek sal�dzin�ti no beig�m
	for (auto it = aa.begin(); next(it) != aa.end();) {
		if (*it > *(next(it))) {
			it = aa.erase(it);
		}
		else {
			++it;
		}
	}
	aa.reverse();
}

int main() {
	int ok = 1;
	do {
		list<int> aa;
		int i;
		cout << "Ievadiet veselu skaitlu virkni (lai beigtu ievadiet 0):" << endl;
		cin >> i;
				
		while (i != 0) {
			aa.push_back(i);
			cin >> i;
			
		}
		cout << "Saraksts pirms dzesanas: " << endl;
		print(aa);
		deleteElements(aa);
		cout << "Saraksts pec dzesanas: " << endl;
		print(aa);
		cout << "Vai velaties turpinat [1] vai beigt [0]? ";
		cin >> ok;
		cout << endl;
	} while (ok ==1);
}

/*
+---------------+-----------------+--------------------------------+---------------------------+--------------+
| Ievades dati  | V�lam� reakcija | Rezult�ts ar saist�to sarakstu | Rezult�ts ar STL sarakstu | Vai pareizi? |
+---------------+-----------------+--------------------------------+---------------------------+--------------+
| 1 1 1         | 1 1 1           | 1 1 1                          | 1 1 1                     | +            |
| 1 2 3 4 5     | 1               | 1                              | 1                         | +            |
| 20 6 31 -2 35 | 20 6 -2         | 20 6 -2                        | 20 6 -2                   | +            |
| 3 2 1 -5      | 3 2 1 -5        | 3 2 1 -5                       | 3 2 1 -5                  | +            |
+---------------+-----------------+--------------------------------+---------------------------+--------------+
*/