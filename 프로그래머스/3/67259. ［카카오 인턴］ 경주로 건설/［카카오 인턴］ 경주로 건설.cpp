#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Point{
    int _x;
    int _y;
    int _cost;
    int _prevDir;
    
    Point() = default;
    
    Point(int x, int y, int cost, int dir)
        :_x(x), _y(y), _cost(cost), _prevDir(dir){};
};

struct cmp{
    bool operator () (Point& a, Point& b){
        return a._cost > b._cost;
    }
};

int solution(vector<vector<int>> board) {    
    int _dist[26][26][4];
    int _dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int _row = board.size(), _col = board[0].size();
    const int INF = 987654321;
    int answer = INF;
    priority_queue<Point, vector<Point>, cmp> _pq;
    
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 4; k++)
                _dist[i][j][k] = INF;
    
    _pq.push({0, 0, 0, 0});
    _pq.push({0, 0, 0, 1});
    _pq.push({0, 0, 0, 2});
    _pq.push({0, 0, 0, 3});
    
    while(!_pq.empty())
    {
        auto _cur = _pq.top();
        
        _pq.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int _nx = _cur._x + _dir[i][0];
            int _ny = _cur._y + _dir[i][1];
            
            if ( abs(_cur._prevDir - i) == 2)
                continue;
            
            if (_nx < 0 || _ny < 0 || _nx >= _row 
                || _ny >= _col || board[_nx][_ny] == 1)
                continue;
            
            Point _next;
            _next._x = _nx;
            _next._y = _ny;
            _next._prevDir = i;
            
            if(_cur._prevDir == i)
                _next._cost = _cur._cost + 100;
            else
                _next._cost = _cur._cost + 600;
            
            if (_dist[_nx][_ny][i] > _next._cost){
                _dist[_nx][_ny][i] = _next._cost;
                _pq.push(_next);
            }
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        answer = min(answer, _dist[_row - 1][_col - 1][i]);
    }
    
    return answer;
}