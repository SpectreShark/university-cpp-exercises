#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string group;
    string last_name;
    string first_name;
    string middle_name;
    char gender{};
    int birth_year{};
    double physics_grade{};
    double math_grade{};
    double informatics_grade{};
    bool has_scholarship{};
};

void write_students_to_file(const string& filename, const int student_count) {
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        cout << "Введите данные для " << student_count << " студентов:\n";

        for (int index = 0; index < student_count; index++) {
            string group;
            string last_name;
            string first_name;
            string middle_name;
            char gender;
            int birth_year;
            double physics_grade;
            double math_grade;
            double informatics_grade;
            bool has_scholarship;

            cout << "Студент №" << index + 1 << endl;
            cout << "Группа: ";
            getline(cin, group);
            cout << "Фамилия: ";
            getline(cin, last_name);
            cout << "Имя: ";
            getline(cin, first_name);
            cout << "Отчество: ";
            getline(cin, middle_name);
            cout << "Пол (М/Ж): ";
            cin >> gender;
            cin.ignore();
            cout << "Год рождения: ";
            cin >> birth_year;
            cin.ignore();
            cout << "Оценка по физике: ";
            cin >> physics_grade;
            cin.ignore();
            cout << "Оценка по математике: ";
            cin >> math_grade;
            cin.ignore();
            cout << "Оценка по информатике: ";
            cin >> informatics_grade;
            cin.ignore();
            cout << "Есть стипендия (1 - да, 0 - нет): ";
            cin >> has_scholarship;
            cin.ignore();

            file << group << ' ' << last_name << ' ' << first_name << ' '
                 << middle_name << ' ' << gender << ' ' << birth_year << ' '
                 << physics_grade << ' ' << math_grade << ' '
                 << informatics_grade << ' ' << has_scholarship << '\n';
        }

        file.close();
        cout << "Данные успешно записаны в файл." << endl;
    }
}

void read_students_from_file(Student* students, const int student_count,
                             const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        for (int index = 0; index < student_count; index++) {
            file >> students[index].group >> students[index].last_name
                 >> students[index].first_name >> students[index].middle_name
                 >> students[index].gender >> students[index].birth_year
                 >> students[index].physics_grade >> students[index].math_grade
                 >> students[index].informatics_grade
                 >> students[index].has_scholarship;
        }

        file.close();
    }
}

void print_students(const Student* students, const int student_count,
                    const string& target_group, const double& minimum_grade) {
    cout << "Студенты группы " << target_group
         << " со средним баллом больше " << minimum_grade << endl;

    for (int index = 0; index < student_count; index++) {
        if (students[index].group == target_group) {
            const double average_grade =
                (students[index].physics_grade + students[index].math_grade +
                 students[index].informatics_grade) /
                3.0;

            if (average_grade > minimum_grade) {
                cout << "ФИО: " << students[index].last_name << ' '
                     << students[index].first_name << ' '
                     << students[index].middle_name;
                cout << ", Средний балл: " << average_grade << endl;
            }
        }
    }
}

int main() {
    string filename;
    cout << "Введите имя файла для работы: ";
    getline(cin, filename);

    cout << "Введите количество студентов для добавления: ";
    string input;
    getline(cin, input);
    const int student_count = stoi(input);
    write_students_to_file(filename, student_count);

    auto* students = new Student[student_count];
    read_students_from_file(students, student_count, filename);

    cout << "Введите минимальный средний балл: ";
    getline(cin, input);
    const double minimum_grade = stod(input);

    cout << "Введите название группы для поиска: ";
    string target_group;
    getline(cin, target_group);

    print_students(students, student_count, target_group, minimum_grade);
    delete[] students;

    return 0;
}
