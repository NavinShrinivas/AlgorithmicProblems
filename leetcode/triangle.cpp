class Solution {
public:
  vector<vector<int>> dp;
  int dp_solver(vector<vector<int>> &triangle, int row, int col) {
    cout << "here" << row << col;
    if (col > row || col < 0) {
      return 100000;
    }
    if (row == 0 and col == 0) {
      dp[0][0] = triangle[0][0];
      return dp[0][0];
    }
    if (dp[row][col] != -1) {
      return dp[row][col];
    }
    int above = dp_solver(triangle, row - 1, col);
    int above_beside = dp_solver(triangle, row - 1, col - 1);
    if (above < above_beside) {
      dp[row][col] = above + triangle[row][col];
    } else {
      dp[row][col] = above_beside + triangle[row][col];
    }
    return dp[row][col];
  }
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<vector<int>> t(triangle.size(), vector<int>(triangle.size(), -1));
    dp = t;
    vector<int> last_dist;
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
      cout << i;
      last_dist.push_back(dp_solver(triangle, triangle.size() - 1, i));
    }
    sort(last_dist.begin(), last_dist.end());
    return last_dist[0];
  }
};
