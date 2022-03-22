#include <bits/stdc++.h>
using namespace std;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 map<long long, int> wagony;
 map<long long, int>::iterator it;
 int max_w_wagonie, ile_zakupow;
 long long akt_wagon, szukany_wagon;
 int bilety;
 int i;
 
 cin >> ile_zakupow >> max_w_wagonie >> szukany_wagon;
 
 for (i=1; i<=ile_zakupow; ++i) {
    cin >> akt_wagon >> bilety;
    if ( wagony[akt_wagon]+bilety <= max_w_wagonie )
       wagony[akt_wagon]  = wagony[akt_wagon] + bilety;
 }
 
 cout << wagony.size() << "\n"; 
 for (it=wagony.begin(); it!=wagony.end(); ++it)
    cout << it->first << " " << it->second << '\n';

 it = wagony.lower_bound (szukany_wagon);
 if ( it == wagony.end() )
    --it;
 cout << it->first << " " << it->second << '\n';
 
 return 0;
}

