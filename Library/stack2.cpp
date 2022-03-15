#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> s;
	
	s.push(7);
	s.push(6);
	s.push(3);
	s.pop();
	s.push(3);
	s.pop();

	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}
