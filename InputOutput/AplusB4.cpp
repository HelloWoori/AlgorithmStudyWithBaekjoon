/*
A+B - 4
https://www.acmicpc.net/problem/10951
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int input1(0), input2(0);
    while (cin >> input1 >> input2)
    {
        cout << input1 + input2 << '\n';
    }

    return 0;
}