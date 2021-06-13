
import Foundation

class Solution {
    func reverseWords(_ s: String) -> String {
        let trim = s.trimmingCharacters(in: CharacterSet.init(charactersIn: " "))
        var arr = trim.split(separator: Character.init(" "))
        let count = arr.count
        var newStr = ""
        var i = 0
        for _ in 0..<arr.count {
            if ((Double(i) * 2.0) >= Double(count)) {
                break
            }
            arr.swapAt(i, count - 1 - i)
            newStr += arr[i]
            newStr += " "
            i+=1
        }
        for j in i..<arr.count {
            newStr += arr[j]
            newStr += " "
        }
        if (!newStr.isEmpty) {
            newStr.removeLast()
        }
        return newStr
    }
}