/*
프린터
https://programmers.co.kr/learn/courses/30/lessons/42587
*/
#include <string>
#include <vector>
#include <map>
#include <deque>

using namespace std;

bool isHighPriority(const deque<int>& q, map<int, int>& m)
{
    int now = q[0];
    int nowPriority = m[now];
    for(size_t i = 1; i < q.size(); ++i)
    {
        int next = q[i];
        int nextPriority = m[next];
        if(nowPriority < nextPriority) //더 큰 우선순위가 있다면
            return true;
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
   
    map<int, int> m; //인쇄번호, 우선순위
    deque<int> q;    
    vector<int> result;
    
    for(size_t i = 0; i < priorities.size(); ++i)
    {
        q.push_back(i);
        m[i] = priorities[i];
    }
    
    while(q.empty() == false)
    {
        int front = q.front();
        if(isHighPriority(q, m))
        {
            q.pop_front();
            q.push_back(front);
        }
        else
        {
            result.push_back(front);
            q.pop_front();
        }
    }
    
    for(size_t i = 0; i < result.size(); ++i)
    {
        if(result[i] == location)
        {
            answer = i + 1;
            break;
        }
    }
 
    return answer;
}