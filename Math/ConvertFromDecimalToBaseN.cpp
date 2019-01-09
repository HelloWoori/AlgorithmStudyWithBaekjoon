/*
진법 변환 2
https://www.acmicpc.net/problem/11005
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    map<int, char> alphabet;
    vector<int> remainder;

    for (int i = 10; i <= 35; ++i)
    {
        alphabet[i] = 'A' - 10 + i;
    }

    int N(0), B(0); //N: 10진법 수, B: B진법
    cin >> N >> B;

    int quotient = N;

    while (quotient != 0)
    {
        remainder.push_back(quotient % B);
        quotient = quotient / B;
    }

    for (auto it = remainder.rbegin(); it != remainder.rend(); ++it)
    {
        int val = *it;
        auto findAlphabet = alphabet.find(val);

        if (findAlphabet == alphabet.end())
            cout << val;
        else
            cout << alphabet[val];
    }
    cout << '\n';

    return 0;
}