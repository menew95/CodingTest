#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool macth(int i, int j, vector<string>& board)
{
    return board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1];
}

int find(vector<string>& board)
{
    int _ret = 0;
    
    set<pair<int, int>> _finds;
    
    for(int i = 0; i < board.size() - 1; i++)
    {
        for(int j = 0; j < board[0].size() - 1; j++)
        {
            if(macth(i, j, board))
            {
                _finds.insert({i, j});
                _finds.insert({i + 1, j});
                _finds.insert({i, j + 1});
                _finds.insert({i + 1, j + 1});
            }
        }
    }
    
    for(auto& _p : _finds)
    {
        if(board[_p.first][_p.second] == '@')
            continue;
        _ret++;
        board[_p.first][_p.second] = '@';
    }
    
    return _ret;
}

void align(vector<string>& board)
{
    for(int j = 0; j < board[0].size(); j++)
    {
        queue<char> _q;
        
        for(int i = board.size() - 1; i >= 0; i--)
        {
            if(board[i][j] != '@')
                _q.push(board[i][j]);
        }
        
        int i = board.size();
        
        for(int i = board.size() - 1; i >= 0; i--)
        {
            if(_q.empty())
            {
                board[i][j] = '@';
            }
            else
            {
                board[i][j] = _q.front();
                _q.pop();   
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true)
    {
        int _cnt = find(board);
        
        if(_cnt == 0)
            break;
        
        answer += _cnt;
        
        align(board);
        
        cout << endl;
    }
    
    return answer;
}