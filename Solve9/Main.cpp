#include <iostream>
using namespace std;

int checkArr[4] = {}; // üũ��
int myArr[4] = {}; // ���簪
string A; // �ԷµǴ� ��
int matchNum = 0;

void Add(char c)
{
	switch (c)
	{
	case 'A':
		myArr[0]++; // ���ڸ� ó���� �־��ִ� �����̱⿡ if ������ ���� ����
		if (myArr[0] == checkArr[0])
		{
			matchNum++;
		}
		break;
	case 'C':
		myArr[1]++; // ���ڿ��̶� ������ �迭��
		if (myArr[1] == checkArr[1])
		{
			matchNum++;
		}
		break;
	case 'G':
		myArr[2]++; // ���ڿ��̶� ������ �迭��
		if (myArr[2] == checkArr[2])
		{
			matchNum++;
		}
		break;
	case 'T':
		myArr[3]++; // ���ڿ��̶� ������ �迭��
		if (myArr[3] == checkArr[3])
		{
			matchNum++;
		}
		break;
	default:
		break;
	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (myArr[0] == checkArr[0])
		{
			matchNum--;
		}
		myArr[0]--; // ���ڿ��̶� ������ �迭��
		break;
	case 'C':
		if (myArr[1] == checkArr[1])
		{
			matchNum--;
		}
		myArr[1]--; // ���ڿ��̶� ������ �迭��
		break;
	case 'G':
		if (myArr[2] == checkArr[2])
		{
			matchNum--;
		}
		myArr[2]--; // ���ڿ��̶� ������ �迭��
		break;
	case 'T':
		if (myArr[3] == checkArr[3])
		{
			matchNum--;
		}
		myArr[3]--; // ���ڿ��̶� ������ �迭��
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	cin >> A;

	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];
		if (checkArr[i] == 0) // 0�� �� ������ ������
		{
			matchNum++;
		}
	}

	for (int i = 0; i < P; i++)
	{
		Add(A[i]);
	}

	if (matchNum == 4)
	{
		count++;
	}

	for (int i = P; i < S; i++)
	{
		int j = i - P;
		Add(A[i]); // p��° �߰�
		Remove(A[j]); // ���� �տ� ���� ����
		if (matchNum == 4)
		{
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}