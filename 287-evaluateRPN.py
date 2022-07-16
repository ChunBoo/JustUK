from cProfile import label


def evalRPN(arr):
    st=[]
    opers={
        "+": lambda a,b:a+b,
        '-':lambda a,b:a-b,
        '*':lambda a,b:a*b,
        '/':lambda a,b:a//b,
    }
    for e in arr:
        if e in opers:
            n2=st.pop()
            n1=st.pop()
            st.append(opers[e](int(n1),int(n2)))
        else:
            st.append(e)
    return st.pop()

arr=["1","2","+","3","*"]
print(evalRPN(arr))