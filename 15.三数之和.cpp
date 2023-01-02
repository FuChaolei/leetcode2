/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    3738
 * Dislikes: 0
 * Total Accepted:    638.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3)
        {
            return res;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i && nums[i - 1] == nums[i])
            {
                continue;
            }
            int t = -nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == t)
                {
                    auto tmp = {nums[i], nums[j], nums[k]};
                    res.emplace_back(tmp);
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < t)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
