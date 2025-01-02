#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int s = 1, e = 1, sum = 1;
	int count = 1;

	while (e != N)
	{
		if (sum == N)
		{
			count++;
			e++;
			sum += e;
		}
		else if (sum < N)
		{
			e++;
			sum += e;
		}
		else
		{
			sum -= s;
			s++;
		}
	}

	cout << count << "\n";

	return 0;
}