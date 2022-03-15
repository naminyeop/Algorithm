#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int num=0, temp=0, max=0;
	int val;
	vector<int> v;
	vector<int> updown;		/* up이면 1, 이외 0 */
	int check[1000];		/* 확인안했으면(0), 확인했으면(1) */
	/* 수열의 크기 입력 */
	cin >> num;	
	
	/* 수열의 크기만큼 val 입력 vector 사용 */
	for(int i = 0; i < num; i++)
	{
		cin >> val;
		v.push_back(val);
	}

//	for(int i = 0; i < num; i++)
//	{
//		cout << v[i] << endl;
//	}	
	
	/* vector를 탐색 하면서 updown vector에 up(1), down(0) 체크 */
	for(int i = 0; i < num - 1; i++)
	{
		if(v[i+1] - v[i] > 0) 	/* up 이면 */
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
		if(updown[i] == 1)		/* up인 경우 */
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
