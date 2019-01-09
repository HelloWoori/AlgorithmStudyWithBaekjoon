/*
2진수 8진수
https://www.acmicpc.net/problem/1373
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string binaryStr("");
    cin >> binaryStr;

    int n = binaryStr.size();
    if (n % 3 == 1)
    {
        cout << binaryStr[0];
    }
    else if (n % 3 == 2)
    {
        cout << (binaryStr[0] - '0') * 2 + binaryStr[1] - '0';
    }

    for (int i = n % 3; i < n; i += 3)
    {
        cout << (binaryStr[i] - '0') * 4 + (binaryStr[i + 1] - '0') * 2 + (binaryStr[i + 2] - '0');
    }
    cout << '\n';

    return 0;
}