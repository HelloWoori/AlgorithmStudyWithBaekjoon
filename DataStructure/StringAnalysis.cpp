/*
문자열 분석
https://www.acmicpc.net/problem/10820
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string str;
    vector<int> v(4, 0);
    while (getline(cin, str))
    {
        for (auto ch : str)
        {
            if (ch >= 'a' && ch <= 'z')
                v[0]++;
            else if (ch >= 'A' && ch <= 'Z')
                v[1]++;
            else if (ch >= '0' && ch <= '9')
                v[2]++;
            else if (ch == ' ')
                v[3]++;
        }
        for (auto X : v)
        {
            cout << X << ' ';
        }
        cout << '\n';
        v.assign(4, 0);
    }

    return 0;
}