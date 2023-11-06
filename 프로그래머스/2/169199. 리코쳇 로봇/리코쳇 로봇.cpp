#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int _x, _y, _cnt = 0;
};

int solution(vector<string> board) {
    int answer = 10000;
    
    Node _robot, _goal;
    
    for(int i = 0; i < board.size(); i++)
    {
        auto _r = board[i].find('R');
        auto _g = board[i].find('G');
        
        if(_r != string::npos)
        {
            _robot._x = i;
            _robot._y = _r;
        }
        if(_g != string::npos)
        {
            _goal._x = i;
            _goal._y = _g;
        }
    }
    
    queue<Node> _queue;
    
    _queue.push(_robot);
    board[_robot._x][_robot._y] = 'X';
    
    int _dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    while(!_queue.empty())
    {
        auto _cur = _queue.front();
        _queue.pop();
        
        if(_cur._x == _goal._x && _cur._y == _goal._y)
        {
            answer = answer < _cur._cnt ? answer : _cur._cnt;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int _nx = _cur._x;
            int _ny = _cur._y;
            
            while(true)
            {
                _nx += _dir[i][0];
                _ny += _dir[i][1];
                
                if(_nx < 0 || _ny < 0
                  || _nx >= board.size() || _ny >= board[i].length() 
                  || board[_nx][_ny] == 'D')
                {
                    _nx -= _dir[i][0];
                    _ny -= _dir[i][1];
                    break;
                }
            }
            
            if(board[_nx][_ny] == 'X')
                continue;
            
            board[_nx][_ny] = 'X';
            _queue.push({_nx, _ny, _cur._cnt + 1});
        }
    }
    
    if(answer == 10000)
        answer = -1;
    
    return answer;
}