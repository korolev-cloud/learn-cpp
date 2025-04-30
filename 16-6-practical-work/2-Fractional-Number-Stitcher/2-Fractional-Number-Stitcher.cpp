#include <iostream>
#include <string> 

int main(){
    std::string numberToDot;
    std::string numberAfterDot;
    std::cout << "Input whole part: ";
    std::cin >> numberToDot;
    // псевдоним size_t
    std::string::size_type sz;
    double wholePart = std::stod (numberToDot, &sz);
    std::cout << "Input fractional part: ";
    std::cin >> numberAfterDot;
    numberToDot.append("." + numberAfterDot);
    wholePart = std::stod (numberToDot, &sz);
    std::cout << "Number is: " << wholePart;
    return 0;
}

/*
Что нужно сделать
Напишите небольшую программу. Из целой и дробной частей числа, 
которые в отдельности вводит пользователь, составьте новое число 
с плавающей точкой (типа double) и выведите это число обратно в 
консоль для проверки. Целая часть — это часть числа, которая 
находится до точки (запятой), дробная — после.

Рекомендации
Вам потребуется функция StringToDouble — std::stod. 
Она принимает на вход строку, содержащую в себе число.
*/