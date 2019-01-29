/*
ROT13
https://www.acmicpc.net/problem/11655
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
   
    string str;
    char rot13;
    getline(cin, str);

    for (auto ch : str)
    {
        rot13 = ch;
        if (ch >= 'a' && ch <= 'z')
        {
            rot13 = (ch + 13) % ('z' + 1);
            if(rot13 < 'a')
                rot13 = rot13 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            rot13 = (ch + 13) % ('Z' + 1);
            if (rot13 < 'A')
                rot13 = rot13 + 'A';             
        }
        cout << rot13;
    }
    return 0;
}