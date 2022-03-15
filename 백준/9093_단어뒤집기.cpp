#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int num;
	cin >> num;
	cin.ignore();
	
	for(int i = 0;  i < num; i++)
	{
		string str;
		stack<char> stack;
		int len;
		
		getline(cin,str);
		str += ' ';
//		cout << "str : "<< str;
		len = str.length();
		
		for(int j = 0; j < len; j++)
		{
			if(str[j] == ' ')		/* �����϶� pop���� �Ųٷ� ��� */
			{
				while(!stack.empty())
				{
					cout << stack.top();
					stack.pop();					
				}
				cout << ' ';
			}
			else					/* ���ڰ� ������ stack�� ���� */
			{
				stack.push(str[j]);
			}
		}
		cout << endl;
		
	}
	
	return 0;
}
