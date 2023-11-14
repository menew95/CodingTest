#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct block
{
    block(int i, int j) : _cnt(1)
    {
        _block.push_back({i, j});
    }
    
    bool _use = false;
    
    int _cnt = 0;
    int _bufSize = 0;
    vector<pair<int, int>> _block;
    
    void align()
    {
        int _minX = 50, _minY;
        
        for(int i = 0; i < _block.size(); i++)
        {
            _minX = _minX < _block[i].first ? _minX : _block[i].first;
            _minY = _minY < _block[i].second ? _minY : _block[i].second;
        }
        
        for(int i = 0; i < _block.size(); i++)
        {
            _block[i].first -= _minX;
            _block[i].second -= _minY;
        }
    }
    
    void rotate()
    {
        int _rot[2][2] = {{0, -1}, {1, 0}};
        
        for(int i = 0; i < _block.size(); i++)
        {
            int _tmp = _block[i].first * _rot[0][0] + _block[i].second * _rot[1][0];
            _block[i].second = _block[i].first * _rot[0][1] + _block[i].second * _rot[1][1];
            _block[i].first = _tmp;
        }
        
        align();
    }
    
    void render()
    {
        vector<vector<int>> _buf(6, vector<int>(6, 0));
        
        for(auto& _p : _block)
        {
            if(_p.first < 0 || _p.second < 0)
            {
                cout << _p.first << _p.second << endl;
                continue;   
            }
            _buf[_p.first][_p.second] = 1;
        }
        
        for(auto& _v : _buf)
        {
            for(auto i : _v)
                cout << i;
            cout << endl;
        }
        
        cout << endl;
    }
    
    bool operator==(block& r)
    {
        for(int i = 0; i < _block.size(); i++)
        {
            bool _find = false;
            
            for(int j = 0; j < r._block.size(); j++)
            {
                if(_block[i] == r._block[j])
                {
                    _find = true;
                    break;
                }
            }
            
            if(!_find)
                return false;
        }
        
        return true;
    }
};

void dfs(block& block, int x, int y, vector<vector<bool>>& visit, vector<vector<int>>& board, int type)
{
    int _dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for(int i = 0; i < 4; i++)
    {
        int _nx = x + _dir[i][0];
        int _ny = y + _dir[i][1];
           
        if(_nx < 0 || _ny < 0 || _nx >= board.size() || _ny >= board[0].size()
           || visit[_nx][_ny] || board[_nx][_ny] == type)
            continue;
           
        visit[_nx][_ny] = true;
           
        block._cnt++;
        block._block.push_back({_nx, _ny});
           
        dfs(block, _nx, _ny, visit, board, type);
    }
}

bool match(block& blank, block& block)
{
    for(int i = 0; i < 4; i++)
    {
        bool _find = false;
        
        if(blank == block)
            return true;
        else
        {
            block.rotate();
        }
    }
    
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

    vector<block> _blanks;
    vector<block> _blocks;
    
    vector<vector<bool>> _visit(game_board.size(), vector<bool>(game_board[0].size(), false));
    
    for(int i = 0; i < game_board.size(); i++)
    {
        for(int j = 0; j < game_board[0].size(); j++)
        {
            if(_visit[i][j] || game_board[i][j] == 1)
                continue;
            
            block _newblank(i, j);
            
            _visit[i][j] = true;
            
            dfs(_newblank, i, j, _visit, game_board, 1);
            
            _newblank.align();
            
            _blanks.push_back(_newblank);
        }
    }
    _visit = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    for(int i = 0; i < table.size(); i++)
    {
        for(int j = 0; j < table[0].size(); j++)
        {
            if(_visit[i][j] || table[i][j] == 0)
                continue;
            
            block _newblock(i, j);
            
            _visit[i][j] = true;
            
            dfs(_newblock, i, j, _visit, table, 0);
            
            _newblock.align();
            
            _blocks.push_back(_newblock);
        }
    }
    
    for(int i = 0; i < _blanks.size(); i++)
    {
        for(int j = 0; j < _blocks.size(); j++)
        {
            if(_blocks[j]._use || _blanks[i]._cnt != _blocks[j]._cnt)
                continue;
            
            if(match(_blanks[i], _blocks[j]))
            {
                answer += _blocks[j]._cnt;
                _blocks[j]._use = true;
                break;
            }
        }
    }
    
    return answer;
}