#include <iostream>
#include <vector>

int firstNumber = 0;
int secondNumber = 0;
int result = 9;

// Функция нахождения слагаемых
void sum(std::vector<int> const &arr)
{
	// проход по массиву
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			firstNumber = i;
			secondNumber = j;
			if (arr[firstNumber] + arr[secondNumber] == result) return;
		}
	}
}

int main()
{
	std::vector<int> arr = { 2, 7, 11, 15 };
	sum(arr);
	std::cout << "Result " << result << " is a sum of " << arr[firstNumber] << " and " << arr[secondNumber];
	return 0;
}

/*
Вам даётся массив целых чисел и одно число — результат. 
Необходимо найти в массиве два числа, сумма которых будет 
давать результат, и вывести их на экран. Гарантируется, что
только одна пара чисел в массиве даёт в сумме результат.
Пример
a = {2, 7, 11, 15}. Результат = 9.
2 + 7 = 9, так что надо вывести числа 2 и 7.
Рекомендация
Как только найдена первая удовлетворяющая условиям пара, можно заканчивать поиск.
*/  