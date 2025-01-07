#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(10001, 0);
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		A[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (A[i] != 0)
		{
			for (int j = 0; j < A[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}

	return 0;
}