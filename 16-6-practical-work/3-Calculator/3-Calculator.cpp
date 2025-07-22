#include<iostream>
#include <sstream>

int main(){
    std::string buffer;
    std::cout << "Input expression in format <number-1><action><number-2> ";
    std::cin >> buffer;
    double firtstNumber = 0.f;
    double secondNumber = 0.f;
    double result = 0.f;
    char operation;
    std::stringstream buffer_stream(buffer);
    buffer_stream >> firtstNumber >> operation >> secondNumber;
    if (operation == '+') result = firtstNumber + secondNumber;
    else if (operation == '-') result = firtstNumber - secondNumber;
    else if (operation == '*') result = firtstNumber * secondNumber;
    else if (operation == '/') result = firtstNumber / secondNumber;
    std::cout << "Solution: " << result;
    return 0;
}

/*
Что нужно сделать
Создайте небольшую программу для вычисления простых действий с числами. 
При запуске программа ожидает пользовательского ввода во временную переменную строку. 
После ввода строки она распарсивается на отдельные члены. 
Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). 
Оба числа — это значения с плавающей точкой, повышенной точности (double). 
Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.

Рекомендации
Чтобы разделить полученную строку на отдельные элементы — числа и оператор, 
воспользуйтесь строковым потоком. Для этого создайте пустую строку std::string buffer 
и дайте пользователю возможность при помощи std::cin ввести в неё команду. 
Затем оберните полученную строку так: std::stringstream buffer_stream(buffer); 
Это позволит вам  получить каждый из трёх компонентов команды: buffer_stream >> a >> operation >> b;



*/