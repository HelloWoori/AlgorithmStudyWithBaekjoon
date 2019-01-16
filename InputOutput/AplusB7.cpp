/*
A+B - 7
https://www.acmicpc.net/problem/11021
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    for (int i = 1; i <= theNumOfTestCases; ++i)
    {
        int input1(0), input2(0);
        cin >> input1 >> input2;
        cout << "Case #" << i << ": " << input1 + input2 << '\n';
    }

    return 0;
}