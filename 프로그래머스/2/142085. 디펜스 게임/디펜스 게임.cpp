#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int _right = 0, _left = enemy.size();
    
    int _cnt = 0;
    while(_right <= _left)
    {
        int _mid = (_right + _left) / 2;
        
        vector<int> _tmp(enemy.begin(), enemy.begin() + _mid);
        sort(_tmp.begin(), _tmp.end());
        
        long long _remain = n;
        
        if(_tmp.size() > k)
        {
            for(int i = 0; i < _tmp.size() - k; i++)
            {
                _remain -= _tmp[i];
            }
        }
        
        if(_remain < 0)
        {
            _left = _mid - 1;
        }
        else
        {
            _right = _mid + 1;
            answer = _mid;
        }
    }
    
    return answer;
}