    """_summary_
    Given a string, return true if it's substrings are all palindromes with length of odd
    Returns:
        _type_: _description_
    """

def  check(s):
    n=len(s)
    for i in range(1,n):
        if s[i]==s[i-1]:   #if there are two chars are same,then it is impossible to have odd palindromes
            return False
    return True


s="racecar"
s1="noon"
print(check(s1))