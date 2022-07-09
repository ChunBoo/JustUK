# given two big numbers as string,return the multiply results

def  multiply(a,b):
    n,m=len(a),len(b)
    ans=[0]*(n+m)
    a=a[::-1]
    b=b[::-1]
    
    for i  in range(n):
        for j in range(m):
            ans[i+j]+=(int)(a[i])*(int)(b[j])
            ans[i+j+1]+=ans[i+j]//10
            ans[i+j]%=10
            
    return ("".join(map(str,ans[::-1]))).lstrip("0")
a="123"
b="456"

print(multiply(a,b))