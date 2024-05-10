#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath> // ��� ������������� ������� ceil

int main() {
    std::locale::global(std::locale("")); // ��������� ������ ��� ���������� ������ � ���������
    int mode;
    int count = 0; // �������������� ���������� ����� ��������� 0
    double interval;
    int fileType;
    std::string filename;

    // ����������� ����� ������
    std::cout << "�������� ����� ������:\n1 - ��������� � ����������\n2 - ��������� � ��������\n�����: ";
    std::cin >> mode;

    double start = 0; // ��������� �������� ��� �������
    double end = 0;   // �������� �������� ��� �������
    double step = 0;  // ��� ��������� �����

    if (mode == 1) {
        // ����������� ��������
        std::cout << "� ����� ����������? ";
        std::cin >> interval;
        // ����������� ���������� �����
        std::cout << "������� ����� ����������? ";
        std::cin >> count;
        // ������������, ����� ������ ����� �� ���� ����� ����
        if (interval <= 0) {
            std::cerr << "�������� ������ ���� ������ ����." << std::endl;
            return 1;
        }
    }
    else {
        // ��������� ���������� � ��������
        std::cout << "������� ��������� �����: ";
        std::cin >> start;
        std::cout << "������� �������� �����: ";
        std::cin >> end;
        std::cout << "������� ��� ��������� �����: ";
        std::cin >> step;
        if (step <= 0) {
            std::cerr << "��� ������ ���� ������ ����." << std::endl;
            return 1;
        }
        if (end < start) {
            std::cerr << "�������� ����� ������ ���� ������ ����������." << std::endl;
            return 1;
        }
        count = static_cast<int>(std::ceil((end - start) / step)) + 1; // ��������� ���������� �����
    }

    // ����������� ��� �����
    std::cout << "� ����� ���� ���������? \n1 - .csv\n2 - .txt\n�����: ";
    std::cin >> fileType;

    // ������������� ��� ����� � ����������� �� ������
    if (fileType == 1) {
        filename = "output.csv";
    }
    else {
        filename = "output.txt";
    }

    // ��������� ���� ��� ������
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
        return 1;
    }

    // ��������� � ������ �����
    if (mode == 1) {
        // ������������ �����
        double value = interval; // �������� � ������� ���������, ����� �������� 0
        for (int i = 0; i < count; i++) {
            file << std::fixed << std::setprecision(2) << value;
            if (i < count - 1) file << " "; // ���������� ������ ��� �����������
            value += interval;
        }
    }
    else {
        // ����� � ��������
        double value = start;
        while (value <= end) {
            file << std::fixed << std::setprecision(2) << value;
            if (value + step <= end) file << " "; // ���������� ������ ��� �����������
            value += step;
        }
    }

    // ��������� ����
    file.close();

    std::cout << "������ ��������� � ���� " << filename << std::endl;

    return 0;
}
