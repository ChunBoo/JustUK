"""_summary_
You are given a list of unique strings genes where each element has the same length and 
contains characters “A”, “C”, “G” and/or “T”.
If strings a and b are the same string except for one character, then a and b are in the same mutation group.
If strings a and b are in a group and b and c are in a group, then a and c are in the same group.
Return the total number of mutation groups.

Constraints
n ≤ 10,000
k ≤ 20 where k is the length of a string in genes
Example 1
Input
genes = [“ACGT”, “ACCT”, “AGGT”, “TTTT”, “TTTG”]
Output
2
Explanation
There are two mutation groups:
[“ACGT”, “ACCT”, “AGGT”]
[“TTTT”, “TTTG”]

Hint:
How can we connect one word with another? Is there a better way to connect than simply comparing each pair? After connecting words with each other, return the groups they form.

Human has 23 chromosomes (one of them controls the gender, where XX means girls and XY means boys). Each chromosome has hundreds of genes.

Returns:
    _type_: _description_
"""

from collections import deque


def  findNoGroups(genes):
    g=set(genes)
    
    def bfs(s):
        q=deque([s])
        while(q):
            curGene=q.popleft()
            for i in range(len(curGene)):
                for c in ('A','G','C','T'):
                    newGene=s[:i]+c+s[i+1:]
                    if newGene in g:
                        g.remove(newGene)
                        q.append(newGene)
    
    ans=0
    for gene in genes:
        if gene in g:
            ans+=1
            bfs(gene)
    return ans

    
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(findNoGroups(genes))           
    