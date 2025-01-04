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
	vector<char> Result;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	stack<int> Stack;
	int num = 1; // 오름차순 수
	bool isShow = true;

	for (int i = 0; i < N; i++)
	{
		int data = A[i];
		if(data >= num)
		{
			while (data >= num) // 목표한 수까지 push
			{
				Stack.push(num++);
				Result.push_back('+');
			}
			Stack.pop(); // 목표한 수 뽑기
			Result.push_back('-');
		}
		else
		{
			// 일단 하나 뽑아둠
			int top = Stack.top();
			Stack.pop();

			if (top > data) // 뽑고나서도 상단이 아니라면 상단이 무조건 뽑히므로 불가
			{
				cout << "NO\n";
				isShow = false;
				break;
			}
			else
			{
				Result.push_back('-');
			}
		}
	}

	if (isShow)
	{
		for (int i = 0; i < Result.size(); i++)
		{
			cout << Result[i] << "\n";
		}
	}

	return 0;
}