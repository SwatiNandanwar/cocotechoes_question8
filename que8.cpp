#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Subject {
    string name;
    int totalMarks;
    int marksScored;
};

struct Student {
    string name;
    vector<Subject> subjects;
    int totalMarks;
};

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Subject generateRandomSubject(const string& name) {
    Subject subject;
    subject.name = name;
    subject.totalMarks = getRandomInt(70, 100);
    subject.marksScored = getRandomInt(0, subject.totalMarks);
    return subject;
}

Student generateRandomStudent(int studentId) {
    Student student{"Student" + to_string(studentId), {}, 0};

    vector<string> subjectNames = {"English", "Hindi", "Math1", "Math2", "Science"};

    for (const auto& subjectName : subjectNames) {
        Subject subject = generateRandomSubject(subjectName);
        student.subjects.push_back(subject);
        student.totalMarks += subject.marksScored;
    }

    
    student.totalMarks /= student.subjects.size();

    return student;
}



bool compareStudents(const Student& a, const Student& b) {
    return a.totalMarks > b.totalMarks;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<Student> students;
    for (int i = 1; i <= 20; ++i) {
        students.push_back(generateRandomStudent(i));
    }

    sort(students.begin(), students.end(), compareStudents);

    cout << "Top Five Students:\n";
    for (int i = 0; i < 5; ++i) {
        cout << students[i].name << " (";
        for (const auto& subject : students[i].subjects) {
            cout << subject.name << ", " << subject.totalMarks << ", " << subject.marksScored << " | ";
        }
        cout << ") Total Marks: " << students[i].totalMarks << "\n";
    }

    return 0;
}
