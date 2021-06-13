import Foundation

class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        if (s.count != t.count) {
            return false
        }
        let sArr = Array(s)
        let tArr = Array(t)
        let stMap = [Character:Character]()
        let tsMap = [Character:Character]()
        let totalCase = [(sArr, tArr, stMap), (tArr, sArr, tsMap)]
        for var theCase in totalCase {
            var i = 0
            for se in theCase.0 {
                if let ste = theCase.2[se] {
                    if (theCase.1[i] != ste) {
                        return false
                    }
                }
                else {
                    theCase.2[se] = theCase.1[i]
                }
                i += 1
            }
        }
        return true
    }
}
