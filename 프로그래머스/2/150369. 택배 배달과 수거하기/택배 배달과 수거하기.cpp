#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int _deliver_cnt = 0, _picks_cnt = 0;
    
    for(int i = n - 1; i >= 0; i--)
    {
        _deliver_cnt += deliveries[i];
        _picks_cnt += pickups[i];
        int _cnt = 0;
        
        while(_deliver_cnt > 0 || _picks_cnt > 0)
        {
            _deliver_cnt -= cap;
            _picks_cnt -= cap;
            _cnt++;
        }
        answer += (i + 1) * 2 * _cnt;
    }
    
    return answer;
}