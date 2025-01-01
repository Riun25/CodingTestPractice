#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int qN, dataN = 0;
	cin >> dataN >> qN;
	int arr[100001] = {};

	for (int i = 1; i <= dataN; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}

	for (int j = 0; j < qN; j++)
	{
		int startN, endN;
		cin >> startN >> endN;
		cout << arr[endN] - arr[startN - 1] << "\n";
	}

	return 0;
}