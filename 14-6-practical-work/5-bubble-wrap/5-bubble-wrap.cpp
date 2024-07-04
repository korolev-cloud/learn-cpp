﻿#include <iostream>

int main()
{
    bool shell[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << shell[i][j];
            //shell[i][j] = true;
        }
    }
}

/*

После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. 
Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька: он либо целый, либо нет, 
то есть true или false (тип массива — bool). Для начала требуется реализовать отдельную функцию 
инициализации пупырки начальным состоянием: полностью целая пупырка, все элементы true.

Программа заключается в последовательном лопании целых регионов пузырьков. 
Перед каждым таким лопанием надо показывать пользователю полностью всю плёнку: 
o — это целый пузырёк, x — лопнутый. Это тоже надо выделить в отдельную функцию. 
Итак, как выглядит само лопание. Пользователь вводит две координаты: начала региона и конца региона. 
Процедура лопания пузырей должна быть реализована с помощью отдельной функции, 
все аргументы должны проверяться на валидность, что они в в рамках диапазона возможных значений, 
иначе должна быть выведена ошибка. После лопания каждого пузыря, который не был ещё лопнут до того, 
в консоль должно выводиться сообщение “Pop!”.

Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена,
программа заканчивает выполнение. Вы можете подсчитать окончание в самой функции по 
отображению пузырьков плёнки, так как функция выполняется после каждого лопания.

Советы и рекомендации
Обратите внимание, что лопание пузырей делается с помощью региона, а не одной точки.
Регион задаётся двумя координатами, это координаты углов прямоугольника.
При лопании региона достаточно запустить цикл только по этим элементам. 
Не нужно проходить каждый раз по всей матрице.
Всю область плёнки удобно представить в виде двумерного массива типа bool.
Инициализировать вручную такой массив сложно, лучше воспользоваться вложенными циклами.

*/