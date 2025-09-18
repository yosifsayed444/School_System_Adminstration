#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
    int id;

    Person(string name, int age, int id)
    {
        this->name = name;
        this->age = age;
        this->id = id;
    }
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class Student : public Person
{
public:
    int grade;
    Student(string name, int age, int id, int grade) : Person(name, age, id)
    {
        this->grade = grade;
    }
    void display() override
    {
        Person::display();
        cout << "Grade: " << grade << endl;
    }
};

class Teacher : public Person
{
public:
    string sub;
    int salary;
    Teacher(string name, int age, int id, string sub, int salary) : Person(name, age, id)
    {
        this->sub = sub;
        this->salary = salary;
    }
    void display() override
    {
        Person::display();
        cout << "Subject: " << sub << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course
{
public:
    string name;
    string code;
    string instructor;
    vector<Student> students;
    vector<Teacher> teachers;

    Course(string name, string code, string instructor)
    {
        this->name = name;
        this->code = code;
        this->instructor = instructor;
    }

    void addStudent(Student student)
    {
        students.push_back(student);
    }
    void addTeacher(Teacher teacher)
    {
        teachers.push_back(teacher);
    }
    void display()
    {
        cout << "\nCourse Name: " << name << endl;
        cout << "Course Code: " << code << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Students: " << endl;
        for (auto &s : students)
            s.display();
        cout << "Teachers: " << endl;
        for (auto &t : teachers)
            t.display();
    }
};

class School
{
public:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;

    void addStudent(Student student)
    {
        students.push_back(student);
        cout<<"Student added successfully"<<endl;
    }

    void editStudent(int id, Student student)
    {
        bool found = false;
        for (auto &s : students)
        {
            if (s.id == id)
            {
                s = student;
                found = true;
                cout<<"Student edited successfully"<<endl;
                break;
            }
        }
        if (!found)
            cout << "Student not found" << endl;
    }

    void editTeacher(int id, Teacher teacher)
    {
        bool found = false;
        for (auto &t : teachers)
        {
            if (t.id == id)
            {
                t = teacher;
                found = true;
                cout<<"Teacher edited successfully"<<endl;
                break;
            }
        }
        if (!found)
            cout << "Teacher not found" << endl;
    }

    void addTeacher(Teacher teacher)
    {
        teachers.push_back(teacher);
        cout<<"Teacher added successfully"<<endl;
    }

    void addCourse(Course course)
    {
        courses.push_back(course);
        cout<<"Course added successfully"<<endl;
    }

    void getStudent(int id)
    {
        bool found = false;
        for (auto &s : students)
        {
            if (s.id == id)
            {
                s.display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Student not found" << endl;
    }

    void getTeacher(int id)
    {
        bool found = false;
        for (auto &t : teachers)
        {
            if (t.id == id)
            {
                t.display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Teacher not found" << endl;
    }
    void removeStudent(int id)
    {
        for (int i = 0; i < students.size();i++){
            if(students[i].id==id){
                students.erase(students.begin()+i);
                cout<<"Student removed successfully"<<endl;
                break;
            }else{
                cout<<"Student not found"<<endl;
            }
        }
    }
    void removeTeacher(int id)
    {
        for (int i = 0; i < teachers.size();i++){
            if(teachers[i].id==id){
                teachers.erase(teachers.begin()+i);
                cout<<"Teacher removed successfully"<<endl;
                break;
            }else{
                cout<<"Teacher not found"<<endl;
            }
        }
    }
        

    void ShowAll()
    {
        cout << "\n--- Students ---\n";
        for (auto &s : students)
            s.display();
        cout << "\n--- Teachers ---\n";
        for (auto &t : teachers)
            t.display();
        cout << "\n--- Courses ---\n";
        for (auto &c : courses)
            c.display();
    }
};
