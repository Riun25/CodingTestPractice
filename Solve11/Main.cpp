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
	int num = 1; // �������� ��
	bool isShow = true;

	for (int i = 0; i < N; i++)
	{
		int data = A[i];
		if(data >= num)
		{
			while (data >= num) // ��ǥ�� ������ push
			{
				Stack.push(num++);
				Result.push_back('+');
			}
			Stack.pop(); // ��ǥ�� �� �̱�
			Result.push_back('-');
		}
		else
		{
			// �ϴ� �ϳ� �̾Ƶ�
			int top = Stack.top();
			Stack.pop();

			if (top > data) // �̰����� ����� �ƴ϶�� ����� ������ �����Ƿ� �Ұ�
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