/*
리모콘
https://www.acmicpc.net/problem/1107
https://www.acmicpc.net/board/view/27251 (왜 채널개수를 1,000,000 개로 늘려야 하나요?)
*/
#include <cstdio>

using namespace std;

int abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

int possibleButton(const int* brokenButtons, int moveChannel)
{
    int len(0);
    if (moveChannel == 0)
    {
        if (brokenButtons[0])
            return 0;
        else
            return 1;
    }
    else
    {
        while (moveChannel > 0)
        {
            if (brokenButtons[moveChannel % 10])
            {
                return 0;
            }

            len++;
            moveChannel /= 10;
        }
        return len;
    }
}

int main()
{ 
    const int CURRENT = 100;
    int brokenButtons[10] = { 0, }; //0: 고장나지 않음, 1: 고장남
    int wantChannel(0), theNumOfBrokenButtons(0);
    scanf("%d %d", &wantChannel, &theNumOfBrokenButtons);
    
    if (theNumOfBrokenButtons > 0)
    {
        while (theNumOfBrokenButtons-- > 0)
        {
            int broken(0);
            scanf("%d", &broken);
            brokenButtons[broken] = 1;
        }
    }

    int result = abs(wantChannel - CURRENT);
    for (int i = 0; i <= 1000000; ++i)
    {
        int moveChannel = i;
        
        int len = possibleButton(brokenButtons, moveChannel);
        if (len > 0)
        {
            int diff = abs(moveChannel - wantChannel);

            if (result > len + diff)
                result = len + diff;
        }
    }

    printf("%d\n", result);

    return 0;
}