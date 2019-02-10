/*
로또
https://www.acmicpc.net/problem/6603
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{ 
    const int PICKNUM = 6;

    while (true)
    {
        int theNumOfNumbers(0);
        scanf("%d", &theNumOfNumbers);

        if (theNumOfNumbers == 0) 
            break;

        vector<int> numbers(theNumOfNumbers);
        vector<int> pickNumbers(theNumOfNumbers, 1); //조합을 위한 벡터
        vector<vector<int>> results;

        for (int i = 0; i < theNumOfNumbers; ++i)
        {
            int input(0);
            scanf("%d", &input);
            numbers[i] = input;
        }

        for (int i = 0; i < theNumOfNumbers - PICKNUM; ++i)
        {
            pickNumbers[i] = 0;
        }

        do
        {
            vector<int> temp;
            for (int i = 0; i < theNumOfNumbers; ++i)
            {
                if (pickNumbers[i] == 1)
                    temp.push_back(numbers[i]);
            }
            results.push_back(temp);

        } while (next_permutation(pickNumbers.begin(), pickNumbers.end()));

        sort(results.begin(), results.end());
        for (const auto& result : results)
        {
            for (const auto& num : result)
            {
                printf("%d ", num);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}