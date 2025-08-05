#include <iostream>
#include <vector>
#include <algorithm>

long long max_of_three(long long a, long long b, long long c) {
    return std::max({a, b, c});
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    
    int n, m;
    std::cin >> n >> m;


    std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m));

  
    for (int i = 0; i < n; ++i) {
        dp[i][0] = a[i][0];
    }


    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) { 
            
           
            long long prev_max_score;

            if (i == 0) { 
                prev_max_score = std::max(dp[i][j - 1], dp[i + 1][j - 1]);
            } else if (i == n - 1) { 
                prev_max_score = std::max(dp[i][j - 1], dp[i - 1][j - 1]);
            } else { 
                prev_max_score = max_of_three(dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]);
            }
            
            dp[i][j] = a[i][j] + prev_max_score;
        }
    }

   
    long long max_beauty = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i][m - 1] > max_beauty) {
            max_beauty = dp[i][m - 1];
        }
    }

   
    std::cout << max_beauty << std::endl;

    return 0;
}