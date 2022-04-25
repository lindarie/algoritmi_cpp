/* Autors: Linda Rieksta
G7. Uzrakstît funkciju, kas  izmet no saraksta tos elementus, kuri lielâki par iepriekðçjo
(iepriekðçjais elements ir tas, kurð norâda uz nâkoðo PIRMS izmeðanas).
Programma izveidota: 05.04.2022
*/
#include <iostream>
using namespace std;

struct elem
{
	int num;
	elem* next;
};

void append(elem*& first, elem*& last, int n) {
	elem* p = new elem;
	p->num = n;
	p->next = NULL;
	if (first == NULL) {
		first = last = p;
	}
	else {
		last->next = p; 
		last = p; 
	}
}
void print(elem* first) {
	elem* p = first;
	if (!p){ 
		cout << "Tukss saraksts" << endl; 
		return; 
	}
	while (p) {
		cout << p->num << " ";
		p = p->next;
	}
	cout << endl;
}

void removeElements(elem*& first, elem*& last) {
	elem* k = last;
	elem* s;
	while (k != first) {
	for (s = first; s != k; s = s->next) { //meklç elementu s pirms elementa k
		if (s->next == k) { 
			if (s->num < k->num) {
				if (k == last) { 
					delete last;
					s->next = NULL;
					last = s;
				}
				else {
					s->next = k->next;
					delete k;
				}
			}
			k = s;
			break;
		}
	}
	}
}

void deleteList(elem* first) {
	elem* p = first;
	while (p != NULL)
	{
		first = first->next;
		delete p;
		p = first;
	};
	cout << "Saraksts ir izdzests" << endl;
}

int main() {
	int ok = 1;
	do {
		elem* first = NULL, * last = NULL;
		int i;
		cout << "Ievadiet veselu skaitlu virkni (lai beigtu ievadiet 0): " << endl;
		cin >> i;
		while (i != 0) {
			append(first, last, i);
			cin >> i;
		}

		cout << "Skaitlu virkne pirms dzesanas: " << endl;
		print(first);

		removeElements(first, last);

		cout << "Skaitlu virkne pec dzesanas: " << endl;
		print(first);

		deleteList(first);

		cout << "Vai velaties turpinat [1] vai beigt [0]? ";
		cin >> ok;
		cout << endl;
	} while (ok == 1);
};


/*
+---------------+-----------------+--------------------------------+---------------------------+--------------+
| Ievades dati  | Vçlamâ reakcija | Rezultâts ar saistîto sarakstu | Rezultâts ar STL sarakstu | Vai pareizi? |
+---------------+-----------------+--------------------------------+---------------------------+--------------+
| 1 1 1         | 1 1 1           | 1 1 1                          | 1 1 1                     | +            |
| 1 2 3 4 5     | 1               | 1                              | 1                         | +            |
| 20 6 31 -2 35 | 20 6 -2         | 20 6 -2                        | 20 6 -2                   | +            |
| 3 2 1 -5      | 3 2 1 -5        | 3 2 1 -5                       | 3 2 1 -5                  | +            |
+---------------+-----------------+--------------------------------+---------------------------+--------------+
*/