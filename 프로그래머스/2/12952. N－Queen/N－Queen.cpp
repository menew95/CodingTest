#include <string>
#include <vector>
#include <iostream>

using namespace std;

int g_answer = 0;

void dfs(vector<vector<bool>>& board, int depth, int n)
{
    if(depth == n)
    {
        g_answer++;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            bool _can = true;
            
            for(int j = 0; j < depth; j++)
            {
                if(board[i][j] 
                   || (i - depth + j >= 0 && board[i - depth + j][j]) 
                   || (i + depth - j < n && board[i + depth - j][j]))
                {
                    _can = false;
                    break;
                }
            }
            
            if(!_can)
                continue;
            
            
            board[i][depth] = true;
            
            dfs(board, depth + 1, n);
            
            board[i][depth] = false;
        }
    }
}

int solution(int n) {
    
    vector<vector<bool>> _board(n, vector<bool>(n, false));
    
    dfs(_board, 0, n);
    
    return g_answer;
}