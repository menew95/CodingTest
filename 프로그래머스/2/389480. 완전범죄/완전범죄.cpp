#include <string>
#include <vector>

using namespace std;
const int MAX = 120 + 12;

bool dp[MAX][MAX];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    int cnt = info.size();
    dp[0][0] = true;
    for(int i=0; i<cnt; ++i)
    {
        bool nextDP[MAX][MAX] = {false, };
        int traceA = info[i][0];
        int traceB = info[i][1];
        for(int a=0; a<n; ++a)
        {
            for(int b=0; b<m; b++)
            {
                if(!dp[a][b])
                    continue;
                if(a+traceA < n)
                    nextDP[a+traceA][b] = true;
                if(b+traceB < m)
                    nextDP[a][b+traceB] = true;
            }
        }
        
        for(int a=0; a<n; ++a)
        {
            for(int b=0; b<m; ++b)
            {
                dp[a][b] = nextDP[a][b];
            }
        }
    }
    
    for(int a=0; a<n; ++a)
    {
        for(int b=0; b<m; ++b)
        {
            if(dp[a][b])
                return a;
        }
    }
    
    return -1;
}