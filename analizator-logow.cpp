/*
Rozwiazanie zadania Analizator logow
Zadanie wymaga uzycia map
Link do zadania: https://szkopul.edu.pl/problemset/problem/alo/site
Wersja 1.1
Zawiera 
a. strukture programu: switch / case
b. map
c. Wczytywanie wypisywanie
 */


#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Wczytyjemy adres IP (cztery liczby int) do vector adres_ip_vector
//znak & oznacza, ze zmiana adres_ip_vector bedzie widoczna w funkcji 
//wywolujacej - konkretnie dzialamy na tej samej pamieci zmiennej co
//glowna funkcja
void WczytajAdresIP (vector<int> &adres_ip_vector) {
 int oktet, i;

 adres_ip_vector.clear(); //usuwamy wszystko z vectora (poprzedni IP)
 for (i=0; i<=3; ++i) {
    cin >> oktet;
	adres_ip_vector.push_back(oktet);
 } 
}

//Wypisujemy adres - zawartość vector-a adres_ip_vector
//(const &) oznacza, ze dzialamy na tej samej pamieci zmiennej co
//glowna funkcja ale nie mozemy niczego zmieniac
//nie mamy potrzeby - tylko wypisujemy
void WypiszAdresIP (const vector<int> &adres_ip_vector) {
 int i;

 for (i=0; i<=3; ++i)
 	cout << adres_ip_vector[i] << ' ';

}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

//map (tablica); klucze(indeksy) to vector czyli adres ip
//wartosci to int czyli ile razy adres ip wystapil
//uporzadkowanie kluczy(indeksow) definiuje struktura Porownaj
//np:  10 30 20 40   5  
 map < vector<int>, int, Porownaj > ile_razy_adres_ip;
 map < vector<int>, int >::iterator it;
 vector<int> adres_ip_vector; //pojedynczy adres ip - cztery liczby
 int liczba_polecen, i;
 string adres_ip_string;
 char polecenie;
 
 cin >> liczba_polecen;
 
 for (i=1; i<=liczba_polecen; ++i) {
    cin >> polecenie;
	switch (polecenie) {
	   case 'k':
	   	  WczytajAdresIP (adres_ip_vector); 
		  ++ile_razy_adres_ip[adres_ip_vector];
	      break;
	   case 'z':
	   	  WczytajAdresIP (adres_ip_vector); 
		  WypiszAdresIP (adres_ip_vector);
   	      if ( ile_razy_adres_ip.count(adres_ip_vector) == 0 )
   	         cout << 0 << "\n";
          else
   		     cout << ile_razy_adres_ip[adres_ip_vector] << "\n";
	     break;
	   case 'w':
          for (it=ile_razy_adres_ip.begin(); it!=ile_razy_adres_ip.end(); ++it) {
     	     WypiszAdresIP (it->first);
             cout << it->second << "\n";
		  }
	   default:
	      break;
	}
 }

 return 0;
}


