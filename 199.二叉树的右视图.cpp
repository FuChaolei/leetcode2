/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (65.23%)
 * Likes:    536
 * Dislikes: 0
 * Total Accepted:    138.5K
 * Total Submissions: 212.3K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1,3,4]
 *
 *
 * 示例 2:
 *
 *
 * 输入: [1,null,3]
 * 输出: [1,3]
 *
 *
 * 示例 3:
 *
 *
 * 输入: []
 * 输出: []
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,100]
 * -100  
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 二叉树的层次遍历
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left)
                {
                    q.emplace(cur->left);
                }
                if (cur->right)
                {
                    q.emplace(cur->right);
                }
                if (s == 0)
                {
                    res.emplace_back(cur->val);
                }
            }
        }
        return res;
    }
};
// @lc code=end
