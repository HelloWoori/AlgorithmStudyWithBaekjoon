/*
완주하지 못한 선수
https://programmers.co.kr/learn/courses/30/lessons/42576
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(const auto& p : participant)
    {
        if(m.count(p) == 0)
            m[p] = 1;
        else
            m[p]++;
    }
    
    for(const auto& c : completion)
    {
        m[c]--;
    }
    
    for(const auto& element : m)
    {
        if(element.second != 0)
            answer = element.first;
    }
    return answer;
}