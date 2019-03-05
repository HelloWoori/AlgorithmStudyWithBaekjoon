/*
탑
https://programmers.co.kr/learn/courses/30/lessons/42588
*/
#include <vector>

using namespace std;

int solveProblem(const vector<int>& heights, int startIdx)
{
    for(int i = startIdx - 1; i >= 0; --i)
    {
        if(heights[i] > heights[startIdx])
            return i + 1;
    }
    
    return 0;
}

vector<int> solution(vector<int> heights) 
{
    vector<int> answer;
    
    for(size_t i = 0; i < heights.size(); ++i)
    {
        int result = solveProblem(heights, i);
        answer.push_back(result);
    }
    
    return answer;
}