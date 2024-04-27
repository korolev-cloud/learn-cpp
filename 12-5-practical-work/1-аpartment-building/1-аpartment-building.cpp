﻿#include <iostream>
#include <string>



int main()
{
    std::string surname[10];
    // массив списка фамилий
    for (int i = 0; i < 10; i++)
        // цикл по списку фамилий
    {
        std::cin >> surname[i];
    }
    int flatNumber;
    // номер квартиры
    for (int i = 0; i < 3; i++)
        // цикл запроса фамилий по номерам квартир
    {
        std::cin >> flatNumber;
        if (flatNumber > 0 && flatNumber < 10)
            std::cout << surname[flatNumber - 1] << std::endl;
        else
        {
            std::cout << "Incorrect flat number" << std::endl;
        }
    }
}

/*
Что нужно сделать
На вход программе поступают десять фамилий в формате строк. 
Это фамилии жильцов квартир с первой по десятую. Необходимо 
прочитать эти фамилии и записать в одномерный массив. Далее 
пользователь вводит три номера квартир. Необходимо вывести в 
консоль фамилию жильца, проживающего в этой квартире. Если 
пользователь введёт некорректный номер квартиры, необходимо 
сообщить ему об этом.

Пример

← SidorovA
← IvanovA
← PetrovA
← SidorovB
← IvanovB
← PetrovB
← SidorovC
← IvanovC
← PetrovC
← SidorovD
←10
→SidorovD
←1
→SidorovA
←5
→IvanovB

Что оценивается
Используется массив строк для хранения данных.
В коде не используются библиотеки, кроме <iostream> и <string>.
Программа проверяет доступность элемента по индексу и выдаёт корректный результат.
*/