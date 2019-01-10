/*
8진수 2진수
https://www.acmicpc.net/problem/1212
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string eight[] = { "000", "001", "010", "011", "100", "101", "110", "111"};

    string str("");
    cin >> str;

    bool start = true;

    if (str.length() == 1 && str[0] - '0' == 0)
    {
        cout << "0";
    }

    for (int i = 0; i < str.length(); ++i)
    {
        int n = str[i] - '0';
        if (start == true && n < 4)
        {
            if (n == 0)
                continue;
            else if (n == 1)
                cout << "1";
            else if (n == 2)
                cout << "10";
            else if (n == 3)
                cout << "11";

            start = false;
        }
        else
        {
            cout << eight[n];
            start = false;
        }
    }
    cout << '\n';

    return 0;
}
/*
2
답: 10

21
답: 10001

27
답: 10111

222
답: 10010010
*/