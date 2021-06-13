import Foundation

extension String {
   func characterAtIndex(_ index:Int) -> Character! {
       let uni = self.utf16[String.Index(utf16Offset: index, in: self)]
       if let uc = UnicodeScalar(uni) {
           let char = Character(uc)
           return char
       } else {
           return nil
       }
   }

   // Allows us to use String[index] notation
   subscript(index:Int) -> Character! {
       return characterAtIndex(index)
   }
}

class Solution {
   func isIsomorphic(_ s: String, _ t: String) -> Bool {
       if (s.count != t.count) {
           return false
       }
       var i = 0
       var map1:[Character:Character] = [Character:Character]()
       var map2:[Character:Character] = [Character:Character]()
       for se in s {
           let te = t[i]
           if let e = map1[se] {
               if e != te {
                   return false
               }
           }
           else {
               if let e2 = map2[te!] {
                   if e2 != se {
                       return false
                   }
               }
               else {
                   map1[se] = te
                   map2[te!] = se
               }
           }
           i += 1
       }
       return true
   }
}