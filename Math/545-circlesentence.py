class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words=sentence.split(" ")
        chars=set()
        # singleCnt=0
        n=len(words)
        words.append(words[0])
        for i in range(n):
            if words[i][-1].upper!=words[(i+1)][0].upper:
                return False
    
        return True