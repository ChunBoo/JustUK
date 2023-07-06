

def isEqualRationalNumbers(s,t):

    def convert(s):
        num=s
        p="("
        if p in s:
            pp=s.find(p)   
            num=s[:pp]       #split the string as substring,likes s.substr()
            r=s[pp+1:-1]
            while len(num)<16:
                num+=r
        return float(num)   #convert the string to double
    return abs(convert(s)-convert(t))<1e-9


# s="0.5(25)"
# t="0.52(52)"
s="0.9(9)"
t="1.000001"
print(isEqualRationalNumbers(s,t))