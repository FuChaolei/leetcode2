/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.32%)
 * Likes:    2332
 * Dislikes: 0
 * Total Accepted:    590.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
// class Solution
// {
// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         sort(coins.rbegin(), coins.rend());
//         int ans = INT_MAX;
//         function<void(int, int, int)> dfs = [&](int s, int amount, int count)
//         {
//             if (amount == 0)
//             {
//                 ans = min(ans, count);
//                 return;
//             }
//             if (s == coins.size())
//             {
//                 return;
//             }
//             const int coin = coins[s];
//             for (int k = amount / coin; k >= 0 && count + k < ans; k--)
//             {
//                 dfs(s + 1, amount - k * coin, count + k);
//             }
//         };
//         dfs(0, amount, 0);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; i++)
        {
            for (auto c : coins)
            {
                if (i - c >= 0)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end
