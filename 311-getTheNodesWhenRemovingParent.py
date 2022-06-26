from collections import defaultdict
from email.policy import default
from xml.dom.minidom import Childless


def kill(N,P,K):
    children=defaultdict(list)
    for c,p in zip(N,P):
        children[p].append(c)
    def dfs(root):
        ans=[root]
        for i in children[root]:
            ans+=dfs(i)
        return ans
    
    
    