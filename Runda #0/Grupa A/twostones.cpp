/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/twostones
Jezik: C++
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 1)
        cout << "Alice";
    else
        cout << "Bob";
}
