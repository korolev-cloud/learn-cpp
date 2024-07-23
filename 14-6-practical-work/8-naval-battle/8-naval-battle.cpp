#include <iostream>
#include <cctype>

bool shipPlacement(bool field[][10], int numberOfDeck){
    int x1, x2, y1, y2;
    
    if (numberOfDeck == 1) {
        std::string coordinates;
        std::cin >> coordinates;
        int l = coordinates.length();
        if (l > 3) {
            std::cout << "Incorrect coordinates! Input coordinates in format x,y\n" << std::endl;
            return false;
        }
        for (int i = 0; i < l; i++) {
            if (i == 0) {
                // разбор координат
                if (isdigit(coordinates[i]))
                    x1 = coordinates[i] - 48;
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
            }
            else if (i == 2)
                if (isdigit(coordinates[i]))
                    y1 = coordinates[i] - 48;
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
        }
        if (field[x1][y1] != 1) {
            //если место не занято, размещаем однопалубник
            field[x1][y1] = 1;
            return true;
        }
        else {
            std::cout << "The coordinates are busy. Try again!\n";
        }
    }
    
    else if (numberOfDeck >= 2 && numberOfDeck <= 4) {
            // расставляем многопалубные корабли
            std::string coordinates;
            std::cin >> coordinates;
            int l = coordinates.length();
            if (l < 4 || l > 7) {
                std::cout << "Incorrect coordinates! Try again! \n";
                return false;
            }
            for (int i = 0; i < l; i++) {
                // разбор введенной строки на координаты
                switch (i) {
                case 0:
                    if (isdigit(coordinates[i]))
                        x1 = coordinates[i] - 48;
                    else {
                        std::cout << "Incorrect coordinates! Try again! \n";
                        break;
                    }
                    break;
                case 2:
                    if (isdigit(coordinates[i]))
                        y1 = coordinates[i] - 48;
                    else {
                        std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                        break;
                    }
                    break;
                case 4:
                    if (isdigit(coordinates[i]))
                        x2 = coordinates[i] - 48;
                    else {
                        std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                        break;
                    }
                    break;
                case 6:
                    if (isdigit(coordinates[i]))
                        y2 = coordinates[i] - 48;
                    else {
                        std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                        break;
                    }
                    break;
                default:
                    continue;
                }
            }
            bool isValidCoordinate = true;
            int decking = 0;
            if (x1 > x2) std::swap(x1, x2);
            if (y1 > y2) std::swap(y1, y2);
            for (int i2 = x1; i2 <= x2 && isValidCoordinate; i2++) {
                // проверяем, что не заняты введенные координаты
                for (int j2 = y1; j2 <= y2; j2++) {
                    if (field[i2][j2]) {
                        std::cout << "The coordinates are busy. Try again!\n";
                        isValidCoordinate = false;
                        break;
                    }
                    decking++;
                }
            }
            if (decking != numberOfDeck) {
                // проверяем количество палуб по координатам
                std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                isValidCoordinate = false;
            }
            if (isValidCoordinate) {
                //если место не занято и палуб сколько нужно, размещаем корабль
                for (int i = x1; i <= x2; i++) {
                    for (int j = y1; j <= y2; j++) {
                        field[i][j] = 1;
                    }
                }
            }
            else
            {
                return false;
            }
    }
}

void printField(bool field[][10], int gamer) {
    std::cout << "\n        Gamer " << gamer << "\n";
    std::cout << "\n    ";
    for (int i = 0; i < 10; i++)  std::cout << i << " ";
    std::cout << "\n\n";
    for (int i = 0; i < 10; i++) {
        std::cout << i << "   ";
        // выводим поле с кораблями текущего игрока
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void shipPlacementAll(bool field[][10], int gamer) {
    printField(field, gamer);
    int oneDeck = 4, twoDeck = 3, threeDeck = 2, fourDeck = 1;
    while (oneDeck) {
        // расстановка однопалубных кораблей
        std::cout << "Enter the coordinates of the " << oneDeck << " one deck ships in format x,y: \n";
        if (shipPlacement(field, 1)) {
            oneDeck--;
        }
    }
       
    printField(field, gamer);

    while (twoDeck) {
        // расстановка двухпалубных кораблей
        std::cout << "Enter the coordinates of the " << twoDeck << " two deck ships : \n";
        if (shipPlacement(field, 2)) {
            twoDeck--;
        }
    }

    printField(field, gamer);

    while (threeDeck) {
        // расстановка трехпалубных кораблей
        std::cout << "Enter the coordinates of the " << threeDeck << " three deck ships : \n";
        if (shipPlacement(field, 3)) {
            threeDeck--;
        }
    }

    printField(field, gamer);

    while (fourDeck) {
        // расстановка четырехпалубных кораблей
        std::cout << "Enter the coordinates of the " << fourDeck << " four deck ships : \n";
        if (shipPlacement(field, 4)) {
            fourDeck--;
        }
    }

    printField(field, gamer);
}

bool killShip(bool field[][10], int x, int y) {
    // выстрел по кораблям
    if (field[x][y]) {
        return true;
    }
    else
    {
        std::cout << "\nBy!\n";
        return false;
    }
}

int main()
{
    bool field_A[10][10] = {0}; // создаем поле игрока А и инициализируем нулями
    bool field_B[10][10] = {0}; // создаем поле игрока В и инициализируем нулями
    int currentGamer = 1;
    
    shipPlacementAll(field_A, currentGamer); // запуск расстановки кораблей
    currentGamer = 2;
    shipPlacementAll(field_B, currentGamer);
    int numberHitsA = 20; // максимальное количество ходов 
    int numberHitsB = 20;


    while (numberHitsA && numberHitsB) {
        int x = 0, y = 0;
        std::cout << "Gamer " << currentGamer << " enter the coordinates of the strike: ";
        std::string coordinates;
        std::cin >> coordinates;
        int l = coordinates.length();
        if (l > 3) {
            std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
            continue;
        }
        for (int i = 0; i < l; i++) {
            if (i == 0) {
                if (isdigit(coordinates[i]))
                    x = coordinates[i] - 48;
                // первое число это x1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
            }
            else if (i == 2)
                if (isdigit(coordinates[i]))
                    y = coordinates[i] - 48;
                // второе число это y1
                else {
                    std::cout << "Incorrect coordinates! Try again! \n" << std::endl;
                    break;
                }
        }

        if (currentGamer == 1) {
            if (killShip(field_B, x, y)) {
                std::cout << "\nGot it!\n";
                field_A[x][y] = 0;
                numberHitsA--;
                continue;
            }
            else currentGamer = 2;
        }
        else
        {
            if (killShip(field_A, x, y)) {
                std::cout << "\nGot it!\n";
                field_A[x][y] = 0;
                numberHitsB--;
                continue;
            }
            else currentGamer = 1;
        }
    }
    std::cout << "\n\nThe player " << currentGamer << " win!!!\n\n\n";
    std::cout << "\n\nGame over!\n\n\n";
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
