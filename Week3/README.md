# Week 3 递归、分治，回溯

## 递归

### 递归代码模版

```
void recursion(int level, param1, param2, ...) {
	// recursion terminator
	if (level > MAX_LEVEL) {
		process_result
		return;
	}
	// current level logic
	process(level, data, ...)
	// drill down
	recursion(level + 1, p1, p2, ...)
	// reverse the current level status if needed
}
```

### 思维要点

1. 不要人肉递归，直接看函数本身开始写即可
2. 找最近重复子问题。用最近最简方法。
3. 数学归纳法（n = 1, 2可；n-1的时候可，n的时候可）

## 分治 Divide & Conquer
> 特殊的递归，本质就是找重复性。
> 
> 很多办法的本质思路就是
> 1. 找重复性
> 2. 分解问题
> 3. 组合每个子问题的结果

### 分治代码模版

```
void divide_conquer(problem, param1, param2, ...) {
	// terminator
	if (problem == NULL) {
		// print result
		return;
	}
	// current level logic
	data = prepare_data(problem);
	subproblems = spilt_problem(problem, data, ...);
	// drill down
	subresult1 = divide_conquer(subproblem[0], param1, param2, ...);
	subresult2 = divide_conquer(subproblem[1], param1, param2, ...);
	subresult3 = divide_conquer(subproblem[2], param1, param2, ...);
	// process and generate the final result
	result = combine_result(subresult1, subresult2, subresult3, ...);
	// reverse current level status if needed
	return;
}
```

## 回溯 Backtracking

> 特殊的递归
> 
> 不断地在每一层去试就行了

// TODO
