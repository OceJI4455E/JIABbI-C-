#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

struct People {
    string surname;
    int numberOfpoints;
    int occupiedPlace;
public:
    void print() {
        cout << "Фамилия: " << surname << "\tКоличество очков: " << numberOfpoints << "\tЗанятое место: " << occupiedPlace << endl;
    }
};

const int HASH_TABLE_SIZE = 15;

class HashTable {
private:
    vector<People> table;
    int hash1(int key) {
        return key % HASH_TABLE_SIZE;
    }
    int hash2(int key) {
        return (key / HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
    }
public:
    HashTable() {
        table.resize(HASH_TABLE_SIZE);
    }
    void insert(People people) {
        int index = hash1(people.numberOfpoints);
        int step = hash2(people.occupiedPlace);
        while (!table[index].surname.empty()) {
            index = (index + step) % HASH_TABLE_SIZE;
        }
        table[index] = people;
    }
    People* search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (!table[index].surname.empty() && table[index].numberOfpoints != key) {
            index = (index + step) % HASH_TABLE_SIZE;
        }
        if (table[index].surname.empty()) {
            return nullptr;
        }
        else {
            return &table[index];
        }
    }
    void print() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            if (table[i].surname != "")
                cout << "[" << i << "]\t->\t" << "Фамилия: " << table[i].surname << "\tКоличество очков: " << table[i].numberOfpoints << "\tЗанятое место: " << table[i].occupiedPlace << endl;
            else
                cout << "[" << i << "]\t->\t" << "Нет данных\n";
        }
    }
};

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    const int n = 5;
    People people[n];
    for (int i = 0; i < n; i++) {
        system("cls");
        cout << "Ввод данных о человеке No " << i + 1 << endl;
        cout << "Введите фамилию: ";
        cin >> people[i].surname;
        people[i].numberOfpoints = rand() % 200;
        people[i].occupiedPlace = rand() % (1 - 9);

        //для ручного ввода
        /*cout << "Ввод данных о человеке No " << i + 1 << endl;
        cout << "Введите фамилию: ";
        cin >> people[i].surname;
        cout << "Введите Количество очков: ";
        cin >> people[i].numberOfpoints;
        cout << "Введите Занятое место: ";
        cin >> people[i].occupiedPlace;*/
    }

    HashTable table;
    for (int i = 0; i < n; i++) {
        table.insert(people[i]);
    }

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        people[i].print();
    }

    cout << "Хеш-таблица:" << endl;
    table.print();
    system("pause");

    char key;
    do
    {
        system("cls");
        table.print();
        cout << "-------------------------------------------------\n";
        cout << "Введите ключ для поиска (Вес): ";
        int searchObject;
        cin >> searchObject;

        People* result = table.search(searchObject);
        if (result == nullptr) {
            cout << "Элемент не найден" << endl;
        }
        else {
            cout << "Найденный элемент: ";
            result->print();
        }
        cout << "-------------------------------------------------\n";
        cout << "Продолжить поиск? (да - любая клавиша, нет - 1): ";
        cin >> key;
    } while (key != '1');


    return 0;
}