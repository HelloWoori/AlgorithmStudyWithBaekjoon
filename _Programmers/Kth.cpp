/*
K번째 수
https://programmers.co.kr/learn/courses/30/lessons/42748
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(const auto& command : commands)
    {
        vector<int> temp;
        const int START = command[0] - 1;
        const int END = command[1] - 1;
        const int K = command[2] - 1;
        
        for(int i = START; i <= END; ++i)
        {
            temp.push_back(array[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[K]);        
    }
       
    return answer;
}