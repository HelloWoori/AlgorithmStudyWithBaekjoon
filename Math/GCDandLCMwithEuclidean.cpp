/*
최대공약수와 최소공배수
https://www.acmicpc.net/problem/2609
*/
#include <iostream>

using namespace std;

int Euclidean(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    
    int num1(0), num2(0);
    cin >> num1 >> num2;
    
    //최대공약수 Greatest Common Divisor
    //최소공배수 Least Common Multiple
    
    int GCD(1), LCM(1);

    GCD = Euclidean(num1, num2);
    LCM = (num1 / GCD) * (num2 / GCD) * GCD;
    
    cout << GCD << '\n';
    cout << LCM << '\n';

    return 0;
}

int Euclidean(int a, int b)
{
    if (b == 0)
        return a;
    
    Euclidean(b, a % b);
}