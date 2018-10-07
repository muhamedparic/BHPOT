/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/loowater
Jezik: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int heads[20010];
  int knights[20010];

  ios_base::sync_with_stdio(0);

  while (1)
  {
    int n, m;
    cin >> n >> m;

    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> heads[i];

    for (int j = 0; j < m; j++)
      cin >> knights[j];

    sort(heads, heads + n);
    sort(knights, knights + m);

    int hit = 0, kit = 0;
    int sum = 0;

    while (hit < n && kit < m)
    {
      if (heads[hit] <= knights[kit])
      {
        sum += knights[kit];
        hit++;
        kit++;
      }
      else
      {
        kit++;
      }
    }

    if (hit == n)
      cout << sum << '\n';
    else
      cout << "Loowater is doomed!" << '\n';
    }
  }
