#include <iostream>

int main()
{
	int countNum = 0;
	std::cin >> countNum;

	std::string number;
	std::cin >> number;

	int sum = 0;

	for (int i = 0; i < countNum; i++)
	{
		sum += number[i] - '0';
	}

	std::cout << sum << "\n";

	return 0;
}