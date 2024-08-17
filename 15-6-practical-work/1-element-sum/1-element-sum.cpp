#include <iostream>

int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 6, 9};
    int startPos = 0;
    int endPos = sizeof(a) / sizeof(a[0]) - 1;
    int sum = 0;
    for (int j = 0; j < endPos; j++) {
        int currentSum = 0;
        for (int i = startPos; i < j; i++) {
            currentSum += a[i];
        }
        if (currentSum < sum) startPos++;
        else sum = currentSum;
        if (a[startPos] + a[startPos + 1] < 0) startPos += 2;
        if ((a[endPos] + a[endPos - 1]) < 0) endPos -= 2;
        sum += a[j];
    }
    
    std::cout << "Sum = " << sum << "\n";
    std::cout << "startPos = " << startPos << "\n";
    std::cout << "endPos = " << endPos << "\n";

}

/*

Вам даётся массив целых чисел.Необходимо найти в массиве такие два индекса i и j, 
что сумма a[i], a[i + 1], a[i + 2], …, a[j] будет максимально возможной, и вывести их.

Пример
a = { −2, 1, −3, 4, −1 ,2 ,1 ,−5 ,4 }

Наибольшая сумма последовательных элементов находится между 
индексами 3 и 6: {4, −1, 2, 1}, сумма = 6. Необходимо вывести 3 и 6.

*/  