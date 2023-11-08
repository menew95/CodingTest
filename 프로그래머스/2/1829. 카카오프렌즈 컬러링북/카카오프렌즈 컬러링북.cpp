#include <vector>
#include <queue>
#include <functional>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> _visit(m, vector<bool>(n, false));
    
    function<int(int, int)> bfs = [&_visit, &picture, &m, &n](int x, int y)
    {
        int _ret = 0;
        queue<pair<int, int>> _queue;
        
        int _dir[4][2] = {{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};
        
        _queue.push({x, y});
        _visit[x][y] = true;
        
        while(!_queue.empty())
        {
            auto _cur = _queue.front();
            _queue.pop();
            
            _ret++;
            
            for(int i = 0; i < 4; i++)
            {
                int _nx = _cur.first + _dir[i][0];
                int _ny = _cur.second + _dir[i][1];
                
                if(_nx < 0 || _ny < 0 || _nx >= m || _ny >= n
                   || _visit[_nx][_ny])
                    continue;
                
                if(picture[_nx][_ny] != picture[x][y])
                    continue;
                
                _visit[_nx][_ny] = true;
                _queue.push({_nx, _ny});
            }
        }
        
        return _ret;
    };
        
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(_visit[i][j])
                continue;
            if(picture[i][j] == 0)
            {
                _visit[i][j] = true;
                continue;
            }
            
            int _size = bfs(i, j);
            
            max_size_of_one_area = max_size_of_one_area > _size ? max_size_of_one_area : _size;
            number_of_area++;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}