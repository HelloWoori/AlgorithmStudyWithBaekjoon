/*
최소공배수
https://www.acmicpc.net/problem/1934
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
        int num1(0), num2(0);
        cin >> num1 >> num2;
        int tempNum1 = num1;
        int tempNum2 = num2;

        while (tempNum2 != 0)
        {
            int temp = tempNum1;
            tempNum1 = tempNum2;
            tempNum2 = temp % tempNum2;
        }
        int gcd = tempNum1;

        cout << num1 * num2 / gcd << '\n';
    }

    return 0;
}