#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<int> ans(N, 0);
	for (int i = 0; i < N; i++ )
	{
		cin >> A[i];
	}

	stack<int> Stack; // 인덱스 저장용
	Stack.push(0);

	for (int i = 1; i < N; i++)
	{
		while (!Stack.empty() && A[Stack.top()] < A[i])
		{
			ans[Stack.top()] = A[i];
			Stack.pop();
		}
		Stack.push(i);
	}

	while (!Stack.empty())
	{
		ans[Stack.top()] =-1;
		Stack.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] <<" ";
	}
}