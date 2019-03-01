/*
모의고사
https://programmers.co.kr/learn/courses/30/lessons/42840
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solveProblemSupozaOne(const vector<int>& answers);
int solveProblemSupozaTwo(const vector<int>& answers);
int solveProblemSupozaThree(const vector<int>& answers);  
    
vector<int> solution(vector<int> answers) {
    map<int, vector<int>> correct;
    
    int max = solveProblemSupozaOne(answers);
    correct[max].push_back(1);
    
    int temp = solveProblemSupozaTwo(answers);
    if(max < temp) max = temp;
    correct[temp].push_back(2);
    
    temp = solveProblemSupozaThree(answers);
    if(max < temp) max = temp;
    correct[temp].push_back(3);
    
    return correct[max];
}

int solveProblemSupozaOne(const vector<int>& answers)
{
    int cnt = 0;
    for(size_t idx = 0; idx < answers.size(); ++idx)
    {
        if(answers[idx] == idx % 5 + 1) cnt++;
    }
    return cnt;
}

int solveProblemSupozaTwo(const vector<int>& answers)
{
    int cnt = 0;
    for(size_t idx = 0; idx < answers.size(); ++idx)
    {
        int val = 0;
        int mod = idx % 8;
        if(idx % 2 == 0)
        {
            if(answers[idx] == 2) cnt++;
        }
        else
        {
            if(mod == 1)      val = 1;
            else if(mod == 3) val = 3;
            else if(mod == 5) val = 4;
            else if(mod == 7) val = 5;
            
            if(answers[idx] == val) cnt++;
        }
    }
    return cnt;
}

int solveProblemSupozaThree(const vector<int>& answers)
{
    int cnt = 0;
    for(size_t idx = 0; idx < answers.size(); ++idx)
    {
        int val = 0;
        int mod = idx % 10;
        if(mod == 0 || mod == 1) val = 3;
        else if(mod == 2 || mod == 3) val = 1;
        else if(mod == 4 || mod == 5) val = 2;
        else if(mod == 6 || mod == 7) val = 4;
        else if(mod == 8 || mod == 9) val = 5;
        
        if(answers[idx] == val) cnt++;
    }
    return cnt;
}