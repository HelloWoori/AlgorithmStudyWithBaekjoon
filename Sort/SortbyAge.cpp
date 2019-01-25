/*
나이순 정렬
https://www.acmicpc.net/problem/10814
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Person
{
    int id;
    int age;
    string name;
    
    Person() : id(0), age(0), name("") {}
    Person(int _id, int _age, string _name)
        : id(_id)
        , age(_age)
        , name(_name)
    {}

    bool operator < (const Person& other) const
    {
        if (age == other.age)
            return id < other.id;
        else
            return age < other.age;
    }
};

int main()
{
    int theNumOfPeople(0);
    cin >> theNumOfPeople;

    vector<Person> people;
    people.reserve(theNumOfPeople);

    for(int i = 0; i < theNumOfPeople; ++i)
    {
        int age(0);
        string name("");
        cin >> age >> name;

        people.push_back(Person(i, age, name));
    }

    sort(people.begin(), people.end());

    for (const auto& person : people)
    {
        cout << person.age << " " << person.name << '\n';
    }

    return 0;
}