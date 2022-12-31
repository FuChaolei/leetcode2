/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.71%)
 * Likes:    1268
 * Dislikes: 0
 * Total Accepted:    426.7K
 * Total Submissions: 659.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4 
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(NULL));
        int l = 0, r = nums.size() - 1;
        return qsort(nums, k, l, r);
    }
    int qsort(vector<int> &nums, int &k, int l, int r)
    {
        int m = rand() % (r - l + 1) + l;
        swap(nums[l], nums[m]);
        int x = l, y = r;
        int t = nums[x];
        while (x < y)
        {
            while (nums[y] <= t && x < y)
            {
                y--;
            }
            while (nums[x] >= t && x < y)
            {
                x++;
            }
            swap(nums[x], nums[y]);
        }
        swap(nums[x], nums[l]);
        if (x == k - 1)
        {
            return nums[x];
        }
        else if (x < k - 1)
        {
            return qsort(nums, k, x + 1, r);
        }
        else
        {
            return qsort(nums, k, l, x - 1);
        }
    }
};
// @lc code=end
