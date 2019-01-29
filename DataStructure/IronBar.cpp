/*
쇠막대기
https://www.acmicpc.net/problem/10799
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    string str;
    vector<char> v;
    char prev = ' ';
    char ch;
    int cnt = 0;

    cin >> str;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        ch = *it;
        if (it != str.begin())
            prev = *(it - 1);

        if (ch == '(')
        {
            v.push_back(ch);
        }
        else if(ch == ')')
        {
            if (v.empty() == false)
            {
                if (prev == '(')
                {
                    v.pop_back();
                    cnt += v.size();
                }
                else
                {
                    v.pop_back();
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}