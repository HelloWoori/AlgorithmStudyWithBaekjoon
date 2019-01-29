/*
알파벳 개수
https://www.acmicpc.net/problem/10808
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    vector<int> v(26, 0);
    string str;

    cin >> str;

    for (auto s : str)
    {
        v[s - 'a']++;
    }

    for (auto x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}