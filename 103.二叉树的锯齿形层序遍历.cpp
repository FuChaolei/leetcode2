/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.43%)
 * Likes:    725
 * Dislikes: 0
 * Total Accepted:    281.8K
 * Total Submissions: 490.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        deque<TreeNode *> dq;
        if (root == nullptr)
        {
            return res;
        }
        dq.emplace_back(root);
        bool t = true;
        while (!dq.empty())
        {
            vector<int> tmp;
            int s = dq.size();
            while (s--)
            {
                TreeNode *cur;
                if (t)
                {
                    cur = dq.front();
                    if (cur->left)
                    {
                        dq.emplace_back(cur->left);
                    }
                    if (cur->right)
                    {
                        dq.emplace_back(cur->right);
                    }
                    dq.pop_front();
                }
                else
                {
                    cur = dq.back();
                    if (cur->right)
                    {
                        dq.emplace_front(cur->right);
                    }
                    if (cur->left)
                    {
                        dq.emplace_front(cur->left);
                    }
                    dq.pop_back();
                }
                tmp.emplace_back(cur->val);
            }
            t = !t;
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end
