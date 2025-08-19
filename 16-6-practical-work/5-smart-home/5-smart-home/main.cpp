#include <iostream>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int switchesState = 0;

int dayCount = 0;
int main()
{
    std::string buffer;
    int tInside, tOutside;
    std::string lightsStr, movementStr;

    while (dayCount <= 2) {
        int tempLight = 5000;
        int dayTime = 0;
        while (dayTime <= 23) {
                
            std::cout << "\nTemperature inside, temperature outside, movement, lights:\n";
            std::getline(std::cin, buffer);
            std::stringstream buffer_stream(buffer);
            buffer_stream >> tInside >> tOutside >> movementStr >> lightsStr;
            bool movement = (movementStr == "yes");
            bool lights = (lightsStr == "on");
            
            if (lights && !(switchesState & LIGHTS_INSIDE)){
                //свет внутри выключен и команда включить
                switchesState |= LIGHTS_INSIDE;
                //изменяем состояние на включено
                std::cout << "Lights inside ON!\n";
            }
            
            if (!lights && (switchesState & LIGHTS_INSIDE)) {
                //проверяем что свет внутри включен и введено выключить
                switchesState &= ~LIGHTS_INSIDE;
                // изменяем состояние на выключено
                std::cout << "Lights inside OFF!\n";
            }
            
            
            if (dayTime >= 16 || dayTime < 5) {
                if (movement && !(switchesState & LIGHTS_OUTSIDE)){
                    //свет выключен и есть движение?
                    switchesState |= LIGHTS_OUTSIDE;
                    //изменяем состояние на включено
                    std::cout << "Lights outside ON!\n";;
                }
                
                if (dayTime >= 16 && dayTime < 20) tempLight -= (5000 - 2700) / (20 - 16);
            }
            if (!movement && (switchesState & LIGHTS_OUTSIDE)) {
                //проверяем что свет снаружи включен и нет движения
                switchesState &= ~LIGHTS_OUTSIDE;
                // изменяем состояние на выключено
                std::cout << "Lights outside OFF!\n";;
            }
            
            if ((switchesState & LIGHTS_OUTSIDE) || (switchesState & LIGHTS_INSIDE)) {
                std::cout << "Color temperature: " << tempLight << " K\n";
            }
            
            
            if (tOutside < 0 && !(switchesState & WATER_PIPE_HEATING)) {
                switchesState |= WATER_PIPE_HEATING;
                std::cout << "Water pipe heating ON!\n";
            }
            else if (tOutside > 5 && (switchesState & WATER_PIPE_HEATING)) {
                switchesState &= ~WATER_PIPE_HEATING;
                std::cout << "Water pipe heating OFF!\n";
            }
            if (tInside < 22 && !(switchesState & HEATERS)) {
                switchesState |= HEATERS;
                std::cout << "HEATERS ON!\n";
            }
            else if (tInside >= 25 && (switchesState & HEATERS)) {
                switchesState &= ~HEATERS;
                std::cout << "HEATERS OFF!\n";
            }
            if (tInside >= 30 && !(switchesState & CONDITIONER)) {
                switchesState |= CONDITIONER;
                std::cout << "CONDITIONER ON!\n";
            }
            else if (tInside <= 25 && (switchesState & CONDITIONER)) {
                switchesState &= ~CONDITIONER;
                std::cout << "CONDITIONER OFF!\n";
            }
            dayTime++;
        }
        dayCount++;
    }
    
}

/*

Разработайте упрощённую модель умного дома для дачи. 
Выполните симуляцию его работы на протяжении двух дней. 
Стартовое время для симуляции умного дома 00:00. 
Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома. 
В доме расположен электронный умный щиток с автоматами. 
Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств:

отключение и включение питания всего дома;
основные розетки дома;
свет внутри дома;
наружный свет в саду;
отопление в помещении;
отопление водопровода, идущего из скважины с насосом;
кондиционер в помещении.
Есть несколько условий по включению/отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0 °С, 
надо включить систему обогрева водопровода. 
Если температура снаружи поднялась выше 5 °С, 
то систему обогрева водопровода нужно отключить.
Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) 
и снаружи есть какое-то движение, то необходимо включить садовое освещение. 
Если движения нет или время не вечернее, то света снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление. 
Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
Если температура в помещении поднялась до 30 °С, включается кондиционер. 
Как только температура становится 25 °С, кондиционер отключается.
Всё освещение в доме также умное и поддерживает настройку цветовой 
температуры для комфортного нахождения. Каждый день начиная с 16:00 и до 20:00 
температура цвета должна плавно изменяться с 5000K до 2700К. 
Разумеется, это изменение должно происходить, если свет сейчас включён. 
В 00:00 температура сбрасывается до 5000К.
Все события по отключению и включению устройств должны выводиться в консоль явным образом. 
Если устройство не изменило своё состояние (осталось включённым или выключенным), 
событие генерироваться не должно! Если свет в доме включён, 
должна отображаться текущая цветовая температура.

Программа выполняется следующим образом:

Каждый час пользователь сообщает состояние всех основных датчиков и света 
(температура снаружи, температура внутри, есть ли движение снаружи, включён ли свет в доме).
Данные параметры вводятся разом в одну строку через пробел, 
а потом парсятся в переменные из строкового буфера stringstream.
Информация о движении выводится в формате yes/no.
Включение и отключение света происходит с помощью on/off.
Рекомендации
Состояние переключателей можно хранить в перечислении вида:

enum switches
{>
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
Чтобы включить обогреватель, нужно написать switches_state |= HEATERS; 
Чтобы выключить — switches_state &= ~HEATERS;

Пример работы программы:

Temperature inside, temperature outside, movement, lights:
10 10 yes on
Heaters ON!
Lights ON!
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
10 10 yes on
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
30 30 yes on
Heaters OFF!
Conditioner ON!
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
30 30 yes on
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:

*/   
