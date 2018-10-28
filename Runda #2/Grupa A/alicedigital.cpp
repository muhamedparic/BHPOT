/*
Autor: Muhamed Paric
Zadatak: https://open.kattis.com/problems/alicedigital
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> v(n);

        // Unosenje clanova vektora
        for (int &i : v)
            cin >> i;

        int best = 0;
        vector<int> cumulative(n);

        cumulative[0] = v[0];

        for (int i = 1; i < v.size(); i++)
            cumulative[i] = v[i] + cumulative[i - 1];

        vector<int> mOrSmaller; // Samo nam trebaju posljednja 2, ali memorija je jeftina

        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= m)
                mOrSmaller.push_back(i);
        }

        for (int i = 0; i < mOrSmaller.size(); i++) {
            if (v[mOrSmaller[i]] == m) {

                int seqStart, seqEnd;

                if (i == 0)
                    seqStart = 0;
                else
                    seqStart = mOrSmaller[i - 1] + 1;

                if (i == mOrSmaller.size() - 1)
                    seqEnd = v.size() - 1;
                else
                    seqEnd = mOrSmaller[i + 1] - 1;

                if (seqStart == 0)
                    best = max(best, cumulative[seqEnd]);
                else
                    best = max(best, cumulative[seqEnd] - cumulative[seqStart - 1]);
            }
        }

        cout << best << '\n';
    }
}
