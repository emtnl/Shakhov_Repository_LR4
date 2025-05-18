#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <ctime>

using namespace std;

// Глобальные переменные
int day = 0;
int month = 0;
int year = 0;
int daysToAdd = 0;

// Функция проверки ввода
bool UserInput(const string& input) {
    if (input.empty()) return false;

    try {
        int num = stoi(input);
        if (num <= 0) return false;
    } catch (...) {
        return false;
    }
    return true;
}

// Ввод числа с проверкой
void EnterNumber(int& a, const string& prompt) {
    string input;
    cout << prompt << " = ";
    getline(cin, input);

    while (!UserInput(input)) {
        cout << "Некорректный ввод. Попробуйте снова." << endl;
        cout << prompt << " = ";
        getline(cin, input);
    }

    a = stoi(input);
}

// Функции пунктов меню
void DayInput() {
    EnterNumber(day, "Введите текущий день");
}

void MonthInput() {
    EnterNumber(month, "Введите текущий месяц");
}

void YearInput() {
    EnterNumber(year, "Введите текущий год");
}

void AddDay() {
    EnterNumber(daysToAdd, "Введите количество дней для прибавления");
}

void CalculateDate() {
    if (day == 0 || month == 0 || year == 0 || daysToAdd == 0) {
        cout << "Сначала введите все данные: день, месяц, год и количество дней!" << endl;
        return;
    }

    tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;  // Месяцы в C++ начинаются с 0 (январь — 0)
    date.tm_year = year - 1900;

    time_t t = mktime(&date);
    t += daysToAdd * 24 * 60 * 60; // Прибавляем дни в секундах

    tm* newDate = localtime(&t);
    cout << "Новая дата: "
         << newDate->tm_mday << "."
         << newDate->tm_mon + 1 << "."
         << newDate->tm_year + 1900 << endl;
}

void DifferenceToNewYear() {
    if (day == 0 || month == 0 || year == 0) {
        cout << "Сначала введите день, месяц и год!" << endl;
        return;
    }

    tm current = {};
    current.tm_mday = day;
    current.tm_mon = month - 1;
    current.tm_year = year - 1900;

    tm nextYear = {};
    nextYear.tm_mday = 1;
    nextYear.tm_mon = 0;            // Январь
    nextYear.tm_year = year - 1900 + 1;

    time_t tCurrent = mktime(&current);
    time_t tNextYear = mktime(&nextYear);

    double seconds = difftime(tNextYear, tCurrent);
    int days = static_cast<int>(seconds / (60 * 60 * 24));

    cout << "До 1 января " << year + 1 << ": " << days << " дней" << endl;
}

// Структура меню
struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"ввести текущий день", DayInput}},
        {2, {"ввести текущий месяц", MonthInput}},
        {3, {"ввести текущий год", YearInput}},
        {4, {"ввести количество дней для прибавления", AddDay}},
        {5, {"вычислить новую дату после прибавления дней", CalculateDate}},
        {6, {"найти разницу в днях до 1 января следующего года", DifferenceToNewYear}}
    };

    int choice = 0;

    while (true) {
        cout << "\nМеню:" << endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        EnterNumber(choice, "Выберите пункт");

        if (choice == 0) {
            cout << "@ 2025 Shakhov" << endl;
            break;
        }

        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Неверный пункт меню." << endl;
        }
        cout << endl;
    }

    return 0;
}