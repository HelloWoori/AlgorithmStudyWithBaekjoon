/*
모든 순열
https://www.acmicpc.net/problem/10974
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{ 
    int num(0);
    scanf("%d", &num);
    
    vector<int> v(num);

    for (int i = 1; i <= num; ++i)
    {
        v[i - 1] = i;
    }

    do
    {
        for (const auto& element : v)
        {
            printf("%d ", element);
        }
        printf("\n");

    } while (next_permutation(v.begin(), v.end()));

    return 0;
}