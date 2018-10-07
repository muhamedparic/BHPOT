/*
ID: Muamer Paric
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);


    int n, l;
    string s;
    cin >> n;

    while(n--)
    {
        cin >> l >> s;

        int zadnji[300], cekanje_prije(0), cekanje_poslije(0);

        for(int i=0;i<l;i++)
        {
            zadnji[s[i]]=i;
        }

        for(int i=0;i<l;i++)
        {
            cekanje_prije+=5*(zadnji[s[i]]-i);
        }

        sort(s.begin(), s.end());

        for(int i=0;i<l;i++)
        {
            zadnji[s[i]]=i;
        }

        for(int i=0;i<l;i++)
        {
            cekanje_poslije+=5*(zadnji[s[i]]-i);
        }

        cout << cekanje_prije-cekanje_poslije << endl;
    }

    return 0;
}
