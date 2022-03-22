/*
Rozwiazanie zadania Analizator logow
Zadanie wymaga uzycia map
Link do zadania: https://szkopul.edu.pl/problemset/problem/alo/site
Wersja 1.0
Zawiera strukture programu: switch / case
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int liczba_polecen, i;
 string adres_ip_string;
 char polecenie;
 
 cin >> liczba_polecen;
 
 for (i=1; i<=liczba_polecen; ++i) {
    cin >> polecenie;
	switch (polecenie) {
	   case 'k':
	   	  cout << "Polecenie k\n"; 
	      break;
	   case 'z':
	   	  cout << "Polecenie z\n"; 
	     break;
	   case 'w':
	   	  cout << "Polecenie w\n"; 
	      break;
	   default:
	   	  cout << "Blad\n"; 
	      break;
	}
 }

 return 0;
}


