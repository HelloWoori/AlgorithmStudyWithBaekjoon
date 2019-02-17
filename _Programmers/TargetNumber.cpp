/*
타겟 넘버
- https://programmers.co.kr/learn/courses/30/lessons/43165
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = static_cast<int>(numbers.size());

    vector<int> permutation(size, 1);

    for(int numOfZero = 0; numOfZero <= size; ++numOfZero)
    {
        for(int i = 0; i < numOfZero; ++i)
        {
            permutation[i] = 0;
        }

        do
        {
            int temp = 0;
            for(int i = 0; i < size; ++i)
            {
                if(permutation[i] == 1)
                {
                    temp += numbers[i];
                }
                else
                {
                    temp -= numbers[i];
                }
            }

            if(temp == target)
                answer++;

        }while(next_permutation(permutation.begin(), permutation.end()));
    }

    return answer;
}