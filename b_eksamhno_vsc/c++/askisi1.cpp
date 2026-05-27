#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    int grade;

public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(int g) { grade = g; }

    string getName() { return name; }
    int getAge() { return age; }
    int getGrade() { return grade; }
};

class Course {
private:
    string title;
    string teacher;
    int weeklyHours;

public:
    void setTitle(string t) { title = t; }
    void setTeacher(string tch) { teacher = tch; }
    void setWeeklyHours(int h) { weeklyHours = h; }

    string getTitle() { return title; }
    string getTeacher() { return teacher; }
    int getWeeklyHours() { return weeklyHours; }
};

int main() {
    Student student;
    Course course;

    string studentName, courseTitle, teacher;
    int studentAge, studentGrade, weeklyHours;

    cout << "=== Πληροφορίες Μαθητή ===" << endl;
    cout << "Εισάγετε όνομα μαθητή: ";
    getline(cin, studentName);
    student.setName(studentName);

    cout << "Εισάγετε ηλικία: ";
    cin >> studentAge;
    student.setAge(studentAge);

    cout << "Εισάγετε τάξη: ";
    cin >> studentGrade;
    student.setGrade(studentGrade);

    cin.ignore();

    cout << "\n=== Πληροφορίες Μαθήματος ===" << endl;
    cout << "Εισάγετε όνομα μαθήματος: ";
    getline(cin, courseTitle);
    course.setTitle(courseTitle);

    cout << "Εισάγετε όνομα διδάσκοντα: ";
    getline(cin, teacher);
    course.setTeacher(teacher);

    cout << "Εισάγετε εβδομαδιαίες ώρες: ";
    cin >> weeklyHours;
    course.setWeeklyHours(weeklyHours);

    cout << "\n=== Δεδομένα που Καταχωρήθηκαν ===" << endl;
    cout << "Μαθητής: " << student.getName() << endl;
    cout << "Ηλικία: " << student.getAge() << endl;
    cout << "Τάξη: " << student.getGrade() << endl;

    cout << "\nΜάθημα: " << course.getTitle() << endl;
    cout << "Διδάσκων: " << course.getTeacher() << endl;
    cout << "Ώρες: " << course.getWeeklyHours() << endl;

    return 0;
}
