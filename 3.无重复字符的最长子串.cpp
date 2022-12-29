/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.07%)
 * Likes:    8547
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 5.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
//!!!滑动窗口：首先设置数组大小为128，值为-1，遍历字符串从0到s.size
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> tmp(128, -1);
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); j++)
        {
            i = max(i, tmp[s[j]] + 1);
            res = max(res, j - i + 1);
            tmp[s[j]] = j;
        }
        return res;
    }
};
// @lc code=end
