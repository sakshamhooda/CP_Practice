#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>

using namespace std;

const long long INF = -1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> counts(51, 0);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        counts[s]++;
    }

    vector<vector<long long>> dp(52, vector<long long>(n + 1, INF));

    for (int j = 0; j <= counts[0]; ++j) {
        dp[1][j] = 0;
    }

    for (int i = 1; i <= 50; ++i) {
    
        for (int k = 0; k <= n; ++k) {
            if (dp[i][k] == INF) { 
                continue;
            }

            for (int j = 0; j <= min(k, counts[i]); ++j) {
                
                long long score_from_closing = (long long)(k - j) * i;
                
                long long score_from_summing_leftovers = (long long)(counts[i] - j) * i;

                long long current_total_score = dp[i][k] + score_from_closing + score_from_summing_leftovers;

                dp[i + 1][j] = max(dp[i + 1][j], current_total_score);
            }
        }
    }

    cout << dp[51][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}