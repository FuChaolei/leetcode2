/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.67%)
 * Likes:    1615
 * Dislikes: 0
 * Total Accepted:    226.9K
 * Total Submissions: 430.7K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 *
 *
 *
 * 实现 LRUCache 类：
 *
 *
 * LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value)
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 *
 *
 *
 *
 *
 *
 * 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 * 0
 * 最多调用 2 * 10^5 次 get 和 put
 *
 *
 */

// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        c = capacity;
    }

    int get(int key)
    {
        auto it = m_.find(key);
        if (it == m_.cend())
        {
            return -1;
        }
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    void put(int key, int value)
    {
        auto it = m_.find(key);
        if (it != m_.cend())
        {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        if (cache_.size() == c)
        {
            // ​ 想要拷贝元素：for(auto x:range)
            // ​ 想要修改元素 : for(auto &&x:range)
            // ​ 想要只读元素：for(const auto& x:range)
            const auto &node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }

private:
    int c;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> cache_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
