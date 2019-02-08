/*
차이를 최대로
https://www.acmicpc.net/problem/10819
https://www.acmicpc.net/board/view/27262 (반례)
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

int main()
{ 
    int num(0);
    scanf("%d", &num);

    vector<int> v(num);
    for (int i = 0; i < num; ++i)
    {
        int input(0);
        scanf("%d", &input);
        v[i] = input;
    }

    int max(0);

    for (int n = 1; n < num; ++n)
    {
        int temp = v[0];
        v[0] = v[n];
        v[n] = temp;

        do
        {
            int tempMax(0);
            for (int i = 0; i <= num - 2; ++i)
            {
                int calc = ans(v[i] - v[i + 1]);
                tempMax += calc;
            }
            if (tempMax >= max)
            {
                max = tempMax;
            }

            //for debug
            //for (const auto& element : v)
            //{
            //    printf("%d ", element);
            //}
            //printf("\n");
            //printf("tempMax: %d\n", tempMax);
        } while (next_permutation(v.begin(), v.end()));
    }

    printf("%d\n", max);

    return 0;
}