/*
Autor: Drago Šmitran
Zadatak: https://open.kattis.com/problems/timeloop
Jezik: C++
*/

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cout << i << " Abracadabra\n";
    }
}
