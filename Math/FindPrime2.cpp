/*
소수 구하기
https://www.acmicpc.net/problem/1929
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int start(0), end(0);
    cin >> start >> end;

    vector<bool> isPrime(end + 1, true); //모두 소수라고 가정하고 지워나가기 시작
    
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2;  i * i <= end; ++i)
    {
        for (int j = i + i; j <= end; j += i)
        {
            isPrime[j] = false;
        }
    }
    
    for (int i = start; i <= end; ++i)
    {
        if (isPrime[i])
            cout << i << '\n';
    }

    return 0;
}