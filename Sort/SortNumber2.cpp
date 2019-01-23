/*
수 정렬하기 2
https://www.acmicpc.net/problem/2751
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int num(0);
    cin >> num;

    vector<int> number;
    number.reserve(num);

    while (num--)
    {
        int input(0);
        cin >> input;
        number.push_back(input);
    }
    
    sort(number.begin(), number.end());

    for (const auto n : number)
    {
        cout << n << '\n';
    }

    return 0;
}