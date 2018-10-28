/*
ID: Muamer Paric
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int r(25), s(0), cw(0);
    string str;
    cin >> str;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='W')
        {
            cw++;
            s++;
            if(cw>=3 && r>5) s++;

            if(r<=10)
            {
                if(s>5)
                {
                    r--;
                    s-=5;
                }
            }
            else if(r<=15)
            {
                if(s>4)
                {
                    r--;
                    s-=4;
                }
            }
            else if(r<=20)
            {
                if(s>3)
                {
                    r--;
                    s-=3;
                }
            }
            else
            {
                if(s>2)
                {
                    r--;
                    s-=2;
                }
            }

            if(r<=0)
            {
                cout << "Legend";
                return 0;
            }
        }
        else if(str[i]=='L' && r<=20)
        {
            cw=0;
            s--;

            if(s<0)
            {
                if(r<10)
                {
                    s=4;
                }
                else if(r<15)
                {
                    s=3;
                }
                else if(r<20)
                {
                    s=2;
                }
                else if(r==20)
                {
                    s=0;
                    r--;
                }

                r++;
            }
        }
        else if(str[i]=='L')
        {
            cw=0;
        }
    }

    cout << r;

    return 0;
}
