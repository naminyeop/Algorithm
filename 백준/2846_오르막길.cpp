#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int num=0, temp=0, max=0;
	int val;
	vector<int> v;
	vector<int> updown;		/* up�̸� 1, �̿� 0 */
	int check[1000];		/* Ȯ�ξ�������(0), Ȯ��������(1) */
	/* ������ ũ�� �Է� */
	cin >> num;	
	
	/* ������ ũ�⸸ŭ val �Է� vector ��� */
	for(int i = 0; i < num; i++)
	{
		cin >> val;
		v.push_back(val);
	}

//	for(int i = 0; i < num; i++)
//	{
//		cout << v[i] << endl;
//	}	
	
	/* vector�� Ž�� �ϸ鼭 updown vector�� up(1), down(0) üũ */
	for(int i = 0; i < num - 1; i++)
	{
		if(v[i+1] - v[i] > 0) 	/* up �̸� */
		{
			updown.push_back(1);
		}
		else
		{
			updown.push_back(0);
		}
	}
	
//	for(int i = 0; i < num - 1; i++)
//	{
//		cout << updown[i] << ", ";
//	}	
//	cout << endl;
	
	int i, j;
	
	for(i = 0; i < num - 1; i++)
	{
		if(updown[i] == 1)		/* up�� ��� */
		{
			for(j = i+1; j < num - 1; j++)
			{
				if(updown[j] == 0)
				{
					break;
				}
			}
			temp = v[j] - v[i];
			if(temp > max) max = temp;		
		}
	}
	
	cout << max << endl;
		
	return 0;
}
