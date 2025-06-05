#include <fstream>
#include <iostream>
#include <string>

// https://dotnettutorials.net/lesson/serialization-in-cpp/

using namespace std;

class Student 
{
    public:
    string name;
    int rollno;
    string branch;
    Student ()
    {
    } 
    Student (string n, int r, string b) 
    {
        name = n;
        rollno = r;
        branch = b;
    } 
    friend ofstream & operator << (ofstream & ofs, Student s);
    friend ifstream & operator >> (ifstream & ifs, Student & s);
};
ofstream & operator << (ofstream & ofs, Student s)
{
    ofs << s.name << endl;
    ofs << s.rollno << endl;
    ofs << s.branch << endl;
    return ofs;
}
ifstream & operator >> (ifstream & ifs, Student & s)
{
    ifs >> s.name >> s.rollno >> s.branch;
    return ifs;
}
int main() 
{
    Student s1("James", 28, "IT");
    ofstream ofs("Student.txt", ios::trunc);
    ofs << s1;
    ofs.close();
    Student s2;
    ifstream ifs("Student.txt");
    ifs >> s2;
    cout << s2.name << " " << s2.rollno << " " << s2.branch << endl;
    ifs.close();
}
