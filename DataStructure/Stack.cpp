/*
스택
https://www.acmicpc.net/problem/10828
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
   
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    vector<int> stack;

    while (theNumOfTestCases-- > 0)
    {
        string cmd("");
        cin >> cmd;

        if (cmd == "push")
        {
            int n(0);
            cin >> n;

            stack.push_back(n);
        }
        else if (cmd == "pop")
        {
            if (stack.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << stack.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (stack.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (cmd == "top")
        {
            if (stack.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << stack.back() << '\n';
            }
        }
    }

    return 0;
}