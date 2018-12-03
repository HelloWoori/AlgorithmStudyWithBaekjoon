/*
텀 프로젝트
https://www.acmicpc.net/problem/9466
*/
#include <iostream>
#include <vector>
using namespace std;

int dfs(
    const int x, 
    const vector<int>& graph,
    vector<int>& checkStep,
    vector<int>& checkCount,
    int& step,
    int& count)
{
    //이미 방문했다면
    if (checkCount[x] != 0)
    {
        //같은 사이클 내라면 -> 사이클 내 학생 수 리턴
        if (checkStep[x] == step)
            return count - checkCount[x];

        //다른 사이클 이라면 -> 팀 못만듦 ㅎㅎ..
        return 0;
    }

    //방문하지 않았다면
    checkStep[x] = step;
    checkCount[x] = count;
    
    count++;

    int next = graph[x];
    return dfs(next, graph, checkStep, checkCount, step, count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int theNumOfTestCases;
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int num;
        cin >> num;
        
        vector<int> graph(num + 1);         //0은 사용하지 않음
        vector<int> checkStep(num + 1, 0);  //같은 사이클 내인지 확인할 용도
        vector<int> checkCount(num + 1, 0); //사이클 내 학생 수를 계산하기 위함
        
        for (int i = 1; i <= num; ++i)
        {
            int input;
            cin >> input;
            graph[i] = input;
        }
    
        int theNumOfStudents = 0;           //팀을 만든 학생 수
        int count = 1;
        for (int i = 1; i <= num; ++i)
        {
            if (checkCount[i] == 0)
            {
                //아직 확인하지 않았다면, 탐색 시작
                theNumOfStudents += dfs(i, graph, checkStep, checkCount, i, count);
            }
        }
    
        //for debug
        /*
        cout << "checkStep = [";
        for (int i = 1; i <= num; ++i)
        {
            cout << checkStep[i] << " ";
        }
        cout << "]\n";

        cout << "checkCount = [";
        for (int i = 1; i <= num; ++i)
        {
            cout << checkCount[i] << " ";
        }
        cout << "]\n";
        */


        //result
        //cout << "result: ";
        cout << num - theNumOfStudents << '\n';
    
    }

    return 0;
}