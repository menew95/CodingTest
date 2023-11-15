#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 10e14;
    
    auto _can_build = [&](long long time)
    {
        int _gold = 0, _siver = 0, _total = 0;
        
        for (int i = 0; i < g.size(); i++)
        {
            long long _move_times = time / (t[i] * 2);
            
            if (time % (t[i] * 2) >= t[i]) _move_times++;
            
            long long _can_move = w[i] * _move_times;
 
            _gold += (long long)g[i] < _can_move ? (long long)g[i] : _can_move;
            _siver += (long long)s[i] < _can_move ? (long long)s[i] : _can_move;
            _total += (long long)(g[i] + s[i]) < _can_move ? (long long)g[i] + s[i] : _can_move;
        }
        
        return (_gold >= a && _siver >= b && _total >= a + b);
    };
    
    long long _s = 0, _e = 10e14 * 3;
    
    while(_s <= _e)
    {
        long long _mid = (_s + _e) / 2;
        
        if(_can_build(_mid))
        {
            answer = answer < _mid ? answer : _mid;
            _e = _mid - 1;
        }
        else
        {
            _s = _mid + 1;
        }
    }
    
    return answer;
}