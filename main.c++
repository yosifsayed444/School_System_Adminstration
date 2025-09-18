#include <bits/stdc++.h>
#include "classes.h"
using namespace std;

signed main()
{
    School school;
    int choice;
    string name, subject, code, instructor, course_name;
    int id;
    int age;
    int grade;
    int salary;
    do
    {
        cout << "\n Menu"
             << "\n 1. Add Student"
             << "\n 2. Edit Student"
             << "\n 3. Get Student"
             << "\n 4. Remove Student"
             << "\n 5. Add Teacher"
             << "\n 6. Edit Teacher"
             << "\n 7. Get Teacher"
             << "\n 8. Remove Teacher"
             << "\n 9. Add Course"
             << "\n 10. Show All"
             << "\n 0. Exit"
             << "\n Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter name, id, age and grade: ";
            cin >> name >> id >> age >> grade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.addStudent(Student(name, age, id, grade));
            break;

        case 2:
        {
            int searchId;
            cout << "Enter id of student to edit: ";
            cin >> searchId;
            cout << "Enter new name, id, age and grade: ";
            cin >> name >> id >> age >> grade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.editStudent(searchId, Student(name, age, id, grade));
            break;
        }

        case 3:
            cout << "Enter id: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.getStudent(id);
            break;

        case 4:
            cout << "Enter id: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.removeStudent(id);
            break;

        case 5:
            cout << "Enter name, id, age, subject and salary: ";
            cin >> name >> id >> age >> subject >> salary;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.addTeacher(Teacher(name, age, id, subject, salary));
            
            break;

        case 6:
        {
            int searchId;
            cout << "Enter id of teacher to edit: ";
            cin >> searchId;
            cout << "Enter new name, id, age, subject and salary: ";
            cin >> name >> id >> age >> subject >> salary;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.editTeacher(searchId, Teacher(name, age, id, subject, salary));
            break;
        }

        case 7:
            cout << "Enter id: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.getTeacher(id);
            break;

        case 8:
            cout << "Enter id: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            school.removeTeacher(id);
            break;

        case 9:
        {
            cout << "Enter course name: ";
            cin >> course_name;
            cout << "Enter course code: ";
            cin >> code;
            cout << "Enter course instructor: ";
            cin >> instructor;

            cout << "Enter number of students: ";
            int n;
            cin >> n;
            Course course(course_name, code, instructor);

            for (int i = 0; i < n; i++)
            {
                cout << "Enter name, id, age and grade: ";
                cin >> name >> id >> age >> grade;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                course.addStudent(Student(name, age, id, grade));
            }

            cout << "Enter number of teachers: ";
            int m;
            cin >> m;

            for (int i = 0; i < m; i++)
            {
                cout << "Enter name, id, age, subject and salary: ";
                cin >> name >> id >> age >> subject >> salary;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                course.addTeacher(Teacher(name, age, id, subject, salary));
            }

            school.addCourse(course);
            break;
        }

        case 10:
            school.ShowAll();
            break;

        case 0:
            cout << "Exited Successfully\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 0);
}
