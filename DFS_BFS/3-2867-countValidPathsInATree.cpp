
/**
 * @brief 我们需要知道一个数是不是质数，可以采用「埃氏筛」来找出范围内所有的质数。关于质数筛选，. 计数质数。

然后我们分别以质数节点为根，用「深度优先搜索」的方式，递归搜索所有的非质数的子树，并求出所有子树的大小，搜索过程中只搜索非质数节点。任何两个来自不同子树的节点，其路径都通过质数根节点，路径上恰好只有根节点一个质数节点，根据题意路径是合法的。我们只需要把所子树大小，两两相乘并求和，就可以得到包含根节点的所有合法路径。

遍历所有质数节点，并且重复上述过程，便可以得到所有合法路径的数目，返回为最终结果。

作者：力扣官方题解
链接：https://leetcode.cn/problems/count-valid-paths-in-a-tree/solutions/2654126/tong-ji-shu-zhong-de-he-fa-lu-jing-shu-m-yyuw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 */
const int N=100001;
bool prime[N];
int init=[](){
    fill(begin(prime),end(prime),true);
    prime[1]=false;
    for(int i=2;i*i<N;++i){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i)
                prime[j]=false;
        }
    }
    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        fill(begin(prime),end(prime),true);
        prime[1]=false;
        for(int i=2;i*i<=n;++i){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<vector<int>> G(n+1);
        for(const auto& e:edges){
            int i=e[0];
            int j=e[1];
            G[i].push_back(j);
            G[j].push_back(i);
        }

        vector<int> seen;
        long long res=0;
        vector<long long> count(n+1,0);
        for(int i=1;i<=n;++i){
            if(!prime[i])
                continue;
            long long cur=0;
            for(int j:G[i]){
                if(prime[j])
                    continue;
                if(count[j]==0){
                    seen.clear();
                    dfs(G,seen,j,0);
                    long long cnt=seen.size();
                    for(int k:seen)
                        count[k]=cnt;
                }   
                res+=count[j]*cur;
                cur+=count[j];
            }
            res+=cur;

        }
        return res;

    }
private:
    void dfs(const vector<vector<int>>& G,vector<int>& seen,int i,int pre){
        seen.push_back(i);
        for(int j:G[i]){
            if(j!=pre&&!prime[j])
                dfs(G,seen,j,i);
        }
    }
};