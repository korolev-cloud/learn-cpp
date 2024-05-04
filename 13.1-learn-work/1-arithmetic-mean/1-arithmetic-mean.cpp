#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the number of numbers: ";
    int n;
    std::cin >> n;
    std::vector<int>vec(n);
    float s = 0.f;
    for (int i = 0; i < n; i++)
    {
        std::cout << i+1 << " numbers ";
        std::cin >> vec[i];
        s += vec[i];
    }
    std::cout << "Arithmetic mean: " << s / n;

}

// Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
// Необходимо вычислить их среднее арифметическое и вывести на экран.

