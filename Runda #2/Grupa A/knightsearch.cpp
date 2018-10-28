/*
Autor: Drago Smitran
https://open.kattis.com/problems/knightsearch

*/

#include <iostream>

std::string toFind = "ICPCASIASG";
char a[110][110];
int n;

bool findString(int curlength, int curi, int curj)
{
    if (curi >= n || curi < 0)
        return 0;
    if (curj >= n || curi < 0)
        return 0;

    if (toFind[curlength] != a[curi][curj])
    {
        return 0;
    }

    if (curlength == 9)
        return 1;

    ++curlength;
    return  findString(curlength, curi + 2, curj + 1) ||
            findString(curlength, curi + 2, curj - 1) ||
            findString(curlength, curi - 2, curj + 1) ||
            findString(curlength, curi - 2, curj - 1) ||
            findString(curlength, curi + 1, curj + 2) ||
            findString(curlength, curi + 1, curj - 2) ||
            findString(curlength, curi - 1, curj + 2) ||
            findString(curlength, curi - 1, curj - 2);

}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 'I')
            {
                if (findString(0, i, j))
                {
                    std::cout << "YES";
                    return 0;
                }
            }
        }
    }

    std::cout << "NO";
}

