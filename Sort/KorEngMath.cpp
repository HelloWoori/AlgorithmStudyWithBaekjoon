/*
국영수
https://www.acmicpc.net/problem/10825
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    int kor;
    int eng;
    int math;

    Student() : name(""), kor(0), eng(0), math(0) {}
    Student(string _name, int _kor, int _eng, int _math)
        : name(_name)
        , kor(_kor)
        , eng(_eng)
        , math(_math)
    {
    }

};

bool isScoreAllSame(const Student& s1, const Student& s2)
{
    return (s1.kor == s2.kor &&
            s1.eng == s2.eng &&
            s1.math == s2.math);
}

bool mySort(const Student& s1, const Student& s2)
{
    if (isScoreAllSame(s1, s2))
        return s1.name < s2.name;

    else if (s1.kor == s2.kor && s1.eng == s2.eng)
        return s1.math > s2.math;
    
    else if ((s1.kor != s2.kor))
        return s1.kor > s2.kor;

    else if (s1.kor == s2.kor)
        return s1.eng < s2.eng;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfStudents(0);
    cin >> theNumOfStudents;
    
    vector<Student> students;
    students.reserve(theNumOfStudents);

    string name("");
    int kor(0), eng(0), math(0);

    while (theNumOfStudents-- > 0)
    {
        cin >> name >> kor >> eng >> math;
        students.push_back(Student(name, kor, eng, math));
    }

    sort(students.begin(), students.end(), mySort);

    for (const auto& student : students)
    {
        cout << student.name << '\n';
    }

    return 0;
}