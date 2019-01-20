/*
팩토리얼 0의 개수
https://www.acmicpc.net/problem/1676
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int input(0);
    cin >> input;

    int result(0);
    if (input >= 125)
    {
        result += static_cast<int>(input / 125);
    }
    if (input >= 25)
    {
        result += static_cast<int>(input / 25);
    }
    if (input >= 5)
    {
        result += static_cast<int>(input / 5);
    }

    cout << result << '\n';

    return 0;
}