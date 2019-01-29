/*
에디터
https://www.acmicpc.net/problem/1406
*/
#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::stack<char> left;
    std::stack<char> right;
    std::string str;
    int num = 0;

    std::cin >> str;
    for (auto s : str)
    {
        left.push(s);
    }

    std::cin >> num;
    while (num > 0)
    {
        //std::cout << num << '\n';
        char ch;
        std::cin >> ch;
        if (ch == 'L')
        {
            if (!left.empty())
            {
                char top = left.top();
                left.pop();
                right.push(top);
            }
        }
        else if (ch == 'D')
        {
            if (!right.empty())
            {
                char top = right.top();
                right.pop();
                left.push(top);
            }
        }
        else if (ch == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (ch == 'P')
        {
            char input;
            std::cin >> input;
            left.push(input);
        }
        num--;
    }

    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty())
    {
        std::cout << right.top();
        right.pop();
    }
}