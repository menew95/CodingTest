#include <iostream>
#include <algorithm>

int main()
{
    int n; // 계단 수
    int score[301]; // 계단 점수 (1-based)
    int dp[301][3] = {0}; // 모두 0으로 초기화
    
    std::cin >> n;
    for(int i = 1; i <= n; i++) // 1-based indexing으로 입력받기
        std::cin >> score[i];
    
    dp[1][1] = score[1];
    dp[1][2] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i][1] = std::max(dp[i-2][1], dp[i-2][2]) + score[i];
        dp[i][2] = dp[i-1][1] + score[i];
    }

    int answer = std::max(dp[n][1], dp[n][2]);
    std::cout << answer;
    return 0;
}