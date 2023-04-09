/*
 * @lc app=leetcode.cn id=43 lang=golang
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.71%)
 * Likes:    1078
 * Dislikes: 0
 * Total Accepted:    266.8K
 * Total Submissions: 597.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 *
 *
 */

// @lc code=start
func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	n1, n2 := len(num1), len(num2)
	ls := make([]int, n1+n2)
	for i := 0; i < n1; i++ {
		for k := 0; k < n2; k++ {
			ls[i+k+1] += (int(num1[i]) - '0') * (int(num2[k]) - '0')
		}
	}
	for i := n1 + n2 - 1; i > 0; i-- {
		ls[i-1] += ls[i] / 10
		ls[i] %= 10
	}
	res := ""
	for i := 0; i < len(ls); i++ {
		res += strconv.Itoa(ls[i])
	}
	if ls[0] == 0 {
		return res[1:]
	}
	return res
}

// @lc code=end

