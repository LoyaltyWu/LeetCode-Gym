// 重新默写了下BFS, DFS
// 1. BFS
// BFS(Node node) {
//     var queue = Queue()
//     queue.insert(node)
// while(queue.isNotEmpty()) {
//     let cur = queue.pop()
//     // process cur
//     visit(cur)
//     var nextLevelNodes = cur.children
//     queue.insert(nextLevelNodes)
// }
// }
// 2. DFS
// DFS(Node node) {
//     visit(node);
//     if (node.nochildren) {
//         return;
//     }
//     if (node.children.isNotEmpty) {
//         for (var child in children)
//             DFS(child);
//     }
// }
// 没通过
// class Solution {
//   public:
//     int ladderLength(string beginWord, string endWord,
//                      vector<string> &wordList) {

//         set<string> wordSet;
//         for (int i = 0; i < wordList.size(); i++) {
//             wordSet.insert(wordList[i]);
//         }
//         return ladderLengthBFS(beginWord, endWord, wordList, wordSet);
//     }

//     int ladderLengthBFS(string beginWord, string endWord,
//                         vector<string> &wordList, set<string> wordSet) {
//         // void bfs(Node * root) {
//         //       map<int, int> visited;
//         //       if (!root) return;
//         //       queue<Node *> queueNode;
//         //       queueNode.push(root);
//         //       while (!queueNode.empty()) {
//         //             Node *node = queueNode.top();
//         //             queueNode.pop();
//         //             if (visited.count(node->val)) continue;
//         //             visited[node->val] = 1;
//         //             for (int i = 0; i < node->children.size(); ++i) {
//         //                     queueNode.push(node->children[i]);
//         //         }
//         //     }
//         // }
//         set<string> visited;
//         queue<string> queueNodes;
//         queueNodes.push(beginWord);
//         int result = 0;
//         while (!queueNodes.empty()) {
//             result++;
//             string node = queueNodes.back();
//             queueNodes.pop();
//             if (visited.find(endWord) != visited.end()) {
//                 return result;
//             }
//             if (visited.find(node) != visited.end()) {
//                 continue;
//             }
//             visited.insert(node);
//             for (int i = 0; i < node.size(); i++) {
//                 char c = node[i];
//                 for (int j = 0; j < 26; j++) {
//                     if ('a' + j == c) {
//                         continue;
//                     }
//                     string newT = string(node);
//                     newT = newT.replace(i, 1, string(1, c));
//                     bool exist = wordSet.find(newT) != wordSet.end();
//                     bool visited2 = visited.find(newT) != visited.end();
//                     if (exist && !visited2) {
//                         queueNodes.push(newT);
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };