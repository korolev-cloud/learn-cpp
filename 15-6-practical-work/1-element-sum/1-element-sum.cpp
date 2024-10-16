#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
// in a given integer array (handles negative numbers as well)
int kadaneNeg(vector<int> const &arr)
{
	// stores the maximum sum subarray found so far
	int max_so_far = INT_MIN;

	// stores the maximum sum of subarray ending at the current position
	int max_ending_here = 0;

	// traverse the given array
	for (int i = 1; i < arr.size(); i++)
	{
		// update the maximum sum of subarray "ending" at index 'i' (by adding the
		// current element to maximum sum ending at previous index 'i-1')
		max_ending_here = max_ending_here + arr[i];

		// maximum sum should be more than the current element
		max_ending_here = max(max_ending_here, arr[i]);

		// update the result if the current subarray sum is found to be greater
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