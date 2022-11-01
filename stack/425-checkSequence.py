


def checkSequence(popped,pushed):
    st=[]
    i=0
    for n in pushed:
        st.append(n)
        while st and i<len(popped) and st[-1]==popped[i]:
            i+=1
            st.pop()
    return not st or len(st)==0 or i==len(popped)

popped=[5,4,3,2,1]
pushed=[1,2,3,4,5]

print(checkSequence(popped,pushed))
    