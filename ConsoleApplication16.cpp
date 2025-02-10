#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    char name[50];
    char gender;
    int group;
    int num_in_group;
    int grades[8];
};

void show_data()
{
    ifstream database("TextFile1.txt");
    if (!database.is_open()) {
        cout << "File opening error" << endl;
    }
    else {
        string data;
        while (getline(database, data)) {
            cout << data << '\n';
        }
    }
    database.close();
}
void create_new_student(struct Student students[], int& size) {
    cout << "Добавим нового студента " << endl;
    cin.ignore();
    cin.getline(students[size].name, 50, '\n');
    cout << "name passed" << endl;
    cout << "Введите пол студента (Ж/М): "<< endl;
    cin >> students[size].gender;
    cout << "gender passed" << endl;
    cin >> students[size].group;
    cout << "group passed" << endl;
    cin >> students[size].num_in_group;
    cout << "num in group passed" << endl;
    for (int i = 0; i < 8; i++) {
        cin >> students[size].grades[i];
        cout << endl;
    }
    cout << "all done" << endl;
    ofstream database("TextFile1.txt", ios::app);  // Открываем файл для добавления
    if (database.is_open()) {
        database << students[size].id << "\n"
            << students[size].name << "\n"
            << students[size].gender << "\n"
            << students[size].group << "\n"
            << students[size].num_in_group << "\n";
        for (int i = 0; i < 8; i++) {
            database << students[size].grades[i] << " ";
        }
        database << "\n";
        database.close();
        cout << "Данные успешно записаны в файл.\n";
    }
    else {
        cout << "Ошибка открытия файла для записи.\n";
    }

    int i = size;
    size++;
}

void print_all(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Имя: " << students[i].name << endl;
        cout << "Пол: " << students[i].gender << endl;
        cout << "Группа: " << students[i].group << endl;
        cout << "Номер в группе: " << students[i].num_in_group << endl;
        cout << "Оценки: ";
        for (int j = 0; j < 8; j++) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl << "-----------------------------" << endl;
    }
}

void info_from_file(Student students[], int size) {
    ifstream database("TextFile1.txt");
    if (!database.is_open()) {
        cout << "File opening error" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            database >> students[i].id;
            database >> students[i].name;
            database >> students[i].gender;
            database >> students[i].group;
            database >> students[i].num_in_group;
            for (int j = 0; j < 8; j++) {
                database >> students[i].grades[j];
            }
        }
    }
    database.close();
}
void print_students_in_group(Student students[], int size) {
    int group_num;
    cout << "Введите номер группы" << endl;
    cin >> group_num;
    cout << "Информация о студентах группы " << group_num << ":\n";
    for (int i = 0; i < size; i++) {
        if (students[i].group == group_num) {
            cout << "ID: " << students[i].id << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Группа: " << students[i].group << endl;
            cout << "Номер в группе: " << students[i].num_in_group << endl;
            cout << "Оценки: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << "-----------------------------" << endl;
        }
    }
}
void students_with_certain_num_in_group(Student students[], int size) {
    int num_in_group;
    cout << "Введите номер в группе" << endl;
    cin >> num_in_group;
    cout << "Информация о студентах с этим номером в группе" << num_in_group << ":\n";
    for (int i = 0; i < size; i++) {
        if (students[i].num_in_group == num_in_group) {
            cout << "ID: " << students[i].id << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Группа: " << students[i].group << endl;
            cout << "Номер в группе: " << students[i].num_in_group << endl;
            cout << "Оценки: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << "-----------------------------" << endl;
        }
    }
}
void male_and_female_num(Student students[], int size) {
    int male_count = 0, female_count = 0;
    cout << "Информация о поле студентов: " << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].gender == 'М') {
            male_count++;
        }
        else if (students[i].gender == 'Ж') {
            female_count++;
        }
    }
    cout << "Женщин: " << female_count << endl;
    cout << "Мужчин: " << male_count << endl;
}
void students_without_scholarship(Student students[], int size) {
    cout << "Вывод данных о студентах, которые не получают стипендию " << endl;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            if (students[i].grades[j] == 3) {
                counter++;
            }
        }
        if (counter >= 1) {
            cout << "ID: " << students[i].id << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Группа: " << students[i].group << endl;
            cout << "Номер в группе: " << students[i].num_in_group << endl;
            cout << "Оценки: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << "-----------------------------" << endl;
        }
    }
}
void students_good_and_excellent(Student students[], int size) {
    cout << "Вывод данных о студентах, учатся только на «хорошо» и «отлично»" << endl;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            if (students[i].grades[j] == 4 or students[i].grades[j] == 5) {
                counter++;
            }
        }
        if (counter == 8) {
            cout << "ID: " << students[i].id << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Группа: " << students[i].group << endl;
            cout << "Номер в группе: " << students[i].num_in_group << endl;
            cout << "Оценки: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << "-----------------------------" << endl;
        }
    }
}
void students_excellent(Student students[], int size) {
    cout << "Вывод данных о студентах, учатся только на «отлично»" << endl;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            if (students[i].grades[j] == 5) {
                counter++;
            }
        }
        if (counter == 8) {
            cout << "ID: " << students[i].id << endl;
            cout << "Имя: " << students[i].name << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Группа: " << students[i].group << endl;
            cout << "Номер в группе: " << students[i].num_in_group << endl;
            cout << "Оценки: ";
            for (int j = 0; j < 8; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl << "-----------------------------" << endl;
        }
    }
}
void display_menu() {
    cout << "Выберите действие:" << endl;
    cout << "1. Создание новой записи о студенте." << endl;
    cout << "2. Внесение изменений в уже имеющуюся запись." << endl;
    cout << "3. Вывод всех данных о студентах." << endl;
    cout << "4. Вывод информации обо всех студентах группы N" << endl;
    cout << "5. Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." << endl;
    cout << "6. Вывод количества студентов мужского и женского пола." << endl;
    cout << "7. Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»;" << endl;
    cout << "8. Вывод данных о студентах, имеющих номер в списке – k." << endl;
}
int num_of_id() {
    int size = 0, res = 0;
    ifstream database("TextFile1.txt");
    if (!database.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return -1;
    }
    string data;
    while (getline(database, data)) {
        if (!data.empty()) {
            size++;
        }
    }
    database.close();
    res = size / 6;
    return res;
}
int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct Student students[1000];
    int identificator, size = num_of_id();
    if (size != 0) {
        info_from_file(students, size);
    }
    else {
        create_new_student(students, size);
    }
    while (true) {
        display_menu();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> identificator;
        system("cls");
        switch (identificator) {
        case 1:
            create_new_student(students, size);
            break;
        case 2:
            //find_student_info(students, size);
            break;
        case 3:
            print_all(students, size);
            break;
        case 4:
            print_students_in_group(students, size);
            break;
        case 5:
            students_with_certain_num_in_group(students, size);
            break;
        case 6:
            male_and_female_num(students, size);
            break;
        case 7:
            students_without_scholarship(students, size);
            students_good_and_excellent(students, size);
            students_excellent(students, size);
            break;
        case 8:
            students_with_certain_num_in_group(students, size);
            break;
        case 9:
            cout << "Выход!" << endl;
            return 0;

        default:
            cout << "Некорректный номер задания." << endl;
            break;
        }
        cout << "Задание выполнено. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}
