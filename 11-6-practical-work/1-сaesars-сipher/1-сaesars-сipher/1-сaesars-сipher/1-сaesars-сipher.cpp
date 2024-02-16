#include <iostream>
#include <string>
#include <cctype>

std::string encrypt_caesar(std::string text, int shift)//объявляем функцию
{
    std::string encrypt;  //объявление переменной для зашифрованного текста
    for (int i = 0; i < text.length(); i++)
        //перебор всех символов в исходной строке
    {
        char symbol = text[i];//объявляем переменную для символа
        if (std::islower(symbol))//если символ является маленькой буквой
        {
            encrypt += (symbol - 'a' + shift) % 26 + 'a';//шифруем символ
        }
        else if (std::isupper(symbol))//если символ является большой буквой
        {
            encrypt += (symbol - 'A' + shift) % 26 + 'A';//шифруем символ
        }
        else {//иначе (символ не буква)
            encrypt += symbol; //добавляем символ без шифровки
        }
    }
    return encrypt;//вернуть зашифрованную строку
}

int main()
{
    std::string text;//объявляем переменную для текста
    int shift;//объявляем переменную для смещения
    std::cout << "Text_string: "; std::getline(std::cin, text);//запрашиваем строку
    std::cout << "Code_number: "; std::cin >> shift;//запрашиваем код
    std::cout << encrypt_caesar(text, shift);//шифруем строку
}