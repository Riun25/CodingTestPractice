#include <iostream>
using namespace std;

int main()
{
	// 시험 본 과목 개수
	int n;
	int subject[1000];
	cin >> n;
	
	int i = 0;
	int maxScore = 0;
	int sumScoure = 0;

	while (i < n)
	{
		cin >> subject[i];

		if (subject[i] > maxScore)
		{
			maxScore = subject[i];
		}
		sumScoure += subject[i];
		i++;
	}

	float result = sumScoure * 100.0f / maxScore / n;

	std::cout << result << "\n";

	return 0;
}