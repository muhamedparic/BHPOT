/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/aliennumbers
Jezik: C++
*/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {

        string num, source, target;
        cin >> num >> source >> target;
        long long val = 0;

        reverse(num.begin(), num.end());

        for (int i = 0; i < num.length(); i++) {
            val += (find(source.begin(), source.end(), num[i]) - source.begin()) * pow(source.length(), i);
        }

        string out;

        if (val == 0) {
            cout << target[0];
        } else {
            while (val > 0) {

                out += target[val % target.length()];
                val /= target.length();
            }
            reverse(out.begin(), out.end());
            cout << "Case #" << tt + 1 << ": " << out << endl;
        }
    }
}
