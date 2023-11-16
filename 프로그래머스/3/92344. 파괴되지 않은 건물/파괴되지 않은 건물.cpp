#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> _acc(board.size() + 1, vector<int>(board.size() + 1, 0));
    
    for(int i = 0; i < skill.size(); i++)
    {
        skill[i][5] = skill[i][0] == 2 ? skill[i][5] : skill[i][5] * -1;
        
        _acc[skill[i][1]][skill[i][2]] += skill[i][5];
        _acc[skill[i][3] + 1][skill[i][4] + 1] += skill[i][5];
        _acc[skill[i][1]][skill[i][4] + 1] -= skill[i][5];
        _acc[skill[i][3] + 1][skill[i][2]] -= skill[i][5];
    }
    
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
            _acc[i][j + 1] += _acc[i][j];
    
    for(int j = 0; j < board[0].size(); j++)
        for(int i = 0; i < board.size(); i++)
            _acc[i + 1][j] += _acc[i][j];
    
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
            if(board[i][j] + _acc[i][j] > 0)
                answer++;
    
    return answer;
}