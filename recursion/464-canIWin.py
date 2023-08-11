

def canIWin(M,T):
    sum_=(M+1)*M//2
    if sum_<T:
        return False
    if T<=0:
        return True
    m_=[0]*(1<<M)
    
    def canWin(m,t,state):
        if t<=0:
            return False
        if m_[state]:
            return m_[state]==1
        
        for i in range(m):
            if state&(1<<i):
                continue
            nxtSel=state|(1<<i)
            if not canWin(m,t-(i+1),state|(1<<i)):
                m_[state]=1
                return True
        
        m_[state]=-1
        return False

    return canWin(M,T,0)

print(canIWin(3,2))