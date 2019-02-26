/*
순열의 순서
https://www.acmicpc.net/problem/1722
*/
#include <cstdio>
#include <vector>

using namespace std;
typedef unsigned long long ll;

ll dp[21] = {1};

ll factorial(int n);
void cmd1(int theNumOfNumbers);
void cmd2(int theNumOfNumbers);

int main()
{
    factorial(20);

    int theNumOfNumbers(0), cmd(0);
    scanf("%d %d", &theNumOfNumbers, &cmd);

    /* k번째 순열 출력 */
    if (cmd == 1)
    {
        cmd1(theNumOfNumbers);
    }
    /* 몇 번째 순열인지 출력 */
    else if (cmd == 2)
    {
        cmd2(theNumOfNumbers);
    }

    return 0;
}

ll factorial(int n)
{
    if (dp[n] != 0)
        return dp[n];

    if (n == 1)
    {
        dp[1] = 1;
        return dp[1];
    }

    ll temp = n * factorial(n - 1);
    dp[n] = temp;
    return dp[n];
}

void cmd1(int theNumOfNumbers)
{
    ll k(0);
    scanf("%lld", &k);

    vector<int> permutation(theNumOfNumbers);
    vector<bool> check(theNumOfNumbers + 1, false);

    for (int i = 0; i < theNumOfNumbers; ++i)
    {
        for (int j = 1; j <= theNumOfNumbers; ++j)
        {
            if (check[j]) continue;

            ll temp = dp[theNumOfNumbers - i - 1];
            if (temp < k)
            {
                k -= temp;
            }
            else
            {
                permutation[i] = j;
                check[j] = true;
                break;
            }
        }
    }
    for (const auto& element : permutation)
    {
        printf("%d ", element);
    }
    printf("\n");
}

void cmd2(int theNumOfNumbers)
{
    vector<int> permutation(theNumOfNumbers, 0);
    vector<bool> check(theNumOfNumbers + 1, false);

    //순열 입력
    for (int i = 0; i < theNumOfNumbers; ++i)
    {
        scanf("%d", &permutation[i]);
    }

    //몇 번째 순열인지 계산
    ll result(0);
    for (int idx = 0; idx < theNumOfNumbers; ++idx)
    {
        int now = permutation[idx];
        for (int i = 1; i < now; ++i)
        {
            if (false == check[i])
            {
                result += dp[theNumOfNumbers - idx - 1];
            }
        }
        check[now] = true;
    }
    printf("%lld\n", result + 1); //0번째 부터 센 기준이기 때문에 1 더함
}
/*
5 
1 118
결과: 5 4 2 3 1

20
1 2432902008176640000
결과: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

20
2 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 1 2
결과: 2432902008176639999
*/