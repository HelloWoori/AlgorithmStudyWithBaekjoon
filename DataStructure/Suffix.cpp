/*
접미사 배열
https://www.acmicpc.net/problem/11656
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertionSort(vector<string> &v)
{
	int idx, ridx;
	string remember;
	for(idx = 1; idx < v.size(); ++idx)
	{
		remember = v[idx];
		ridx = idx - 1;
		while(ridx >= 0 && v[ridx] > remember)
		{
			v[ridx + 1] = v[ridx];
			ridx--;
		}
		v[ridx + 1] = remember;
	}
}

int main()
{
	string str;
	vector<string> v;
	cin >> str;

	int size = str.size();
	v.resize(size);

	for(int i = 0; i < size; ++i)
	{
		string s;
		for(int j = i; j < size; ++j)
		{
			s += str[j];
		}
		v[i] = s;
	}

	insertionSort(v);
	
	for(auto X : v)
	{
		cout << X << '\n';
	}

	return 0;
}