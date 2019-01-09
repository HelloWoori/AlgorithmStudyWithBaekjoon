/*
최소공배수
https://www.acmicpc.net/problem/1934
*/
#include <iostream>

using namespace std;

int GCD(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int num1(0), num2(0);
        cin >> num1 >> num2;

        int gcd = GCD(num1, num2);
        cout << num1 * num2 / gcd << '\n';
    }

    return 0;
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    
    return GCD(b, a % b);
}