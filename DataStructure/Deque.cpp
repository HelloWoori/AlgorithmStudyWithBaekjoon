/*
덱
https://www.acmicpc.net/problem/10866
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    vector<int> v;
    string str;
    int n = 0, X = 0;
    cin >> n;
   
    while (n-- > 0)
    {
        cin >> str;
        if (str == "push_front")
        {
            cin >> X;
            v.insert(v.begin(), X);
        }
        else if (str == "push_back")
        {
            cin >> X;
            v.push_back(X);
        }
        else if (str == "pop_front")
        {
            if (!v.empty())
            {
                cout << v.front() << '\n';
                v.erase(v.begin());
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (str == "pop_back")
        {
            if (!v.empty())
            {
                cout << v.back() << '\n';
                v.pop_back();
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (str == "size")
        {
            cout << v.size() << '\n';
        }
        else if (str == "empty")
        {
            if (v.empty())
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
            
        }
        else if (str == "front")
        {
            if (!v.empty())
            {
                cout << v.front() << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (str == "back")
        {
            if (!v.empty())
            {
                cout << v.back() << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
    }

    return 0;
}