#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++)
    {
        int _min = m * m + n * n;
        int _dis_x, _dis_y, _dis2;
        
        if(startY != balls[i][1])
        {
            _dis_x = min(startX + balls[i][0], (m - startX) + (m - balls[i][0]));
            _dis_y = abs(startY - balls[i][1]);
            
            _min = min(_min, _dis_x * _dis_x + _dis_y * _dis_y);
        }
        else 
        {
            if(startX < balls[i][0])
                _dis_x = startX + balls[i][0];
            else if(startX > balls[i][0])
                _dis_x = 2 * m - startX - balls[i][0];
            
            _min = min(_min, _dis_x * _dis_x);
        }
        
        if(startX != balls[i][0])
        {
            _dis_x = abs(startX - balls[i][0]);
            _dis_y = min(startY + balls[i][1], (n - startY) + (n - balls[i][1]));
            
            _min = min(_min, _dis_x * _dis_x + _dis_y * _dis_y);
        }
        else
        {
            if(startY < balls[i][1])
                _dis_y = startY + balls[i][1];
            else if(startY > balls[i][1])
                _dis_y = 2 * n - startY - balls[i][1];
            
            _min = min(_min, _dis_y * _dis_y);
        }
        
        answer.push_back(_min);
    }
    
    return answer;
}