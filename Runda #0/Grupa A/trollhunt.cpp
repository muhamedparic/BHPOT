/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/trollhunt
Jezik: C++
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    a--;

    cout << ceil((double)a / floor(b / (double)c));
}
