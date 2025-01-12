#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	int data1 = 0, data2 = 0, sum = 0;

	while (pq.size() != 1)
	{
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		sum += data1 + data2;
		pq.push(data1 + data2);
	}
	cout << sum;

	return 0;
}