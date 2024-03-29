/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (39.27%)
 * Likes:    771
 * Dislikes: 0
 * Total Accepted:    381.1K
 * Total Submissions: 970.6K
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 平方根 。
 *
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 *
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：x = 4
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：x = 8
 * 输出：2
 * 解释：8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start
func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	l := 1
	r := x / 2
	var res int
	for l <= r {
		mid := (r-l)/2 + l
		t := mid * mid
		if t == x {
			return mid
		} else if t < x {
			res = mid
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return res
}

// @lc code=end

