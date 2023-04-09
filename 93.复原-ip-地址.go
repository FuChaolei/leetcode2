/*
 * @lc app=leetcode.cn id=93 lang=golang
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    150.8K
 * Total Submissions: 279.8K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "1111"
 * 输出：["1.1.1.1"]
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "010010"
 * 输出：["0.10.0.10","0.100.1.0"]
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s 仅由数字组成
 *
 *
 */

// @lc code=start
func restoreIpAddresses(s string) []string {
	res := []string{}
	n := len(s)
	var backtrace func(int, int)
	check := func(b, e int) bool {
		if b > e || e-b+1 > 3 || (s[b] == '0' && b != e) {
			return false
		}
		tmp := s[b : e+1]
		sum := 0
		for i := 0; i < len(tmp); i++ {
			if tmp[i] < '0' || tmp[i] > '9' {
				return false
			}
			sum = sum*10 + int(tmp[i]) - '0'
		}
		if sum > 255 {
			return false
		}
		return true
	}
	backtrace = func(pt, st int) {
		if pt == 3 {
			if check(st, len(s)-1) {
				res = append(res, s)
			}
			return
		}
		for i := st; i < len(s); i++ {
			if check(st, i) {
				pt++
				tmp := s
				s = s[:i+1] + "." + s[i+1:]
				backtrace(pt, i+2)
				s = tmp
				pt--
			} else {
				break
			}
		}
	}
	if n > 12 || n < 4 {
		return res
	}
	backtrace(0, 0)
	return res
}

// @lc code=end

