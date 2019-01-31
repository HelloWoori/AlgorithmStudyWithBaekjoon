/*
집합
https://www.acmicpc.net/problem/11723
*/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int bit(0);

    int theNumOfCmd(0);
    cin >> theNumOfCmd;

    string cmd("");
    int x(0);

    while (theNumOfCmd-- > 0)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> x;
            x--;
            bit |= (1 << x);
        }
        else if (cmd == "remove")
        {
            cin >> x;
            x--;
            bit &= ~(1 << x);
        }
        else if (cmd == "check")
        {
            cin >> x;
            x--;
            int num = bit & (1 << x);
            if (num)
                printf("%d\n", 1);
            else
                printf("%d\n", 0);
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            x--;
            bit ^= (1 << x);
        }
        else if (cmd == "all")
        {
            bit = (1 << 20) - 1;
        }
        else if (cmd == "empty")
        {
            bit = 0;
        }
    }

    return 0;
}