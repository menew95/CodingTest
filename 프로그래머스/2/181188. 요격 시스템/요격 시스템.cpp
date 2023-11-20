#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), [](auto& a, auto& b)
         {
             if(a[0] != b[0])
                return a[0] < b[0];
             
             return a[1] < b[1];
         });
        
    int _right = targets[0][1];
    
    for(int i = 1; i < targets.size(); i++) {
        if(targets[i][0] >= _right) {
            answer += 1;
            _right = targets[i][1];
        }
        else
            _right = min(_right, targets[i][1]);
    }
    
    return answer;
}