
class Solution {
public:
  vector<int> dp;
  int dp_solver(int n) {
    if (n <= 1) {
      return 1;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += dp_solver(i - 1) * dp_solver(n - i);
    }
    dp[n] = ans;
    return dp[n];
  }
  int numTrees(int n) {
    for (int i = 0; i <= n + 1; i++) {
      dp.push_back(-1);
    }
    return dp_solver(n);
  }
};
