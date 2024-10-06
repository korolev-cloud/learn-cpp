#include <iostream>

int main()
{
    int a[] = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};
    int startInd = 0;
    int endInd = sizeof(a)/sizeof(a[0]);
    int maxSum = 0;
    for (int i = startInd; i <= endInd; i++) {
        if (a[i] > a[startInd]) {
            startInd = i;
        }
        if ((a[endInd] + a[endInd - 1]) < 0) endInd -= 2;
        int currentSum = 0;
        for (int j = startInd; j <= endInd; j++)
            currentSum++;
        if (currentSum > maxSum) maxSum = currentSum;
        else break;
    }
    std::cout << " Start = " << startInd << " End = " << endInd;
}

/*

Вам даётся массив целых чисел.Необходимо найти в массиве такие два индекса i и j, 
что сумма a[i], a[i + 1], a[i + 2], …, a[j] будет максимально возможной, и вывести их.

Пример
a = { −2, 1, −3, 4, −1 ,2 ,1 ,−5 ,4 }

Наибольшая сумма последовательных элементов находится между 
индексами 3 и 6: {4, −1, 2, 1}, сумма = 6. Необходимо вывести 3 и 6.

*/  