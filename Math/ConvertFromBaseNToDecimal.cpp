/*
진법 변환
https://www.acmicpc.net/problem/2745
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string str("");
    int B(0);
    cin >> str >> B;

    int idx(0);
    int sum(0);
    for (auto it = str.rbegin(); it != str.rend(); ++it)
    {
        char ch = *it;
        if (ch >= 'A' && ch <= 'Z')
        {
            sum += pow(B, idx) * (ch - 'A' + 10);
        }
        else if ('0' <= ch && ch <= '9')
        {
            sum += pow(B, idx) * (ch - '0');
        }

        ++idx;
    }

    cout << sum << '\n';

    return 0;
}