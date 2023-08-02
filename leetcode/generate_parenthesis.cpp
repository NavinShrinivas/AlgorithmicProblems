class Solution {
public:
  vector<vector<string>> dp;
  vector<string> dp_solver(int n) {
    if (n == 1) {
      dp[1].push_back({"()"});
      return dp[1];
    }
    if (n == 0) {
      dp[0].push_back({""});
      return {""};
    }
    if (dp[n].size() != 0) {
      return dp[n];
    }
    vector<string> prev_dp = dp_solver(n - 1);
    set<string> ans;
    for (int i = 0; i < prev_dp.size(); i++) {
      ans.insert('(' + prev_dp[i] + ')');
      // The end bracket can be anywhere after opening bracket
      string t = '(' + prev_dp[i];
      for (int j = 1; j < prev_dp[i].length(); j++) {
        t.insert(j, ")");
        ans.insert(t);
        t.erase(j, 1);
      }
      ans.insert("()" + prev_dp[i]);
      ans.insert(prev_dp[i] + "()");
    }
    vector<string> vc(ans.begin(), ans.end());
    return vc;
  }
  vector<string> generateParenthesis(int n) {
    dp.assign(n + 1, vector<string>());
    return dp_solver(n);
  }
};
