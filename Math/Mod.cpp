/*
나머지
https://www.acmicpc.net/problem/10430
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a(0), b(0), c(0);
    cin >> a >> b >> c;
    
    cout << (a + b) % c << '\n';
    cout << (a % c + b % c) % c << '\n';
    cout << (a * b) % c << '\n';
    cout << (a % c * b % c) % c << '\n';

    return 0;
}