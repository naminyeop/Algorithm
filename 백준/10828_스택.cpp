#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int num, input;
	stack<int> s;
	string str;
	
	cin >> num;
	
	for(int i = 0; i < num; i++)
	{
		cin >> str;
		
		if(str == "push")		
		{
			cin >> input;
			s.push(input);
		}
		else if(str == "pop")
		{
			if(s.empty() == 0)		/* 비어 있지 않음  */
			{
				cout << s.top() << endl;	
				s.pop();
			}
			else
			{
				cout << "-1" << endl;
			} 
		}
		else if(str == "size")
		{
			cout << s.size() << endl;
		}
		else if(str == "empty")
		{
			if(s.empty() == 0)		/* 비어 있지 않음  */
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "1" << endl;
			}
		}	
		else if(str == "top")
		{
			if(s.empty() == 0)		/* 비어 있지 않음  */
			{
				cout << s.top() << endl;	
			}
			else
			{
				cout << "-1" << endl;
			} 
		}
		else;
	}

	return 0;
}
