/*
-2진수
https://www.acmicpc.net/problem/2089
- https://www.acmicpc.net/board/view/30006 (-2진수 팁)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);

    ll decimal;
    cin >> decimal;

    int n = decimal;

    if (n == 0)
    {
        cout << "0";
    }
    else
    {
        vector<int> minusBinary;
        while (n != 0)
        {
            if (n > 0) //양수인 경우
            {
                if (n % 2 == 0) //짝수
                {
                    n = n / -2;
                    minusBinary.push_back(0);
                }
                else            //홀수
                {
                    n = (n - 1) / -2;
                    minusBinary.push_back(1);
                }
            }
            else       //음수인 경우
            {
                if (n % 2 == 0) //짝수
                {
                    n = n / -2;
                    minusBinary.push_back(0);
                }
                else            //홀수
                {
                    n = (n - 1) / -2;
                    minusBinary.push_back(1);
                }
            }
        }


        for (auto it = minusBinary.rbegin(); it != minusBinary.rend(); ++it)
        {
            cout << *it;
        }
    }
    cout << '\n';
    
    return 0;
}