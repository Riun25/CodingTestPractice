#include <iostream>
#include <vector>
using namespace std;

static int N;

bool IsPrime(int _num) // 소수를 구한다.
{
	for (int i = 2; i <= _num / 2; i++)
	{
		if (_num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void DFS(int _num, int _ten)
{
	if (_ten == N) // 자리수가 일치하는 것을 출력하고 종료
	{
		if (IsPrime(_num) == true)
		{
			cout << _num << "\n";
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		if (IsPrime(_num * 10 + i) == true) // 소수가 맞다면 자리수를 늘림
		{
			DFS(_num * 10 + i, _ten + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 암기한다. 자릿수가 1이고 소수인 것 : 2, 3, 5, 7
	// 1의 자리에 짝수는 불가하다.

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}