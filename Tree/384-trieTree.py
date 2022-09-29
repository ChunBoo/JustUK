


class Trie():
    def __init__(self):
        self.words={}
        self.isWord=False
    
    def insert(self,word):
        root=self
        for w in word:
            if w not in root.words:
                root.words[w]=Trie()
            root=root.words[w]
        root.isWord=True
    
    
    def dfs(self,word,root=None):
        if not root:
            root=self
        for i, w in enumerate(word):
            if w=="?":
                for n in root.words:
                    if dfs(word[i+1:],root.words[n]):
                        return True
                return False
    def search(self,word):
        root=self
        for w in word:
            if w not in root.words:
                return False
            root=root.words[w]
        return root.isWord
    
    def searchPrefix(self,word):
        root=self
        for w in word:
            if w not in root.words:
                return False
            root=root.words[w]
        return True