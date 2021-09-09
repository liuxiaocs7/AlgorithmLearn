// 双向链表节点
class ListNode {
    public int key;
    public int value;
    // 前驱
    public ListNode next;
    // 后继
    public ListNode prev;

    public ListNode(int k, int v) {
        key = k;
        value = v;
    }
}

class LRUCache {
    // 哨兵节点
    private ListNode head;
    private ListNode tail;
    // 哈希表的键是缓存的键，值是双向链表中的节点
    private Map<Integer, ListNode> map;
    // 缓存的最大容量
    int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        // 初始化双向链表
        head.next = tail;
        tail.prev = head;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        // 获取对应键的节点
        ListNode node = map.get(key);
        // 如果哈希表中没有对应的键，未找到返回-1
        if(node == null) {
            return -1;
        }
        // 哈希表中存在对应的键值对则将这个节点移动到链表尾部
        // 表示是最近访问的
        moveToTail(node, node.value);
        // 返回节点对应的值
        return node.value;
    }
    
    public void put(int key, int value) {
        // 如果哈希表中包含这个键，更新对应的值
        // 在链表中将这个节点移动到末尾表示是最近访问的
        if(map.containsKey(key)) {
            moveToTail(map.get(key), value);
        } else {  // 哈希表中不包含这个节点需要插入
            // 容量已经满了，需要将最久未被访问的节点弹出
            if(map.size() == capacity) {
                // 删除头节点(最久未被访问的节点)
                ListNode toBeDeleted = head.next;
                deleteNode(toBeDeleted);
                // 哈希表中删除这条记录
                map.remove(toBeDeleted.key);
            }
            // 新插入的节点
            ListNode node = new ListNode(key, value);
            // 将这个节点插入链表尾部表示最近访问过
            insertToTail(node);
            // 将这个节点插入哈希表
            map.put(key, node);
        }
    }

    // 将链表中的一个节点移动到链表尾部
    private void moveToTail(ListNode node, int newValue) {
        // 删除当前节点，即当前节点和其前后节点没有关联
        deleteNode(node);
        // 修改当前节点的值
        node.value = newValue;
        // 将当前节点插入到链表尾部，表示最近访问
        insertToTail(node);
    }

    // 从链表中删除某个节点
    private void deleteNode(ListNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    // 将一个节点插入到链表尾部
    private void insertToTail(ListNode node) {
        tail.prev.next = node;
        node.prev = tail.prev;
        node.next = tail;
        tail.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */