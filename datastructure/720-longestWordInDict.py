def longestWordInDict_Sorting(words):
    words=sorted(words,key=lambda x:,reverse=True)
    d=set(words)
    for w in words:
        isValid=True
        prefix=""
        for i in range(len(w)):
            prefix+=w[i]
            if prefix not in d:
                isValid=False
                break
        if isValid:
            return w
    return ""

def longestWordInDict(words):
    longest=""
    d=set(words)
    for w in words:
        if len(w)<len(longest) or (len(w)==len(longest) and w>longest):
            continue
        isValid=True
        prefix=""
        for i in range(len(w)):
            prefix+=w[i]
            if prefix not in d:
               isValid=False
               break
        if isValid:
            longest=prefix
    return longest

words1 = ["w","wo","wor","worl","world"]
words = ["a","banana","app","appl","ap","apply","apple"]
# print(longestWordInDict(words))
print(longestWordInDict_Sorting(words))