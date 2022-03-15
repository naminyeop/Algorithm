#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;
    queue<pair<int,int>> que;
    priority_queue<int> pri_que;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        que.push(make_pair(i,priorities[i]));
        pri_que.push(priorities[i]);
    }
    
    while(!que.empty())
    {
        int index = que.front().first;
        int pri = que.front().second;
        
        que.pop();
        
        if(pri == pri_que.top())
        {
            pri_que.pop();
            cnt++;
            if(location == index)
            {
                break;
            }
            
        }
        else
        {
            que.push(make_pair(index, pri));
        }
        
    }
    
    answer = cnt;
    
    return answer;
}
