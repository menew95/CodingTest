#include <string>
#include <vector>
#include <stack>

using namespace std;

void DFS(int depth, int n, int m, int r, vector<vector<int>>& answer)
{
    if(depth == 1)
    {
        answer.push_back({n, m});
        return;
    }
    else
    {
        DFS(depth - 1, n, r, m, answer);
        
        answer.push_back({n, m});
        
        DFS(depth - 1, r, m, n, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    DFS(n, 1, 3, 2, answer);
    
    return answer;
}