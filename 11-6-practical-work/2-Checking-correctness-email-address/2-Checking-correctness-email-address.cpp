﻿#include <iostream>
#include <cctype>


bool foundAt = false;
// флажок найден символ @
bool isValidEmail = true;
// флажок строка валидна как email
int positionAt = 0;
// позиция @

void checkingFirstPart(char strFirst)
{
    std::string validSymbols = "@!#$%&'*+/=?^_`{|}~";
    // разрешены !#$%&'*+-/=?^_`{|}~
    for (int j = 0; j < validSymbols.length(); j++)
    {
        if (strFirst == validSymbols[j])
        {
            std::cout << "j=" << j << std::endl;
            isValidEmail = true;
            break;
        }
    }
    // символ из списка разрешенных
    if (strFirst == '@') foundAt = true;
}

void checkingSecondPart(char strSecond)
{
    if (strSecond == '@') isValidEmail = false;
    // если символ @ то isValidEmail = false
}



int main()
{

    std::string checked;
    std::cout << "Input e-mail address: "; std::cin >> checked;
    // if (checked.length() < 3) isValidEmail = false;
    // проверка на минимальное количество символов
    int firstHalf = checked.find('@');
    if (firstHalf == -1) isValidEmail = false;
    int secondHalf = checked.length() - firstHalf + 1;
    // нахождение длины первой и второй части email адреса
    // if (!firstHalf) isValidEmail = false;
    // std::cout << firstHalf << std::endl;
    // std::cout << secondHalf << std::endl;
    if (firstHalf < 2 || firstHalf > 64
        || secondHalf < 2 || secondHalf > 64) isValidEmail = false;
    // проверка на длину

    for (int i = 0; i < checked.length() && isValidEmail; i++)
        // цикл от начала до конца строки пока строка валидна как email
    {
        isValidEmail = false;
        // буквы, цифры знак «-» (дефис), точка
        // точка не первый и не последний символ, не две подряд
        if (isalpha(checked[i]) || isdigit(checked[i])
            || checked[i] == '-')
        {
            isValidEmail = true;
            std::cout << checked[i] << "=Isalpha,isdigit,-" << std::endl;
        }
        else if (checked[i] == '.' && checked[i+1] != '.')
        {
            isValidEmail = true;
            std::cout << "Dot" << std::endl;
        }
        if (!foundAt)
        {
            checkingFirstPart(checked[i]);
            // std::cout << "checkingFirstPart" << std::endl;
        }
        // если не найдена @ то проверям символы первой части
        else
        {
            checkingSecondPart(checked[i]);
            // std::cout << "checkingSecondPart" << std::endl;
        }
        // иначе проверяем вторую часть
        std::cout << isValidEmail << "=isValidEmail" << std::endl;

    }
    std::cout << (isValidEmail ? "Yes" : "No") << std::endl;
}

/*
Напишите программу, которая проверяет корректность email-адреса, 
введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен 
состоять из двух частей, разделённых знаком @. Первая часть должна 
иметь длину не менее одного и не более 64 символов, вторая часть — 
не менее одного и не более 63 символов. Из символов допускаются только 
английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может 
быть первым или последним символом, две точки не могут идти подряд. 
В первой части (перед символом @), кроме вышеперечисленных, разрешены 
ещё следующие символы:

!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес. Программа должна вывести 
слово Yes, если адрес корректен, а в противном случае — слово No.

Примеры
Корректные адреса:

simple@example.com
very.common@example.com
disposable.style.email.with+symbol@example.com
d.h+symbol@example.com
other.email-with-hyphen@example.com
fully-qualified-domain@example.com
user.name+tag+sorting@example.com (может на самом деле быть перенаправлен 
на user.name@example.com в зависимости от почтового сервиса)
x@example.com (однобуквенная локальная часть)
example-indeed@strange-example.com
admin@mailserver1
example@s.example
mailhost!username@example.org
user%example.com@example.org

Некорректные адреса:
John..Doe@example.com (две точки не могут идти подряд)
Abc.example.com (нет символа @)
A@b@c@example.com (символ @ должен быть только один)
a"b(c)d,e:f;g<h>i[j\k]l@example.com (есть недопустимые символы)
1234567890123456789012345678901234567890123456789012345678901234+x@example.com 
(первая часть длиннее 64 символов)
i_like_underscore@but_its_not_allow_in _this_part.example.com (во второй части есть недопустимый символ «_»)

Рекомендации
Активно используйте оператор индексации строки str[i], но помните, что индексы 
начинаются с нуля, а не с единицы.
Создайте отдельные функции, которые выдают первую и вторую части адреса для 
их последующего анализа.
Для валидации отдельных символов внутри части используйте дополнительные 
строки-словари, состоящие из всех корректных символов для соответствующей части.
При разработке вспомогательных функций получения первой и второй части адреса 
воспользуйтесь циклом, который проверяет текущий символ.

Если символ равен ‘@’, значит мы нашли границу между частями адреса.
В функции нахождения первой части в этом месте надо остановиться и вернуть 
все символы, что были раньше (их можно накапливать в std::string при помощи 
оператора +=). Во второй функции все символы после ‘@’ тем же оператором 
добавляются к результату.
Строка-словарь — это строка, которая в нашем случае содержит весь английский 
алфавит и символы. Каждый символ адреса надо сравнить с каждым символом из 
этого списка «допустимых символов» в цикле.
В этом задании очень важно разбить код на отдельные функции, каждая из которых 
делает небольшую часть работы.

Что оценивается
Корректные результаты валидации адресов электронной почты. 
Должны устанавливаться как валидные адреса, так и невалидные.

Как отправить задание на проверку
Пришлите ссылку на repl.it или файл .срр с решением через форму ниже. 
Также вы можете создать открытый репозиторий в GitHub с содержимым проекта.

Алгоритм проверки
bool trueAddress = false

bool функция проверка первой части

Цикл длиной строки

Проверяем, что символ является @ и trueAddress false, на true , иначе выход и возвращаем false

Если адрес true пишем Yes иначе No

*/ 