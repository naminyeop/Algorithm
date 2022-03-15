#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	int num;
	queue<int> q;	
	
	cin >> num;
		
	for(int i = 0; i < num; i++)
	{	
		string str;
		int value;

		cin >> str;
		
		if(str == "push")
		{
			cin >> value;
			q.push(value);
		}
		else if(str == "pop")
		{
			if(!q.empty())		// ť�� ������� x
			{
				cout << q.front() << endl;
				q.pop();
			} 
			else				// ť�� ����ִٸ� 
			{
				cout << "-1" << endl;
			}
		}		
		else if(str == "size")
		{
			cout << q.size() << endl;
		}
		else if(str == "empty")
		{
			if(!q.empty())		// ť�� ������� x
			{
				cout << "0" << endl;
			} 
			else				// ť�� ����ִٸ� 
			{
				cout << "1" << endl;
			}			
		}
		else if(str == "front")
		{
			if(!q.empty())		// ť�� ������� x
			{
				cout << q.front() << endl;
			} 
			else				// ť�� ����ִٸ� 
			{
				cout << "-1" << endl;
			}
		}
		else if(str == "back")
		{
			if(!q.empty())		// ť�� ������� x
			{
				cout << q.back() << endl;
			} 
			else				// ť�� ����ִٸ� 
			{
				cout << "-1" << endl;
			}
		}
		else;
	}
		
	return 0;
}
