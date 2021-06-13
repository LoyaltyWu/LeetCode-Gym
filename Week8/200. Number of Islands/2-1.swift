
import Foundation
// 思路1
// DFS/BFS
// 思路2
// 并查集(Disjoint Set Union)
// 1. create self.parent = self
// 2. union other.parent = self
// 3. findParent
//      node = self
//      travelled = []
//      while (node.parent != node)
//          travelled += node
//          node = node.parent
//      for item in travlled
//          item.parent = node
//      return node

// 并查集思路1
// 1.1 创建并查集, 个个数值为1的点, 都是一个孤岛
// 1.2 统计这些1的个数K
// 2.1 更具关系表, 进行并查集的union, 通过岛屿连通图进行,
// 2.2 每联通两个岛, K-1
// 2.3 返回K
// 并查集思路2
// 1.1 创建并查集, 个个数值为1的点, 都是一个孤岛
// 1.2 同时, 创建各自的头名, 放在一个set里.
// 2.1 更具关系表, 进行并查集的union, 通过岛屿连通图进行
// 2.2 更新连通时, 更新某个岛群的parent时, 将旧parent节点删除.
//class Node {
//    let i:Int
//    let j:Int
//    var parent:Node
//    Node(row, column) {
//        i = row;
//        j = column
//        parent = self;
//    }
//}

class Solution {
    var total:FindUnion = FindUnion()
    let directions = [(0,-1), (-1,0)]
    
    func numIslands(_ grid: [[Character]]) -> Int {
        // 并查集思路1
        guard !grid.isEmpty else {
            return 0
        }
        total = FindUnion(grid.count * (grid.first?.count ?? 0))
        var i = 0
        for row in grid {
            var j = 0
            for e in row {
                if (e == "1") {
                    total.create(getIndex(i, j, row.count))
                    combine(grid, i, j, grid.count, row.count)
                }
                j += 1
            }
            i += 1
        }
        return total.getCount()
    }
    
    // 认为遍历时, 往右和往下的节点是新节点, 会在后续遍历的时候, 通过向左/向上追回到旧的节点.
    func combine(_ grid: [[Character]], _ i:Int, _ j:Int, _ n:Int, _ m: Int) {
        for d in directions {
            let newI = i + d.0
            if (newI < 0 || newI >= n) {
                continue;
            }
            let newJ = j + d.1
            if (newJ < 0 || newJ >= m) {
                continue;
            }
            if (grid[newI][newJ] == "1") {
                // the land in the neighborhood is also belong to the same island.
                total.union(getIndex(i, j, m), getIndex(newI, newJ, m))
            }
        }
    }
    
    func getIndex(_ i:Int, _ j:Int, _ m:Int) -> Int {// 这个位置写错了 x 1, 写成了n
        return i * m + j
    }
}

class FindUnion {
    var parents:[Int] = [Int]()
    private var islands = 0
    
    init(_ maxElements:Int = 0) {
        if (maxElements <= 0) {
            return
        }
        parents = [Int](repeating: 0, count:maxElements)
    }
    
    func create(_ index: Int) {
        guard (0 <= index || index < parents.count) else {
            return;
        }
        parents[index] = index
        islands += 1
    }
    
    func union(_ index:Int, _ other:Int) {
        let otherParent = findParent(other)
        let curParent = findParent(index)
        if (curParent == otherParent) {
            return
        }
        parents[otherParent] = curParent;
        islands -= 1
    }
    
    func findParent(_ index:Int) -> Int {
        // 查父
        var parent = index
        var needShrink = [Int]()
        while (parents[parent] != parent) {
            needShrink.append(parent)
            parent = parents[parent]
        }
        // 查询路径缩短路径
        for needShrinkIndex in needShrink {
            parents[needShrinkIndex] = parent
        }
        return parent
    }
    
    func getCount()->Int {
        return islands;
    }
}
