#include <iostream>
#include <deque>
using namespace std;

int main()
{
	typedef pair<int, int> node;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;//숫자 개수 / 윈도우 크기
	cin >> N >> L;
	deque<node> Deque;

	for (int i = 0; i < N; i++)
	{
		int now;
		cin >> now;
		// 현재 수보다 큰 값들은 다 지워버림
		while (Deque.size() && Deque.back().first > now)// Deque.size() : 덱에 요소가 존재하는가?
		{
			Deque.pop_back();
		}

		Deque.push_back(node(now, i)); // 노드(현재 수, idx)를 넣어줌

		if (Deque.front().second <= i - L) // idx가 윈도우를 넘어가면 앞부분 삭제해서 윈도우 크기 유지
		{
			Deque.pop_front();
		}

		cout << Deque.front().first << ' ';
	}
	return 0;
}