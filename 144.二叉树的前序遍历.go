/*
 * @lc app=leetcode.cn id=144 lang=golang
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (70.27%)
 * Likes:    634
 * Dislikes: 0
 * Total Accepted:    391.8K
 * Total Submissions: 557.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//递归
// func preorderTraversal(root *TreeNode) []int {
// 	res := []int{}
// 	var preOrder func(*TreeNode)
// 	preOrder = func(root *TreeNode) {
// 		if root != nil {
// 			res = append(res, root.Val)
// 			preOrder(root.Left)
// 			preOrder(root.Right)
// 		}
// 	}
// 	preOrder(root)
// 	return res
// }

//迭代
func preorderTraversal(root *TreeNode) []int {
	st := []*TreeNode{}
	res := []int{}
	if root != nil {
		st = append(st, root)
	}
	for len(st) > 0 {
		cur := st[len(st)-1]
		st = st[:len(st)-1]
		res = append(res, cur.Val)
		if cur.Right != nil {
			st = append(st, cur.Right)
		}
		if cur.Left != nil {
			st = append(st, cur.Left)
		}
	}
	return res
}

// @lc code=end

