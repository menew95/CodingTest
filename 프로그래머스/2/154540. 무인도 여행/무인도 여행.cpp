#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_visit(vector<string>& visit)
{
    for(auto& s : visit)
    {
        cout << s << endl;
    }
}

void DFS(int& food, int cur_x, int cur_y, vector<string>& maps)
{
    int _dir_x[] = { +1, -1, 0, 0 };
    int _dir_y[] = { 0, 0, +1, -1 };
    
    food += maps[cur_x][cur_y] - '0';
    maps[cur_x][cur_y] = 'X';
    
    for(int i = 0; i < 4; i++)
    {
        int nx = cur_x + _dir_x[i];
        int ny = cur_y + _dir_y[i];
        
        if(0 > nx || nx >= maps.size() || 0 > ny || ny >= maps[0].size() )
            continue;
        else if('0' > maps[nx][ny] || maps[nx][ny] > '9')
            continue;
        else
            DFS(food, nx, ny, maps);
    }
    
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            if('0' > maps[i][j] || maps[i][j] > '9')
                continue;
            
            int _food = 0;
            
            DFS(_food, i, j, maps);
            
            answer.push_back(_food);
        }
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    sort(answer.begin(), answer.end(), std::less<int>());

    return answer;
}