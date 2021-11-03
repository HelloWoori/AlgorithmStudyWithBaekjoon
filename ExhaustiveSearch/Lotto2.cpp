/*
로또
https://www.acmicpc.net/problem/6603
*/
#include <iostream>
#include <vector>

#define SIZE 6

using namespace std;

void calc(vector<int>& givenSet, vector<int>& mySet, int count);
int main()
{
    while (true)
    {        
        int numOfSet(0);
        cin >> numOfSet;
        if (numOfSet == 0) break;
        
        vector<int> givenSet(numOfSet, 0);
        vector<int> mySet;
        
        for (int i = 0; i < numOfSet; i++)
        {
             cin >> givenSet[i];
         }

        calc(givenSet, mySet, 0);
        cout << '\n';
    }

    return 0;
}

void calc(vector<int>& givenSet, vector<int>& mySet, int count)
{ 
    if (mySet.size() == SIZE)
    {
        for (int num : mySet)
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;    
    }

    if (givenSet.size() == count) return;
  
    mySet.push_back(givenSet[count]);
    calc(givenSet, mySet, count + 1);

    mySet.pop_back();
    calc(givenSet, mySet, count + 1);
}