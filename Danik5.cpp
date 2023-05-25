#include <iostream>
#include <vector>
#include <ctime>

const int HASH_TABLE_SIZE = 15;
const int MIN_RANGE = 38000;
const int MAX_RANGE = 58000;

int hashFunction(int key);
void printArray(std::vector<int> arr);
void printHashTable(std::vector<int> hashTable);
void searchInHashTable(std::vector<int> hashTable);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n = 9;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_RANGE - MIN_RANGE) + MIN_RANGE;
    }

    std::vector<int> hashTable(HASH_TABLE_SIZE, -1);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= MIN_RANGE && arr[i] <= MAX_RANGE) {
            int index = hashFunction(arr[i]);
            while (hashTable[index] != -1) {
                index = (index + 1) % HASH_TABLE_SIZE;
            }
            hashTable[index] = arr[i];
        }
    }

    printArray(arr);
    std::cout << "----------------------------------------------------------------------------------------------------------\n";
    printHashTable(hashTable);
    system("pause");

    char key;
    do
    {
        system("cls");
        printHashTable(hashTable);
        std::cout << "----------------------------------------------\n";
        searchInHashTable(hashTable);
        std::cout << "----------------------------------------------\n";
        std::cout << "Хотите продолжить? (нет - 0, да - любая клавиша)\n";

        std::cin >> key;
    } while (key != '0');


    return 0;
}

int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}
void printArray(std::vector<int> arr)
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
void printHashTable(std::vector<int> hashTable)
{
    std::cout << "Хеш-таблица:\n";
    for (int i = 0; i < hashTable.size(); i++) {
        std::cout << "[" << i + 1 << "]\t->\t" << hashTable[i] << '\n';
    }
    std::cout << '\n';
}
void searchInHashTable(std::vector<int> hashTable)
{
    int searchKey;
    std::cout << "Введите ключ для поиска: ";
    std::cin >> searchKey;

    int index = hashFunction(searchKey);
    while (hashTable[index] != searchKey && hashTable[index] != -1) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    if (hashTable[index] == searchKey) {
        std::cout << "Элемент НАЙДЕН в хеш-таблице\n";
    }
    else {
        std::cout << "Элемент НЕ НАЙДЕН в хеш-таблице\n";
    }
}