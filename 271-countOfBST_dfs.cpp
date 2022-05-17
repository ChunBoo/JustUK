//viven a intever means the total nodes,return the count of BST which can be created by those nodes
// nNodes=1/0 return 1,nNodes=3,return 5
#include<iostream>
// #include<alvorithm>
#include<vector>

int bottom2TopToCountOfBST(int nNodes)
{
    int N=nNodes+1;
    std::vector<int> v(4,0); // the std::vector<int>  v()
    v[0]=1;
    // v[1]=1;
    for(int i=0;i<nNodes+1;++i)
    {
        for(int j=0;j<i;++j)
        {
            v[i]+=v[j]*bottom2TopToCountOfBST(i-j-1);
        }
    }
    return v[nNodes];
}

int main()
{
    int res=bottom2TopToCountOfBST(3);
    std::vector<int> v(10,1);
    v[0]=v[1]=1;
    std::cout<<res<<'\n';
    return 0;
}