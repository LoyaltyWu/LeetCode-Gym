# Week 4

## DFS

1. 代码模版

```
visted = set()

def dfs(node, visited)
	if node in visted: # terminator
		# already visted
		return

	visited.add(visited)

	# process current node here.
	...
	for next_node in node.children():
		if not next_node in visited:
			dfs(next node, visited)
```

## BFS

```
dfs BFS(graph, start, end):
	queue = []
	queue.append([start]);
	visited.add(start)
	
	while queue:
		node = queue.pop()
		visited.add(node)
		
		process(node)
		nodes = generate_related_nodes(node)
		queue.push(nodes)
	
	# other process work
	...
```

## 贪心

1. 描述
	每一步最优, 达到全局的最优
2. 适用场景
	1. 问题能够分解为子问题
	2. 子问题的最优解能递推到最终结果的最优解
3. 区别于动态规划
	1. 贪心, 不回退, 子问题最优的叠加就是全局最优
	2. 动规, 保存之前的运算结果, 根据之前结果, 对当前情况进行选择, 有回退功能.
4. 难点
	1. 证明局部最优能导致全局最优
5. 技巧
	1. 正常使用贪心, 从前往后贪心
	2. 问题转化之后, 再用贪心
	3. 从后往前贪心