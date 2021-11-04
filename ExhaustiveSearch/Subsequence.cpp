/*
부분수열의 합
https://www.acmicpc.net/problem/1182
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int>& sequence, vector<int>& temp, int targetSum, int count);
int main()
{
    int size(0), targetSum(0);
    cin >> size >> targetSum;

    vector<int> sequence(size);
    vector<int> subsequence;
    for (int i = 0; i < size; i++)
    {
        cin >> sequence[i];
    }

    cout << calc(sequence, subsequence, targetSum, 0) << '\n';

    return 0;
}

int calc(vector<int>& sequence, vector<int>& subsequence, int targetSum, int count)
{
    if (count == sequence.size())
    {
        int sum(0);
        for (int num : subsequence)
        {
            sum += num;
        }
        
        if (subsequence.size() != 0 && sum == targetSum)
        {
            return 1;
        }

        return 0;
    }

    int ret(0);
    subsequence.push_back(sequence[count]);
    ret += calc(sequence, subsequence, targetSum, count + 1);

    subsequence.pop_back();
    ret += calc(sequence, subsequence, targetSum, count + 1);

    return ret;
}