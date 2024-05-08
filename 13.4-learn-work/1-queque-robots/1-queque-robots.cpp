#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec(0);
	int num = 0;
	while (num != -1)
	{
		cout << "Enter number ";
		cin >> num;
		assert(int(num));
		vec.push_back(num);
		
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

/* С помощью push_back() реализуйте очередь из роботов-андроидов. 
Роботы приходят в очередь и называют(вводят с клавиатуры) свои порядковые номера 
(целые положительные). Последний робот в очереди всегда имеет номер -1. 
Когда он пришёл, необходимо вывести на экран все номера в очереди.
*/