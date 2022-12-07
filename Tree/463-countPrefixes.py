'''
given a string array words and a string s, where words[i] and s comprise only of lowercase English letters. Return the number of strings in words that are a prefix of s. A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

Example 1:
Input: words = [“a","b","c","ab","bc","abc"], s = “abc"
Output: 3
Explanation:
The strings in words which are a prefix of s = “abc" are:
“a", “ab", and “abc".
Thus the number of strings in words which are a prefix of s is 3.

Example 2:
Input: words = [“a","a"], s = “aa"
Output: 2
Explanation:
Both of the strings are a prefix of s.
Note that the same string can occur multiple times in words, and it should be counted each time.
'''

def countPrefixes(words,s):
    ans=0
    for i in words:
        if s.startswith(i):
            ans+=1
    return ans


class Trie:
    def __init__(self):
        self.data = {}
        self.counter = 0
 
    def insert(self, word: str) -> None:
        cur = self
        for i in word:
            if not i in cur.data:
                cur.data[i] = Trie()
            cur = cur.data[i]
        cur.counter += 1
 
    def search(self, word: str) -> bool:
        cur = self
        for i in word:
            if not i in cur.data:
                return False
            cur = cur.data[i]
        return cur.counter > 0
        
    def startsWith(self, prefix: str) -> bool:
        cur = self
        for i in prefix:
            if not i in cur.data:
                return False
            cur = cur.data[i]
        return True  
    
    def count(self, prefix: str) -> int:
        cur = self
        for i in prefix:
            if not i in cur.data:
                return 0
            cur = cur.data[i]
        return cur.counter      

words = ["a","b","c","ab","bc","abc"]
s = "abc"
print(countPrefixes(words,s))