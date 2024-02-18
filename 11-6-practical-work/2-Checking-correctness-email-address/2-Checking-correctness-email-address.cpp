﻿#include <iostream>
#include <regex>

bool isValidEmail(std::string Input)
{
    // шаблон регулярного выражения
    const std::regex Pattern("^[A-Za-z0-9]+([A-Za-z0-9._-]+)*[A-Za-z0-9]@[A-Za-z0-9]+\.[A-Za-z]{2,4}$");

    // возвращаем True, если в строке есть вхождение по регулярному выражению
    return std::regex_match(Input, Pattern);
}

int main()
{
    while (true)
    {
        std::string checked;
        std::cout << "Input e-mail address: "; std::cin >> checked;
        if (isValidEmail(checked))
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
    
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

*/ 