#runLength method for decompressing 
def  runLength(s):
    if not s:
        return None
    data=[]  #for store the [2,"a",3,"b"]
    c=0      #for count the number
    for i in s:
        if i.isdigit():
            c+=c*10+int(i)
        else:
            data.append(c)
            data.append(i)
            c=0
    
    return "".join(data[i]*data[i+1] for i in range(0,len(data),2))


s="12a3b4c5d6e"

print(runLength(s))