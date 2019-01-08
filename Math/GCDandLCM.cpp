/*
최대공약수와 최소공배수
https://www.acmicpc.net/problem/2609
*/
#include <iostream>

using namespace std;

int min(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    
    int num1(0), num2(0);
    cin >> num1 >> num2;

    int minNum = min(num1, num2);
    
    //최대공약수 Greatest Common Divisor
    //최소공배수 Least Common Multiple
    
    int GCD(1), LCM(1);

    for (int i = 2; i <= minNum; ++i)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            GCD = i;
        }
    }

    LCM = (num1 / GCD) * (num2 / GCD) * GCD;
    
    cout << GCD << '\n';
    cout << LCM << '\n';

    return 0;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}