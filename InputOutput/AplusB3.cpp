/*
A+B - 3
https://www.acmicpc.net/problem/10950
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int input1(0), input2(0);
        cin >> input1 >> input2;
        cout << input1 + input2 << '\n';
    }

    return 0;
}