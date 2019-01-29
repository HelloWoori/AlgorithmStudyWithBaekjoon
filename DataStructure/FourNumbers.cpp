/*
네 수
https://www.acmicpc.net/problem/10824
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned long a[2] = {0, 0};
	string str1, str2;
	for(int i = 0;  i < 2; ++i)
	{
		cin >> str1 >> str2;
		a[i] = stoul(str1.append(str2));
	}
	cout << a[0] + a[1] << '\n';

	return 0;
}