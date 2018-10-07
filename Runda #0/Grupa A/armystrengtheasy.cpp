/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/armystrengtheasy
Jezik: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int g_monsters, mg_monsters;
        cin >> g_monsters >> mg_monsters;

        int g_strongest = -100000, mg_strongest = -100000;

        while (g_monsters--) {
            int monster;
            cin >> monster;
            g_strongest = max(g_strongest, monster);
        }

        while (mg_monsters--) {
            int monster;
            cin >> monster;
            mg_strongest = max(mg_strongest, monster);
        }

        if (g_strongest >= mg_strongest)
            cout << "Godzilla\n";
        else
            cout << "MechaGodzilla\n";
    }
}
