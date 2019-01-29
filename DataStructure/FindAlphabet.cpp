/*
알파벳 찾기
https://www.acmicpc.net/problem/10809
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    //처음 등장하는 위치를 출력하는 프로그램
    vector<int> v(26, -1);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        int idx = str[i] - 'a';
        if (v[idx] == -1)
            v[idx] = i;
        else
            continue;
    }

    for (auto X : v)
    {
        cout << X << ' ';
    }
    cout << '\n';

    return 0;
}