/*
조합 0의 개수
https://www.acmicpc.net/problem/2004
*/
#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

struct Count
{
    ull two;
    ull five;

    Count() : two(0), five(0) {}
    Count(ull _two, ull _five) : two(_two), five(_five) {}

    Count operator- (Count other)
    {
        return Count(two - other.two, five - other.five);
    }

};

ull CountTwo(ull n);
ull CountFive(ull n);

int main()
{
    ios_base::sync_with_stdio(false);

    ull n(0), m(0);
    cin >> n >> m;

    //for debug
    //cout << n << "!의 2의 개수: " << CountTwo(n) << '\n';
    //cout << n << "!의 5의 개수: " << CountFive(n) << '\n';

    //cout << m << "!의 2의 개수: " << CountTwo(m) << '\n';
    //cout << m << "!의 5의 개수: " << CountFive(m) << '\n';

    //cout << n - m << "!의 2의 개수: " << CountTwo(n - m) << '\n';
    //cout << n - m << "!의 5의 개수: " << CountFive(n - m) << '\n';

    Count countN(CountTwo(n), CountFive(n));
    Count countM(CountTwo(m), CountFive(m));
    Count countNminusM(CountTwo(n - m), CountFive(n - m));

    Count temp1 = countN - countM;
    Count temp2 = temp1 - countNminusM;

    if (temp2.two >= temp2.five)
        cout << temp2.five << '\n';
    else
        cout << temp2.two << '\n';

    return 0;
}

ull CountTwo(ull n)
{
    ull x = 1;
    ull result = 0;

    while (pow(2, x) <= n)
    {
        result += static_cast<ull>(n / pow(2, x));
        x++;
    }
    return result;
}

ull CountFive(ull n)
{
    ull x = 1;
    ull result = 0;

    while (pow(5, x) <= n)
    {
        result += static_cast<ull>(n / pow(5, x));
        x++;
    }
    return result;
}