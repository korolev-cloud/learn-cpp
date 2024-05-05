#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the number of numbers: ";
    int n;
    std::cin >> n;
    std::vector<float>vec(n);
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << " numbers ";
        std::cin >> vec[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << vec[i] << ", ";
    }
}

// Пользователь вводит с клавиатуры число n, а затем -- n действительных (дробных) чисел. 
// Необходимо вывести их все в обратном порядке (то есть сначала то число, которые пользователь ввёл последним и так далее).

