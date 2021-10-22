/*
암호 만들기
https://www.acmicpc.net/problem/1759
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calc(int idx, vector<char> &password, vector<char> &alphaList, int goalCount);
bool check(vector<char> &password);
int main()
{
    int goalCount(0), alphaCount(0);
    cin >> goalCount >> alphaCount;

    vector<char> alphaList;
    vector<char> password;
    for (int i = 0; i < alphaCount; i++)
    {
        char alpha;
        cin >> alpha;
        alphaList.push_back(alpha);
    }

    sort(alphaList.begin(), alphaList.end());

    calc(0, password, alphaList, goalCount);
    
    return 0;
}

void calc(int idx, vector<char> &password, vector<char> &alphaList, int goalCount)
{
    if (idx > alphaList.size())
    {
        return;
    }

    if (password.size() == goalCount)
    {
        if (check(password))
        {
            for (auto alpha : password)
            {
                cout << alpha;
            }
            cout << '\n';
          
            return;
        }
      
        return;
    }
  
    password.push_back(alphaList[idx]);
    calc(idx + 1, password, alphaList, goalCount);

    password.pop_back();
    calc(idx + 1, password, alphaList, goalCount);
}

bool check(vector<char> &password)
{
    int moCount(0), jaCount(0);
    for (auto alpha : password)
    {
        if (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u')
        {
            moCount++;
        }
        else
        {
            jaCount++;
        }
    }

    if (moCount >= 1 && jaCount >= 2)
    {
        return true;
    }

    return false;
}