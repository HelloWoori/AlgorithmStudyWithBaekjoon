/*
가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sizeOfSequence(0);
    cin >> sizeOfSequence;

    vector<int> sequence(sizeOfSequence + 1, 0);
    vector<int> dpIncrease(sizeOfSequence + 1, 1);
    vector<int> dpDecrease(sizeOfSequence + 1, 1);
    int max(1);

    //수열 입력
    for (int i = 1; i <= sizeOfSequence; ++i)
    {
        cin >> sequence[i];
    }

    //증가하는 부분
    for (int now = 2; now <= sizeOfSequence; ++now)
    {
        for (int prev = 1; prev < now; ++prev)
        {
            //가장 긴 증가하는 부분 수열
            if (sequence[prev] < sequence[now])
            {
                int temp = dpIncrease[prev] + 1;
                if (dpIncrease[now] < temp)
                    dpIncrease[now] = temp;
            }
        }
    }

    //감소하는 부분
    for (int now = sizeOfSequence - 1; now >= 1; --now)
    {
        for (int post = sizeOfSequence; post > now; --post)
        {
            if (sequence[post] < sequence[now])
            {
                int temp = dpDecrease[post] + 1;
                if (dpDecrease[now] < temp)
                    dpDecrease[now] = temp;
            }
        }
    }

    //계산
    for (int i = 1; i <= sizeOfSequence; ++i)
    {
        int tempMax = dpIncrease[i] + dpDecrease[i] - 1;
        //cout << "i: " << i << ", " << dpIncrease[i] << ' ' << dpDecrease[i] << '\n';
        if (max < tempMax)
            max = tempMax;
    }

    cout << max << '\n';
 
    return 0;
}
/*
반례
17
7 2 1 1 5 2 2 3 2 3 1 2 4 5 1 2 4
답: 6
*/