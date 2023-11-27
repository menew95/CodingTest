#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int g_answer = 10e16;

int bfs(pair<int, int> s, pair<int, int> e, vector<vector<int>>& board)
{
    int _ret = 0;
    queue<tuple<int, int, int>> _queue;
    
    vector<vector<bool>> _visit(4, vector<bool>(4, false));
    
    _queue.push({s.first, s.second, 0});
    
    _visit[s.first][s.second] = true;
    
    int _dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    while(!_queue.empty())
    {
        auto[_cur_x, _cur_y, _cur_cnt] = _queue.front();
        
        _queue.pop();
        
        if(_cur_x == e.first && _cur_y == e.second)
        {
            _ret = _cur_cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int _nx = _cur_x + _dir[i][0];
            int _ny = _cur_y + _dir[i][1];
            
            if(_nx < 0 || _ny < 0 || _nx > 3 || _ny > 3)
                continue;
            
            if(_visit[_nx][_ny])
                continue;
            
            _visit[_nx][_ny] = true;
            
            _queue.push({_nx, _ny, _cur_cnt + 1});
        }
        
        for(int i = 0; i < 4; i++)
        {
            int _nx = _cur_x, _ny = _cur_y;
            
            for(int j = 0; j < 4; j++)
            {
                _nx += _dir[i][0];
                _ny += _dir[i][1];
                
                if(_nx < 0 || _ny < 0 || _nx > 3 || _ny > 3)
                {
                    _nx -= _dir[i][0];
                    _ny -= _dir[i][1];
                    break;
                }
                
                if(board[_nx][_ny] != 0)
                    break;
            }
                
            if(_visit[_nx][_ny])
                continue;
            
            _visit[_nx][_ny] = true;
            _queue.push({_nx, _ny, _cur_cnt + 1});
        }
    }
    
    return _ret;
}

void dfs(int cnt, int depth, vector<int>& card, vector<vector<pair<int, int>>>& card_pos, vector<vector<int>>& board, pair<int, int> cur)
{
    if(depth == card.size())
    {
        g_answer = g_answer < cnt ? g_answer : cnt;
        return;
    }
    
    auto card_pos0 =  card_pos[card[depth]][0];
    auto card_pos1 =  card_pos[card[depth]][1];
    
    int _cnt_0_1 = bfs(cur, card_pos0, board) + bfs(card_pos0, card_pos1, board) + 2;
    int _cnt_1_0 = bfs(cur, card_pos1, board) + bfs(card_pos1, card_pos0, board) + 2;
    
    board[card_pos0.first][card_pos0.second] = 0;
    board[card_pos1.first][card_pos1.second] = 0;
    
    dfs(cnt + _cnt_0_1, depth + 1, card, card_pos, board, card_pos1);
    dfs(cnt + _cnt_1_0, depth + 1, card, card_pos, board, card_pos0);
    
    board[card_pos0.first][card_pos0.second] = 1;
    board[card_pos1.first][card_pos1.second] = 1;
}

int solution(vector<vector<int>> board, int r, int c) {
    
    vector<vector<pair<int, int>>> _card_pos(7);
    vector<int> _card;
    // 카드 위치와 카드 남은 갯수
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] != 0)
            {
                _card_pos[board[i][j]].push_back({i, j});
                _card.push_back(board[i][j]);
            }
        }
    }
    
    sort(_card.begin(), _card.end());
	_card.erase(unique(_card.begin(), _card.end()), _card.end());
    
    do
    {
        // 삭제할 카드 순서에 따라 삭제후 이동 횟수 중 최소를 찾음
        dfs(0, 0, _card, _card_pos, board, {r, c});
        
    } while(next_permutation(_card.begin(), _card.end()));
    
    return g_answer;
}