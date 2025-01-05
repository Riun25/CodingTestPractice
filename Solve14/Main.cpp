#include <iostream>
#include <queue>
using namespace std;

struct Compare
{
	bool operator()(int _n1, int _n2) 
	{
		int abs1 = abs(_n1);
		int abs2 = abs(_n2);
		if (abs1 == abs2)
		{
			return _n1 > _n2;
		}
		else
		{
			return abs1 > abs2;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, Compare> Queue;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (Queue.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << Queue.top() << "\n";
				Queue.pop();
			}
		}
		else
		{
			Queue.push(x);
		}
	}
	return 0;
}