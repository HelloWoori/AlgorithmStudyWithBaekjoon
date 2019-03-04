/*
전화번호 목록
https://programmers.co.kr/learn/courses/30/lessons/42577
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solveProblem(const vector<string>& phone_book)
{
    for(size_t i = 0; i < phone_book.size(); ++i)
    {
        size_t strLen = phone_book[i].size();
        for(size_t j = i + 1; j < phone_book.size(); ++j)
        {
            if(strLen < phone_book[j].size())
            {
                if(phone_book[j].substr(0, strLen) == phone_book[i])
                    return false;
            }
        }        
    }    
    return true;  
}

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    answer = solveProblem(phone_book);
    
    return answer;
}