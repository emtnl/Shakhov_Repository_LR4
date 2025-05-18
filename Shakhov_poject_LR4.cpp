#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;

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



void DayInput(){


}


void MonthInput(){


}


void YearInput() {
    EnterNumber(year, "Введите текущий год");
}



void AddDay(){


}


void CalculateDate(){


}

void Difference(){

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
