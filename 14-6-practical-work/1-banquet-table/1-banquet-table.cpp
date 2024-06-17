﻿#include <iostream>

int main()
{
    int tableware[2][6] = { {4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3} }; // столовые приборы
    int dishes[2][6] = { {3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2} }; // тарелки
    int chairs[2][6] = { {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1} }; // стулья
    chairs[0][4] += 1; // приставлен стул для ребенка
    tableware[1][2] -= 1; //украдена ложка
    tableware[0][0] -= 1; tableware[1][2] += 1; //VIP поделилась ложкой
    dishes[0][0] -= 1; // официант забрал десертную тарелку


}


/*

По поводу успешного прохождения двумерных массивов собирается банкет, организуется стол на 12 персон. 
Есть два VIP-места, они рядом во главе стола. Стол протяжён в длину, места расположены в два ряда. 
Каждый пришедший должен быть «упакован» соответствующим образом. Во-первых, столовые приборы: 
по три на каждого человека (вилка, ложка, нож) и одна маленькая дополнительная ложечка для VIP-персон (для десерта). 
Во-вторых, тарелки: каждому по две (для первого и второго блюда) и ещё одна тарелка для VIP-персон (для десерта). 
В-третьих, стулья: минимум один для каждого гостя. Заведите соответствующие 
двумерные массивы для количества приборов, посуды и стульев и проинициализируйте их.

Но это ещё не всё. На банкете после инициализации происходят некоторые события. 
Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому на данное место был приставлен ещё один стул. 
С третьего места во втором ряду в неизвестном направлении была украдена ложка. 
Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки, 
и стала есть суп десертной. За ненадобностью официант забрал у VIP-гостя одну десертную тарелку, 
ведь есть десерт ложкой, которая уже побывала уже в супе, неприлично. Больше без происшествий, 
однако эти события на банкете надо отразить в инициализированных ранее массивах.

Советы и рекомендации
Все действия в задаче оформляются в виде выражений внутри исходного кода. 
Текстовый интерфейс для задачи делать необязательно.
Необходимо объявить несколько двумерных массивов (по типам приборов).
Массивы очень удобно инициализировать сразу при объявлении так:
int packages[2][3] = {{2, 1, 7},{3, 5, 31}}
Проще будет сначала записать в массивы значения из задания, а потом отнимать или прибавлять 
нужные элементы, следуя за сценарием событий:
packages[0][0] +=1; // packages[0][0] хранит в себе цифру 2, и мы прибавляем к этому значению 1 — += 1.
Что оценивается
Все действия внутри массива соответствуют условию.

*/
