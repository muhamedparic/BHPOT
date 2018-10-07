/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/cold
Jezik: C++
*/

#include <iostream>

using namespace std;

int main() {
    int n, sol = 0;

    cin >> n;

    while (n--) {
        int cur;
        cin >> cur;
        if (cur < 0)
            sol++;
    }

    cout << sol;
}
