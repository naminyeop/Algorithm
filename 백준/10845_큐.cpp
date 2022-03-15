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
			if(!q.empty())		// 큐가 비어있지 x
			{
				cout << q.front() << endl;
				q.pop();
			} 
			else				// 큐가 비어있다면 
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
			if(!q.empty())		// 큐가 비어있지 x
			{
				cout << "0" << endl;
			} 
			else				// 큐가 비어있다면 
			{
				cout << "1" << endl;
			}			
		}
		else if(str == "front")
		{
			if(!q.empty())		// 큐가 비어있지 x
			{
				cout << q.front() << endl;
			} 
			else				// 큐가 비어있다면 
			{
				cout << "-1" << endl;
			}
		}
		else if(str == "back")
		{
			if(!q.empty())		// 큐가 비어있지 x
			{
				cout << q.back() << endl;
			} 
			else				// 큐가 비어있다면 
			{
				cout << "-1" << endl;
			}
		}
		else;
	}
		
	return 0;
}
