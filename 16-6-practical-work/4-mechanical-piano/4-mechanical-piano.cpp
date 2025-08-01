﻿#include <iostream>
#include <string>

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int notes{ 0b0000'0000 };

int main()
{
    std::string accord;
    std::cout << "Input accord: \n";
    std::cin >> accord;
    for (int i = 0; i < accord.length(); i++) {
        notes = notes | (1 << int(accord[i]) - '0' - 1);
    }
    if (notes & DO) std::cout << "DO\n";
    if (notes & RE) std::cout << "RE\n";
    if (notes & MI) std::cout << "MI\n";
    if (notes & FA) std::cout << "FA\n";
    if (notes & SOL) std::cout << "SOL\n";
    if (notes & LA) std::cout << "LA\n";
    if (notes & SI) std::cout << "SI\n";
}

/*

Создайте упрощённую модель механического пианино. 
У этого пианино семь клавиш, которые соответствуют семи нотам. 
Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum. 
В начале программы пользователь вводит «аккорд», то есть строку с набором цифр от 1 до 7, 
например: 1234 или 63.

Далее нужно скомпоновать цифры «аккорда» в одну битовую маску, 
которую будет содержать переменная типа int, где каждый бит соответствует определённой ноте. 
В этом случае, даже если при вводе будет введена одна и та же цифра (нота), 
она превратится только в один конкретный бит (нельзя нажать на одну клавишу два раза, 
когда мы берём «аккорд»). После того как битовая маска сформирована, программа 
осуществляет вывод нот из введённого «аккорда».

Рекомендации
Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации строки. 
Для дальнейшей конвертации символа в строку используйте соответствующий конструктор.
Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, 
используйте оператор сдвига. Общая формула такова: 1 << индекс ноты (начинается с нуля). 
К примеру, 1 << 0 — битовый флаг ноты до, 1 << 6 — битовая маска ноты си.

Перечисление, хранящее ноты, имеет следующий вид:
enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

Далее проверяем наличие бита для каждой ноты из enum в битовой маске и выводим ноту, 
если соответствующий бит выставлен:

if (notes & DO)
        {
            std::cout << "DO";
        }
И так далее.

Где notes — это целое число, хранящее битовую маску «аккорда».

*/  