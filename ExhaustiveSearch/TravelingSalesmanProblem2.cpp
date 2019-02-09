/*
외판원 순회 2
https://www.acmicpc.net/problem/10971
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void calcMinCost(const vector<vector<int>>& road, 
                 const vector<int>& cities, 
                       int& minCost)
{
    int tempMinCost(0);
    for (auto it = cities.begin(); it != cities.end() - 1; ++it)
    {
        int city = *it;
        int nextCity = *(it + 1);

        if (road[city][nextCity] == 0)
            return;
        else
            tempMinCost += road[city][nextCity];
    }

    //다시 출발점으로 돌아가는게 가능한지 여부 체크 (불가능하면 즉, 0이면 리턴)
    int backCost = road[*(cities.end() - 1)][*(cities.begin())];
    
    if (backCost == 0)
        return;

    tempMinCost += backCost;

    if (tempMinCost < minCost)
    {
        minCost = tempMinCost;
    }
}

int main()
{ 
    int theNumOfCities(0);
    scanf("%d", &theNumOfCities);

    vector<vector<int>> road(theNumOfCities, vector<int>(theNumOfCities, 0));
    vector<int> cities(theNumOfCities);

    for (int h = 0; h < theNumOfCities; ++h)
    {
        for (int w = 0; w < theNumOfCities; ++w)
        {
            scanf("%d", &road[h][w]);
        }
    }

    for (int i = 0; i < theNumOfCities; ++i)
    {
        cities[i] = i;
    }

    //비용 구하기
    int minCost = numeric_limits<int>::max();
    for (int i = 1; i < theNumOfCities; ++i)
    {
        do
        {
            calcMinCost(road, cities, minCost);
        } while (next_permutation(cities.begin(), cities.end()));

        int temp = cities[0];
        cities[0] = cities[i];
        cities[i] = temp;
    }
   
    printf("%d\n", minCost);

    return 0;
}
/*
4
0 5 1 99
99 0 5 1
1 99 0 5
5 1 99 0
답:  20

4
0 0 10 10
10 0 3 10
10 10 0 3
3 10 10 0
답: 33
*/