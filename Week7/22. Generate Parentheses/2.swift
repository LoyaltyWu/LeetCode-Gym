class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
        return generateParenthesisImpl(n, "", 0,0)
    }

    func generateParenthesisImpl(_ n: Int, _ text: String, _ left: Int, _ right:Int) -> [String] {
        var result:[String] = [String]()
        if (n <= 0) {
            return [""]
        }
        if (left<n) {
            result += generateParenthesisImpl(n, text+"(", left + 1, right)
        }
        if (left>right) {
            result += generateParenthesisImpl(n, text+")", left, right + 1)
        }
        if (left == n && right == n) {
            return [text]
        }
        return result
    }
}