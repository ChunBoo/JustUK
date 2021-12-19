

s="Hi,world"
def reverseWords(s):
    return ",".join(s.split(",")[::-1])


newS=reverseWords(s);
print(newS)