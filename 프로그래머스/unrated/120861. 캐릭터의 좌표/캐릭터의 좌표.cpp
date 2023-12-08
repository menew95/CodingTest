#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    int _size_x = board[0] / 2, _size_y = board[1] / 2;
    
    for(auto& _s : keyinput)
    {
        if(_s[0] == 'l' && answer[0] - 1 >= _size_x * -1) answer[0]--;
        else if(_s[0] == 'r' && answer[0] + 1 <= _size_x) answer[0]++;
        else if(_s[0] == 'u' && answer[1] + 1 <= _size_y) answer[1]++;
        else if(_s[0] == 'd' && answer[1] - 1 >= _size_y * -1) answer[1]--;
    }
    return answer;
}