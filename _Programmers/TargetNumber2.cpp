/*
타겟 넘버
- https://programmers.co.kr/learn/courses/30/lessons/43165
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(const vector<int>& numbers, const int target, int& answer, int sum, int idx)
{
    if(idx == numbers.size())
    {
        if(sum == target)
            answer++;
        return;
    }

    DFS(numbers, target, answer, sum + numbers[idx], idx + 1);
    DFS(numbers, target, answer, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    int idx = 0;
    DFS(numbers, target, answer, -numbers[idx], idx + 1);
    DFS(numbers, target, answer,  numbers[idx], idx + 1);

    return answer;
}