﻿#include <iostream>

char checkWin(char (&field)[3][3])
{
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] && field[i][0] == field[i][2]) return field[i][0];
        else if (field[0][i] == field[1][i] && field[0][i] == field[2][i]) return field[0][i]; 
    }
    return ' ';
}

int main()
{
    char field[3][3];
    char gamerName = 'X';
    int coordinateX;
    int coordinateY;
    int counter = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = ' ';
        }
    }

    while (counter < 9)
    {
        std::cout << "Input x y gamer " << gamerName << std::endl;
        std::cin >> coordinateX >> coordinateY;
        std::cout << std::endl;
        if ((coordinateX < 0) | (coordinateX > 2) | (coordinateY < 0) | (coordinateY > 2))
        {
            std::cout << "Incorrect coordinate" << std::endl;
        }
        else if (field[coordinateX][coordinateY] != ' ')
        {
            std::cout << "This place is occupied, specify other coordinates" << std::endl;
        }
        else {
            field[coordinateX][coordinateY] = gamerName;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << field[i][j];
                    if (j < 2) std::cout << "|";
                }
                if (i < 2) std::cout << std::endl << "-----" << std::endl;
            }
            std::cout << std::endl; std::cout << std::endl;
            if (gamerName == 'X') gamerName = 'O';
            else gamerName = 'X';
            char win = checkWin(field);
            if (win != ' ') {
                std::cout << "Winner " << win << std::endl;
                break;
            }
            counter++;
        }
        
    }
    

}

/*

Старая добрая игра на страницах всех школьных тетрадей. 
Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char. 
Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе 
координаты свой символ — X или O (буквы латинского алфавита). 
Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает. 
Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья. 
Для простоты не будем рассматривать диагональные совпадения — только строго вертикальные и строго горизонтальные.

Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону). 
Это можно сделать сразу при объявлении либо с помощью вложенного цикла. 
На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение, 
и игрок должен указать координаты клетки повторно. 
После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.

Советы и рекомендации
Действия для обоих игроков одинаковые, отличаются только символом, который ставится на поле.
Игровой цикл не должен быть бесконечным. Игра имеет определённое максимальное количество шагов.
Не забывайте про случай ничьей.
Как и в предыдущем задании, здесь будет удобно сразу заполнить массив значениями false. 
Количество мест, доступных для заполнения, заранее известно. 
В процессе заполнения из этой переменой нужно не забывать вычитать единицу. 
Чтобы отметить место как занятое, нужно лишь написать places[i][j] = true;.
Проверку на победу игрока, которую надо осуществлять после каждого хода, 
можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль, и горизонталь, 
а как именно — попробуйте догадаться сами.
Здесь заранее известно число ходов — 3 * 3. Столько раз должен быть выполнен цикл, 
который спрашивает у очередного игрока координаты.
Символ, который будет установлен в указанных координатах, 
можно на каждом шаге менять подобным образом:
if (gamer_name == 'X')
                gamer_name = 'O';
else
                gamer_name = 'X';

Что оценивается
Корректный ход игры, соответствующий правилам.
Правильный (желательно красивый) вывод игрового поля.
Понятный игроку интерфейс.

*/  
