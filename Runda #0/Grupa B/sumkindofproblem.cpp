/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/sumkindofproblem
Jezik: C++
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  while (n--)
  {
    int k, br;
    cin >> k >> br;
    int rez = br * (br + 1) / 2;
    cout << k << ' ' << rez << ' ' << 2 * rez - br << ' ' << 2 * rez << '\n';
  }
}
