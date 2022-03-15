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
			if(str[j] == ' ')		/* 공백일때 pop으로 거꾸로 출력 */
			{
				while(!stack.empty())
				{
					cout << stack.top();
					stack.pop();					
				}
				cout << ' ';
			}
			else					/* 문자가 있을때 stack에 적재 */
			{
				stack.push(str[j]);
			}
		}
		cout << endl;
		
	}
	
	return 0;
}
