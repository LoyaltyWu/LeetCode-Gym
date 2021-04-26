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

