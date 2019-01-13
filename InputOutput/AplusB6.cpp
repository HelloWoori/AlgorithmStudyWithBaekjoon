/*
A+B - 6
https://www.acmicpc.net/problem/10953
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        string str("");
        cin >> str;

        int num1 = str[0] - '0';
        int num2 = str[2] - '0';
        cout << num1 + num2 << '\n';
    }

    return 0;
}