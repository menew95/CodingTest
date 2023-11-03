#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    for(int i = storey; i > 0;)
    {
        int _tmp = i % 10;
        if(_tmp == 5 && i > 10 && (i / 10) % 10 >= 5)
        {
            answer += 5;
            i += 10;
        }
        else if(_tmp <= 5)
        {
            answer += _tmp;
        }
        else
        {
            answer += 10 - _tmp;
            i += 10;
        }
        
        i /= 10;
    }
    
    return answer;
}