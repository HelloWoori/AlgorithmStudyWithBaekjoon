/*
소수 찾기
https://www.acmicpc.net/problem/1978
*/
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i=2; i*i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    int cnt(0);
    while (theNumOfTestCases-- > 0)
    {
        int input(0);
        cin >> input;

        if (isPrime(input))
            cnt++;
    }
    cout << cnt << '\n';

    return 0;
}