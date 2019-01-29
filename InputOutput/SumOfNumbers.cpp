/*
숫자의 합
https://www.acmicpc.net/problem/11720
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfNumbers(0);
    cin >> theNumOfNumbers;

    string str("");
    cin >> str;

    int result(0);
    for(int i = 0; i < theNumOfNumbers; ++i)
    {
        result += (str[i] - '0');
    }

    cout << result << '\n';

    return 0;
}