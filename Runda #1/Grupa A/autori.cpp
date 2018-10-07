/*
Zadatak: https://open.kattis.com/problems/autori
Autor: Muhamed Parić
Jezik: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || s[i - 1] == '-')
            cout << s[i];
    }
}
