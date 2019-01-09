/*
GCD의 합
https://www.acmicpc.net/problem/9613
- https://www.acmicpc.net/board/view/28922 (도움을 받은 글)
*/
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;
    
    while (theNumOfTestCases-- > 0)
    {
        int theNumOfNumbers(0);
        cin >> theNumOfNumbers;

        vector<int> numbers;
        numbers.reserve(theNumOfNumbers);

        while (theNumOfNumbers-- > 0)
        {
            int num(0);
            cin >> num;
            numbers.push_back(num);
        }

        unsigned long long sum(0); //모든 쌍의 GCD의 합
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                int gcd = GCD(numbers[i], numbers[j]);
                sum += gcd;

                //for debug
                //cout << numbers[i] << ", " << numbers[j] << " gcd = " << gcd << '\n';
             }
        }

        cout << sum << '\n';
    }

    return 0;
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}