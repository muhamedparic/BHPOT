/*
Autor: Muhamed Parić
Zadatak: https://open.kattis.com/problems/pivot
Jezik: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100100];
    int largestleft[100100];
    int smallestright[100100];
    
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    largestleft[0] = arr[0];
    
    for (int i = 1; i < n; i++)
        largestleft[i] = max(largestleft[i - 1], arr[i]);
    
    smallestright[n - 1] = arr[n - 1];
    
    for (int i = n - 2; i >= 0; i--)
        smallestright[i] = min(smallestright[i + 1], arr[i]);
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
        cnt += ((arr[i] >= largestleft[i]) && (arr[i] <= smallestright[i]));
    
    cout << cnt;
}