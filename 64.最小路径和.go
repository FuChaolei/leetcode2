/*
 * @lc app=leetcode.cn id=64 lang=golang
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (69.48%)
 * Likes:    1452
 * Dislikes: 0
 * Total Accepted:    463.8K
 * Total Submissions: 667.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * 0
 *
 *
 */

// @lc code=start
func minPathSum(grid [][]int) int {
	n1, n2 := len(grid), len(grid[0])
	for i := 0; i < n1; i++ {
		for j := 0; j < n2; j++ {
			if i == 0 && j == 0 {
				continue
			}
			if i == 0 {
				grid[0][j] = grid[0][j] + grid[0][j-1]
			} else if j == 0 {
				grid[i][0] = grid[i][0] + grid[i-1][0]
			} else {
				grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
			}
		}
	}
	return grid[n1-1][n2-1]
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end

