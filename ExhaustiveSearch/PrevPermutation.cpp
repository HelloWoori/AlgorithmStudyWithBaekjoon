/*
이전 순열
https://www.acmicpc.net/problem/10973
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSame(vector<int>& v1, vector<int>& v2)
{
    if (v1.size() == v2.size())
    {
        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool mySmaller(int a, int b)
{
    return (a > b);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int size(0);
    cin >> size;

    vector<int> v(size);
    vector<int> copy(size);

    for (int i = 0; i < size; ++i)
    {
        cin >> v[i];

        copy[i] = v[i];
    }

    prev_permutation(v.begin(), v.end());
    sort(copy.begin(), copy.end(), mySmaller);

    if (isSame(v, copy))
    {
        cout << "-1" << '\n';
    }
    else
    {
        for (const auto& element : v)
        {
            cout << element << " ";
        }
        cout << '\n';
    }

    return 0;
}