#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the number of numbers: ";
    int n;
    std::cin >> n;
    std::vector<int>vec(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    
    std::vector<int>bigNum(2,0);
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > bigNum[0]) 
        {
            bigNum[1] = bigNum[0];
            bigNum[0] = vec[i];
        }
        else if (vec[i] > bigNum[1]) bigNum[1] = vec[i];
    }
    std::cout << bigNum[1];
}

// Пользователь вводит с клавиатуры число n, а затем -- n целых чисел. 
// Необходимо отыскать второе по величине из этих чисел и вывести на экран.


