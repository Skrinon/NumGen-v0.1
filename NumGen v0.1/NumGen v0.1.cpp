#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath> // Для использования функции ceil

int main() {
    std::locale::global(std::locale("")); // Установка локали для корректной работы с символами
    int mode;
    int count = 0; // Инициализируем количество чисел значением 0
    double interval;
    int fileType;
    std::string filename;

    // Запрашиваем режим работы
    std::cout << "Выберите режим работы:\n1 - Генератор с интервалом\n2 - Генератор с выборкой\nВыбор: ";
    std::cin >> mode;

    double start = 0; // Начальное значение для выборки
    double end = 0;   // Конечное значение для выборки
    double step = 0;  // Шаг изменения числа

    if (mode == 1) {
        // Запрашиваем интервал
        std::cout << "С каким интервалом? ";
        std::cin >> interval;
        // Запрашиваем количество чисел
        std::cout << "Сколько чисел генерируем? ";
        std::cin >> count;
        // Обеспечиваем, чтобы первое число не было равно нулю
        if (interval <= 0) {
            std::cerr << "Интервал должен быть больше нуля." << std::endl;
            return 1;
        }
    }
    else {
        // Настройка генератора с выборкой
        std::cout << "Введите начальное число: ";
        std::cin >> start;
        std::cout << "Введите конечное число: ";
        std::cin >> end;
        std::cout << "Введите шаг изменения числа: ";
        std::cin >> step;
        if (step <= 0) {
            std::cerr << "Шаг должен быть больше нуля." << std::endl;
            return 1;
        }
        if (end < start) {
            std::cerr << "Конечное число должно быть больше начального." << std::endl;
            return 1;
        }
        count = static_cast<int>(std::ceil((end - start) / step)) + 1; // Вычисляем количество чисел
    }

    // Запрашиваем тип файла
    std::cout << "В какой файл сохранить? \n1 - .csv\n2 - .txt\nВыбор: ";
    std::cin >> fileType;

    // Устанавливаем имя файла в зависимости от выбора
    if (fileType == 1) {
        filename = "output.csv";
    }
    else {
        filename = "output.txt";
    }

    // Открываем файл для записи
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return 1;
    }

    // Генерация и запись чисел
    if (mode == 1) {
        // Интервальный режим
        double value = interval; // Начинаем с первого интервала, чтобы избежать 0
        for (int i = 0; i < count; i++) {
            file << std::fixed << std::setprecision(2) << value;
            if (i < count - 1) file << " "; // Используем пробел как разделитель
            value += interval;
        }
    }
    else {
        // Режим с выборкой
        double value = start;
        while (value <= end) {
            file << std::fixed << std::setprecision(2) << value;
            if (value + step <= end) file << " "; // Используем пробел как разделитель
            value += step;
        }
    }

    // Закрываем файл
    file.close();

    std::cout << "Данные сохранены в файл " << filename << std::endl;

    return 0;
}
