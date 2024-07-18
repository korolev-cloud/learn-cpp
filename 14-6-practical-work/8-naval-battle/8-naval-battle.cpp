#include <iostream>
#include <cctype>

void shipPlacement(bool field[][10], char x1, char y1, char x2, char y2){
    // размещение одного корабля
    if (x2 < 10) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                field[i][j] = true;
            }
        }
    }
    else field[x1][y1] = 1;
}

void shipPlacementAll(bool field[][10], int gamer) {
    // расстановка кораблей
    // std::cout << "Gamer " << gamer << ".Enter the coordinates separated by a comma: \n";

    //bool isValidCoordinates = true;
    int x1 = 10, x2 = 10, y1 = 10, y2 = 10;
    int oneDock = 4, twoDock = 3, threeDock = 2, fourDock = 1;

    while (oneDock) {
        // цикл пока не расставлены однопалубные корабли
        std::cout << "Gamer " << gamer << ".Enter the coordinates of the four single-deck ships: \n";

        std::string coordinates;
        std::cin >> coordinates;
        int l = coordinates.length();
        for (int i = 0; i < l; i++) {
            if (i == 0) {
                if (isdigit(coordinates[i]))
                    x1 = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
            }
            else if (i == 2)
                if (isdigit(coordinates[i]))
                    y1 = coordinates[i] - 48;
            // второе число это y1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
        }
        if (x1 < 10 && y1 < 10) {
            if (field[x1][y1] != 1) {
                //если место не занято, размещаем однопалубник
                oneDock--;
                shipPlacement(field, x1, y1, x2, y2);
                std::cout << "One one-deck ship is installed! Left: " << oneDock << "\n";
            }
            else {
                std::cout << "The coordinates are busy. Try again!\n";
            }
        }
    }
    /*
    
        if (l < 7 && isdigit(coordinates[i])) {
            // координаты других кораблей
            switch (i) {
            case 0:
                x1 = coordinates[i];
                break;
            case 2:
                y1 = coordinates[i];
                break;
            case 4:
                x2 = coordinates[i];
                break;
            case 6:
                y2 = coordinates[i];
                break;
            }
            }
        else
            std::cout << "Incorrect coordinates. Try again!" << std::endl;

            if (x1 < 10 && y1 < 10) {
                if (x2 < 10 && y2 < 10) {
                    for (int i2 = x1; i2 < x2; i2++) {
                        for (int j2 = y1; j2 < y2; j2++) {
                            if (field[i2][j2] == true) {
                                std::cout << "The coordinates are busy. Try again!"
                                    << std::endl;
                                i2 = x2;
                                break;
                            }
                        }
                    }
                    if (x2 - x1 == 1 || y2 - y1 == 1) {
                        twoDock--;
                        shipPlacement(field, x1, y1, x2, y2);
                        std::cout << "Two dock added" << std::endl;
                        // размещаем двухпалубник
                    }
                    else if (x2 - x1 == 2 || y2 - y1 == 2) {
                        threeDock--;
                        shipPlacement(field, x1, y1, x2, y2);
                        std::cout << "Three dock added" << std::endl;
                        // размещаем трехпалубник
                    }
                    else if (x2 - x1 == 3 || y2 - y1 == 3) {
                        fourDock--;
                        shipPlacement(field, x1, y1, x2, y2);
                        std::cout << "Four dock added" << std::endl;
                        // размещаем четырехпалубник
                    }
                }

            }
    }
    
    */

    while (twoDock) {
        // цикл пока не расставлены однопалубные корабли
        std::cout << "Gamer " << gamer << ".Enter the coordinates of the three two-deck ships: \n";

        std::string coordinates;
        std::cin >> coordinates;
        int l = coordinates.length();
        if (l < 4) {
            std::cout << "Incorrect coordinates! Try again! \n";
            continue;
        }
        for (int i = 0; i < l; i++) {
            switch (i) {
            case 0:
                if (isdigit(coordinates[i]))
                    x1 = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n";
                    break;
                }
                break;
            case 2:
                if (isdigit(coordinates[i]))
                    y1 = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
                break;
            case 4:
                if (isdigit(coordinates[i]))
                    x2 = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
                break;
            case 6:
                if (isdigit(coordinates[i]))
                    y2 = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
                break;
            }
        }
        if (x1 < 10 && y1 < 10 && x2 < 10 && y2 < 10) {
            for (int i2 = x1; i2 < x2; i2++) {
                for (int j2 = y1; j2 < y2; j2++) {
                    if (field[i2][j2] != 1) {
                        //если место не занято, размещаем двухпалубник
                        twoDock--;
                        shipPlacement(field, x1, y1, x2, y2);
                        std::cout << "One two-deck ship is installed! Left: " << oneDock << "\n";
                    }
                    else {
                        std::cout << "The coordinates are busy. Try again!\n";
                    }
                }
            }
            
        }
    }

    while (threeDock){

    }

    while (fourDock)
    {

    }


    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        // выводим поле с кораблями текущего игрока
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}

void killShip (bool field) {
    // выстрел по кораблям

}

int main()
{
    bool field_A[10][10] = {0}; // создаем поле игрока А и инициализируем нулями
    bool field_B[10][10] = {0}; // создаем поле игрока В и инициализируем нулями
    int currentGamer = 1;
    
    shipPlacementAll(field_A, currentGamer);
    currentGamer = 2;
    shipPlacementAll(field_B, currentGamer);

    

}

/*

Требуется реализовать упрощённую игру в морской бой. Игровое поле размером 10 на 10 клеток. 
Участвуют два игрока. В арсенале каждого из них 4 маленьких кораблика размером в одну клетку, 
3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и 
один большой корабль размером в четыре клетки. Для простоты клетки поля пронумерованы 
по вертикали от 0 до 9 и по горизонтали от 0 до 9. Мы не будем использовать классические 
наименования клеток, такие как B4, C6, а просто два индекса. Вначале игроки по очереди 
расставляют корабли, начиная с самых маленьких и заканчивая большими. Маленькие корабли 
в одну клетку расставляются с помощью указания одной клетки-точки на поле, к примеру 2,1. 
Корабли размерностью от двух клеток и выше расставляются с помощью координат их начала и 
конца, к примеру: 0,1–0,3. Корабли могут быть установлены только строго вертикально или 
горизонтально. Установка корабля по диагонали недопустима, об этом тоже надо сообщить 
пользователю. Если корабль не может быть размещён на заданных клетках из-за того, что 
он столкнётся с другим кораблём (окажется на его клетках) или выйдет за пределы поля, 
то игроку должно быть сделано предупреждение, после которого он должен переставить 
корабль на новые валидные координаты. В нашем упрощённом варианте игры мы не будем 
обсчитывать соприкосновения кораблей друг с другом, а потому корабли вполне можно 
будет размещать друг к другу вплотную, борт к борту. После того как все корабли 
расставлены, начинается игра. Игроки по очереди атакуют друг друга, называя координаты 
выстрела. После выстрела в консоль выводится информация о его результате: попал или мимо. 
Если выстрел успешен, клетка, на которой был корабль (или его фрагмент), затирается и 
становится пустой. Игра заканчивается тогда, когда все корабли одной из сторон будут 
полностью уничтожены. Как только это произойдёт, в консоль выводится информация с 
номером игрока, который победил.

Советы и рекомендации
Действия игроков практически одинаковые, их можно объединить в функции.

В программе достаточно иметь два поля, по одному на каждого игрока.

Лучше создать три отдельные функции: одну для размещения одного корабля, еще одну как 
обёртку над первой (она будет размещать все корабли), а третью для удара по координате. 
Также вам потребуются два глобальных массива для двух отдельных участков моря:

bool field_1[10][10];
bool field_2[10][10];

Что оценивается
Корабли расставляются правильно.
Есть возможность выиграть.
Реализован понятный и удобный для пользователя интерфейс игры.


Критерии оценки
В циклах нет выхода за границы массивов.
Все повторяющиеся действия вынесены в функции.
Программы запускаются и корректно работают, нет синтаксических ошибок.
Имена переменных корректные, отражают суть хранимых данных.
Создан текстовый интерфейс для всех программ, кроме первой.
Обеспечен контроль ввода, где это необходимо.
Выполнено пять заданий и более.

*/
