def captitize(s):
    words=s.split()
    for i ,w in enumerate(words):
        if len(w)<=2:
            words[i]=words[i].lower()
        else:
            words[i]=words[i].title()
    return " ".join(words)


s="eRIC IS rYANS GOOD FRIEND"
print(captitize(s))