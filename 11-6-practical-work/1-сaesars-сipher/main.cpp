#include <iostream>

std::string encrypt_caesar (std::string text, int shift)
{
    std::string encrypt;
    for (int i = 0; i < text.length(); i++)
    {
        encrypt += i + shift;
    }
    return encrypt;
}

int main ()
{
    std::string text;
    int shift;
    std::cout << "Text: "; std::cin >> text;
    std::cout << "Code: "; std::cin >> shift;
    std::cout << encrypt_caesar(text, shift);
}

/* Задание 1. Шифр Цезаря
Что нужно сделать
Юлий Цезарь использовал свой способ шифрования текста. Каждая буква заменялась на 
следующую по алфавиту через K позиций по кругу. Если взять английский алфавит и 
K = 3, то в слове, которое мы хотим зашифровать, буква A станет буквой D, B станет E
и так далее. Если для сдвига на данное число позиций алфавита не хватает, то он 
зацикливается, то есть последняя буква алфавита Z, сдвинутая на одну позицию, 
будет преобразовываться в A. 
Напишите функцию encrypt_caesar, в которую передаётся текст и сдвиг и которая 
возвращает зашифрованный текст. Считаем, что входные строки состоят лишь из 
английских букв. Если там содержатся и другие символы, то их надо выдать без 
шифрования. Регистр букв (заглавные и строчные) меняться не должен.

Пример 1:
Text: aBxZ*
Code: 67

Результат:
pQmO*

Пример 2:
Text: The quick brown fox jumps over the lazy dog
Code: 3

Результат:
Wkh txlfn eurzq ira mxpsv ryhu wkh odcb grj

Рекомендации
Функция шифрования принимает на вход строку и смещение. Нужно добавить 
смещение к числовому значению очередной буквы, но учесть зацикленность нашего алфавита.

У английской буквы ‘A’ числовое значение 65. Вы можете узнать остальные 
значения при помощи cout << int(‘интересующая вас буква’);
То есть для получения числового значения символа добавляем одинарные кавычки. 
Чтобы проверить, попадает ли символ в диапазон, нужно сделать if(symbol >= ‘x’ && symbol <=’z’). 
Коды у заглавных и строчных символов разные. Чтобы ограничить число верхним пределом, 
можно воспользоваться оператором %. 
При делении с остатком на число 26 никогда не получим число больше него. Значит, 
не выйдем за пределы алфавита, а снова попадём в его начало (27 % 26 даёт 1, то 
есть снова первый символ). Чтобы зашифровать символ s, нужно:
Отнять от него значение первого символа алфавита (‘a’ или ‘A’ — вам потребуются 
два условия для двух разных случаев). Получим порядковый номер символа в алфавите. 
Добавить смещение шифра, которое указывает пользователь. 
Полученное значение разделить с остатком на 26. Получим порядковый номер символа 
в алфавите с учётом его зацикленности. Осталось получить этот символ, зная его номер. 
Для этого к коду первого символа алфавита (‘a’ или ‘A’) добавляем полученный порядковый номер.
Что оценивается
Корректность работы программы по созданию зашифрованной версии слова или текста.
Как отправить задание на проверку
Пришлите ссылку на repl.it или файл .срр с решением через форму ниже. Также вы 
можете создать открытый репозиторий в GitHub с содержимым проекта.
*/