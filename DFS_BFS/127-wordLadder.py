
from collections import deque
def countOfWordLadder(beginWord,endWord,wordList):
    dict=set(wordList)
    l=len(beginWord)

    q=deque()
    q.append(beginWord)
    step=0
    chars=[]
    while not len(q)==0:
        step+=1

        for sz in range(len(q)):
            w=q.popleft()
            for i in range(l):
                ch=w[i]
                for j in range(ord('a'), ord('z')+1):
                    tmp=list(w)
                    tmp[i]=chr(j)
                    w="".join(tmp)
                    # if w=='dot':
                    print(w)
                    if w==endWord:
                        return step+1;
                    if w not in dict:
                        continue
                    dict.remove(w)
                    q.append(w)
                tmp=list(w)
                tmp[i]=ch
                w="".join(tmp)
    return 0


beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

print(countOfWordLadder(beginWord,endWord,wordList))