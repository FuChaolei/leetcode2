/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.37%)
 * Likes:    4101
 * Dislikes: 0
 * Total Accepted:    727.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a"
 * 输出："a"
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "ac"
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由数字和英文字母（大写和/或小写）组成
 *
 *
 */

// @lc code=start
func longestPalindrome(s string) string {
	n := len(s)
	getlen := func(l, r int) int {
		for l >= 0 && r < n && s[l] == s[r] {
			r++
			l--
		}
		return r - l - 1
	}
	b := 0
	res := 0
	for i := 0; i < n; i++ {
		tmp := int(math.Max(float64(getlen(i, i)), float64(getlen(i, i+1))))
		if tmp > res {
			b = i - (tmp-1)/2
			res = tmp
		}
	}
	return s[b : b+res]
}

// @lc code=end

