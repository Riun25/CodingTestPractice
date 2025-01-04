#include <iostream>
#include <deque>
using namespace std;

int main()
{
	typedef pair<int, int> node;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;//���� ���� / ������ ũ��
	cin >> N >> L;
	deque<node> Deque;

	for (int i = 0; i < N; i++)
	{
		int now;
		cin >> now;
		// ���� ������ ū ������ �� ��������
		while (Deque.size() && Deque.back().first > now)// Deque.size() : ���� ��Ұ� �����ϴ°�?
		{
			Deque.pop_back();
		}

		Deque.push_back(node(now, i)); // ���(���� ��, idx)�� �־���

		if (Deque.front().second <= i - L) // idx�� �����츦 �Ѿ�� �պκ� �����ؼ� ������ ũ�� ����
		{
			Deque.pop_front();
		}

		cout << Deque.front().first << ' ';
	}
	return 0;
}