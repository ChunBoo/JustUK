def greatestLetter(s):
    """
    :type s: str
    :rtype: str
    """
    #find the largest char
    ss=sorted(s)
    for i in range(len(s)-1,-1,-1):
        if ss[i].upper() in ss and ss[i].lower() in ss:
            return ss[i].upper()
    return ""
print(greatestLetter("AbCdEfGhIjK"))