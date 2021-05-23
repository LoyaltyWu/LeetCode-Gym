# Week 7

## BFS

```c++
void BFS(Node *node) {
    queue<Node *> queue;
    queue.push(node);
    while (!queue.empty()) {
        Node *cur = queue.pop();
        // process current node
        if (cur->children.size() > 0) {
            queue.push(cur->children);
        }
    }
    return;
}
```

## 双向 BFS

稍微有点点智能的 BFS, 头尾两端开始 BFS, 尽量优先短的那部分, 进行遍历

```c++
// two-way BFS
void two_way_BFS(Node beginNode, Node endNode) {
    q1.push(beginNode));
    q2.push(endNode);
    while(q1.isNotEmpty() && q2.isNotEmpty()) {
        if (q1.size() > q2.size()) {
            swap(q1, q2);
        }
        // q1 small size
        q3 = q1.copy();
        q1.clear();
        while(q3.isNotEmpty) {
            Node node3 = q3.pop();
            q1.add(node3.children);
        }
    }
}
```

## A\* 启发式搜索

> 优先级版本的 BFS

Python 代码模版

```python
# Pythondef
AstarSearch(graph, start, end):
    pq = collections.priority_queue() # 优先级 —> 估价函数
    pq.append([start]) 
    visited.add(start)
    while pq: 
        node = pq.pop() # can we add more intelligence here ?
        visited.add(node)
        process(node) 
        nodes = generate_related_nodes(node)   
        unvisited = [node for node in nodes if node not in visited]
        pq.push(unvisited)
```
