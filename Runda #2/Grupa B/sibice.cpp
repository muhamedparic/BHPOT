/*
Autor: Drago Smitran

https://open.kattis.com/problems/sibice


*/

#include <iostream>
#include <math.h>

int main()
{
    int n, w, h;
    std::cin >> n >> w >> h;
    
    int length = sqrt(w * w + h * h);
    
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        
        if (x <= length)
            std::cout << "DA\n";
        else
            std::cout << "NE\n";
    }
}
