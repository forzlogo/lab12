#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

void inputFromKeyboard(std::vector<int>& list) {
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return;
    }

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        list.push_back(x);
    }
}

void inputRandom(std::vector<int>& list) {
    std::srand(std::time(0));
    int n;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        int x = std::rand() % 101;
        list.push_back(x);
    }

    std::cout << "Сгенерированные числа: ";
    for (int i = 0; i < n; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

void inputFromFile(std::vector<int>& list, const std::string& filename) {
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Ошибка" << filename << std::endl;
        return;
    }

    int n;
    file >> n;

    if (n % 2 != 0) {
        std::cout << "Ошибка" << std::endl;
        file.close();
        return;
    }

    for (int i = 0; i < n; i++) {
        int x;
        file >> x;
        list.push_back(x);
    }
}

void printVector(const std::vector<int>& list) {
    int size = list.size();
    int half = size / 2;

    for (auto it = list.begin() + half; it != list.end(); ++it) {
        std::cout << *it << " ";
    }

    for (auto it = list.begin(); it != list.begin() + half; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL,"rus");
    std::vector<int> list;
    int choice;

    std::cout << "Выберите способ ввода данных:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайными числами\n";
    std::cout << "3 - из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputFromKeyboard(list);
        break;
    case 2:
        inputRandom(list);
        break;
    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        inputFromFile(list, filename);
        break;
    }
    default:
        std::cout << "Ошибка" << std::endl;
        return 1;
    }

    std::cout << "Результат:"<< std::endl;
    printVector(list);
}