#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N,K;
	cin >> N >> K;
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	
	cout << "<";
	
	while(!q.empty())	/* queue �� �������� */
	{	
		int num;
		
		/* K-1��°���� POP�ؼ� �ǵڿ� PUSH �ϱ� */
		for(int j = 0; j < K-1; j++)
		{
			num = q.front();
//			cout << "num : " << num << endl;
			q.pop();
			q.push(num);
		}
		
		num = q.front();
		if(q.size() == 1)
		{
			cout << num <<">";
		}
		else
		{
			cout << num <<", ";			
		}
		q.pop();
	}
	
	return 0;
}
