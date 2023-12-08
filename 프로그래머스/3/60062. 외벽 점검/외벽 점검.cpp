#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INT_MAX;
    int _size = weak.size();
    
    for(int i = 0; i < _size - 1; i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    
    do 
    {
        for(int i = 0; i < _size; i++)
        {
            int _s = weak[i];
            int _e = weak[i + _size - 1];
            
            for(int j = 0; j < dist.size(); j++)
            {
                _s += dist[j];
                
                if(_s >= _e) 
                {
                    answer = min(answer, j + 1);
                    break;
                }
                
                for(int k = i + 1; k < i + _size; k++)
                {
                    if(weak[k] > _s)
                    {
                        _s = weak[k];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == INT_MAX) return -1;
    
    return answer;
}