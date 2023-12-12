#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i = l; i <= r; i++)
    {
        if(i % 5 != 0)
            continue;
        
        string _s = to_string(i);
        
        bool _tmp = true;
        for(auto _c : _s)
            if(!(_c == '0' || _c == '5'))
            {
                _tmp = false;
                break;
            }
        
        if(_tmp)
            answer.push_back(i);
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}