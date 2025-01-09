#include <iostream>
#include <vector>
using namespace std;

static int N;

bool IsPrime(int _num) // �Ҽ��� ���Ѵ�.
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
	if (_ten == N) // �ڸ����� ��ġ�ϴ� ���� ����ϰ� ����
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
		if (IsPrime(_num * 10 + i) == true) // �Ҽ��� �´ٸ� �ڸ����� �ø�
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

	// �ϱ��Ѵ�. �ڸ����� 1�̰� �Ҽ��� �� : 2, 3, 5, 7
	// 1�� �ڸ��� ¦���� �Ұ��ϴ�.

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}