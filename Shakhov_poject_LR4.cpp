#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;
int day = 0, month = 0, year = 0, daysToAdd = 0;

void menu(){
    cout << "Task 1. ввести текущий день" << endl;
    cout << "Task 2. ввести текущий месяц" << endl;
    cout << "Task 3. ввести текущий год" << endl;
    cout << "Task 4. ввести количество дней для прибавления" << endl;
    cout << "Task 5. вычислить новую дату после прибавления дней" << endl;
    cout << "Task 6. найти разницу в днях между текущей датой и 1 января следующего года" << endl;


}
 
bool UserInput(string input){
    if (input.empty()) return false;

    try{
        int number = stoi(input);
        if (number < 0) return false;
    }

    catch (...)
    {return false;}
    return true;
}


void EnterNumber(int& a, string b){
    string str_input;
    cout << b << " = ";
    getline(cin, str_input);


    while(!UserInput(str_input)){
        cout << b << " = ";

        getline(cin, str_input);
    }

    a = stoi(str_input);
}



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


#include <ctime>
#include <iomanip>

void CalculateDate() {
    if (day == 0 || month == 0 || year == 0 || daysToAdd == 0) {
        cout << "Сначала введите дату и количество дней для прибавления.\n";
        return;
    }

    tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    time_t t = mktime(&date);
    t += daysToAdd * 24 * 60 * 60;

    tm *newDate = localtime(&t);
    cout << "Новая дата: " << put_time(newDate, "%d-%m-%Y") << endl;
}


<<<<<<< HEAD
void YearInput(){


}


void AddDay(){


}


void CalculateDate(){


}

void Difference() {
    if (day == 0 || month == 0 || year == 0) {
        cout << "Сначала введите текущую дату.\n";
        return;
    }




    tm current = {};
    current.tm_mday = day;
    current.tm_mon = month - 1;
    current.tm_year = year - 1900;

    tm jan1 = {};
    jan1.tm_mday = 1;
    jan1.tm_mon = 0;
    jan1.tm_year = year - 1900 + 1;

    time_t t1 = mktime(&current);
    time_t t2 = mktime(&jan1);

    double seconds = difftime(t2, t1);
    int days = static_cast<int>(seconds / (60 * 60 * 24));

    cout << "Разница в днях до 1 января следующего года: " << days << endl;
}



struct MenuItem{
    string title;
    function<void> action;

};









int main(){
    map<int, MenuItem> menu = {
        {1, {"ввести текущий день", DayInput}},
        {2, {"ввести текущий месяц", MonthInput}},
        {3, {"ввести текущий год", YearInput}},
        {4, {"ввести количество дней для прибавления", AddDay}},
        {5, {"вычислить новую дату после прибавления дней", CalculateDate}},
        {6, {"найти разницу в днях между текущей датой и 1 января следующего года", Difference}},
    };
    
    int choice = 0;


    while (true) {
        cout << "Меню:" << endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        EnterNumber(choice, "Input number of menu: ");
        if (choice == 0) {
            cout << "@ 2025 FirstName LastName" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод." << endl;
        }
        cout << endl;
    }
    return 0;

    

}
