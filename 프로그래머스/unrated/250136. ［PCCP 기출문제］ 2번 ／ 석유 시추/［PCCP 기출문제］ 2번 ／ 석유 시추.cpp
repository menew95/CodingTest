#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

tuple<int, int, int> find_oil(pair<int, int> pos, vector<vector<bool>>& visit, vector<vector<int>>& land)
{
    tuple<int, int, int> _ret = { pos.second, pos.second, 1 };
    
    queue<pair<int, int>> _queue;
    _queue.push(pos);
    visit[pos.first][pos.second] = true;
    
    while(!_queue.empty())
    {
        auto _cur = _queue.front();
        _queue.pop();
        
        int _dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for(int i = 0; i < 4; i++)
        {
            pair<int, int> _n = { _cur.first + _dir[i][0], _cur.second + _dir[i][1] };
            
            if(_n.first < 0 || _n.first == land.size()
              || _n.second < 0 || _n.second == land[0].size()
              || visit[_n.first][_n.second] || !land[_n.first][_n.second])
                continue;
            
            visit[_n.first][_n.second] = true;
            
            get<0>(_ret) = min(get<0>(_ret), _n.second);
            get<1>(_ret) = max(get<1>(_ret), _n.second);
            get<2>(_ret) = get<2>(_ret) + 1;
            _queue.push(_n);
        }
    }
    
    return _ret;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    vector<vector<bool>> _visit(land.size(), vector<bool>(land[0].size(), false));
    
    vector<tuple<int, int, int>> _oils;
    
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[0].size(); j++)
        {
            if(!_visit[i][j] && land[i][j])
            {
                _oils.push_back(find_oil({i, j}, _visit, land));
            }
        }
    }

    
    for(int i = 0; i < land[0].size(); i++)
    {
        int _oil_cnt = 0;
        
        for(auto& _oil : _oils)
        {
            if(get<0>(_oil) > i || i > get<1>(_oil))
            {
                continue;
            }
            
            _oil_cnt += get<2>(_oil);
        }
        
        answer = max(answer, _oil_cnt);
    }
    
    return answer;
}