#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    map<string, int> _gem_cnt;
    
    for(int i = 0; i < gems.size(); i++)
        _gem_cnt[gems[i]]++;
    
    int _cnt = gems.size();
    
    if(_cnt == _gem_cnt.size())
    {
        answer[0] = 1;
        answer[1] = gems.size();
        return answer;
    }
    
    int _left = 0, _right = 0, i = 0;
    
    map<string, int> _tmp;
    
    while(true)
    {
        for(i = _right; i < gems.size(); ++i)
        {
            _tmp[gems[i]]++;
            
            if (_tmp.size() == _gem_cnt.size()) {
                _right = i;
                break;
            }
        }
        
        if (i == gems.size())
            break;
        
        for (i = _left; i < gems.size(); ++i) {
            if (_tmp[gems[i]] == 1) {
                _left = i;
                break;
            }
            else _tmp[gems[i]]--;
        }
        
        if (_right - _left < _cnt) {
            answer[0] = _left + 1;
            answer[1] = _right + 1;
            _cnt = _right - _left;
        }
        
        _tmp.erase(gems[_left]);
        _left++;
        _right++;
    }
    
    return answer;
}