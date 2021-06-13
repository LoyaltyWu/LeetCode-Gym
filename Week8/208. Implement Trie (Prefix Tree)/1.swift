
import Foundation
class Node {
    var isEnd = false;
    var children:[Character:Node] = [Character:Node]()
    init(_ end:Bool = false) {
        isEnd = end
    }
}
// 26叉树
class Trie {
    private var root = Node()
    /** Initialize your data structure here. */
    init() {
        root = Node()
    }
    
    /** Inserts a word into the trie. */
    func insert(_ word: String) {
        var index = 0
        let lastIndex = word.count - 1
        var cur = root
        for e in word {
            let isEnd = (index == lastIndex)
            if let curChild = cur.children[e] {
                if (isEnd) {
                    curChild.isEnd = true
                }
                cur = curChild
            }
            else {
                let newNode = Node(isEnd)
                cur.children[e] = newNode
                cur = newNode
            }
            index += 1
        }
    }
    
    /** Returns if the word is in the trie. */
    func search(_ word: String) -> Bool {
        var index = 0
        let lastIndex = word.count - 1
        var cur = root
        var found = false
        for e in word {
            let isEnd = (index == lastIndex)
            if let curChild = cur.children[e] {
                if (isEnd) {
                    if (curChild.isEnd) {
                        found = true
                    }
                }
                cur = curChild
            }
            else {
                found = false// 这里最开始写反了.
                break;
            }
            index += 1
        }
        return found
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    func startsWith(_ prefix: String) -> Bool {
        var index = 0
        let lastIndex = prefix.count - 1
        var cur = root
        var found = false
        for e in prefix {
            let isEnd = (index == lastIndex)
            if let curChild = cur.children[e] {
                if (isEnd) {
                    found = true
                }
                cur = curChild
            }
            else {
                found = false
                break;
            }
            index += 1
        }
        return found
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie()
 * obj.insert(word)
 * let ret_2: Bool = obj.search(word)
 * let ret_3: Bool = obj.startsWith(prefix)
 */
