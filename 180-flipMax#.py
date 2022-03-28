def flipMax(n):
    arr=list(str(n))
    for i in range(len(arr)):
        print(type(i),i)
        if(arr[i]<"3"):
            arr[i]="3"
            break;
    return int(''.join(arr))


res=flipMax(323)
print(res)