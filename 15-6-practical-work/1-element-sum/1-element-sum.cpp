#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Функция для нахождения начального и конечного индекса
// подмассива с максимальной суммой элементов
int kadaneNeg(vector<int> const &arr)
{
	// подмассив с максимальной суммой, найденный на данный момент
	int max_so_far = INT_MIN;

	// максимальную сумму подмассива, заканчивающегося в текущей позиции
	int max_ending_here = 0;

	// пройдите по заданному массиву
	for (int i = 1; i < arr.size(); i++)
	{
		// обновите max_ending_here, "заканчивающегося" на индексе "i" (добавив
		// текущего элемента к максимальной сумме, заканчивающейся на предыдущем индексе "i-1")
		max_ending_here = max_ending_here + arr[i];

		// max_ending_here больше текущего элемента
		max_ending_here = max(max_ending_here, arr[i]);

		// обновите max_so_far, если сумма max_ending_here больше
		max_so_far = max(max_so_far, max_ending_here);
	}

	return max_so_far;
}

int main()
{
	vector<int> arr = { -8, 3, -6, -2, -5, -4 };

	cout << "The maximum sum of a contiguous subarray is " << kadaneNeg(arr);

	return 0;
}
/*

Вам даётся массив целых чисел.Необходимо найти в массиве такие два индекса i и j, 
что сумма a[i], a[i + 1], a[i + 2], …, a[j] будет максимально возможной, и вывести их.

Пример
a = { −2, 1, −3, 4, −1 ,2 ,1 ,−5 ,4 }

Наибольшая сумма последовательных элементов находится между 
индексами 3 и 6: {4, −1, 2, 1}, сумма = 6. Необходимо вывести 3 и 6.

*/  