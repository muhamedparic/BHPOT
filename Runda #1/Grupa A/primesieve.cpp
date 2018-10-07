// Autor: Drago Šmitran

#include <iostream>
#include <bitset>
#define int long long int

std::bitset<100000010> sett;

main()
{
    int n, q;
    std::cin >> n >> q;

    sett[1] = 1;
    sett[0] = 1;
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (sett[i] == 0)
        {
            if (i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                    sett[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        if (!sett[i])
            ++ans;
    }

    std::cout << ans << "\n";
    int x;
    while (q--)
    {
        std::cin >> x;

        std::cout << !sett[x] << "\n";
    }
}
