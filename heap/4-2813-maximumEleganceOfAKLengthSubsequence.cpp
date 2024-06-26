/***
 * You are given a 0-indexed 2D integer array items of length n and an integer k.

items[i] = [profiti, categoryi], where profiti and categoryi denote the profit and category of the ith item respectively.

Let's define the elegance of a subsequence of items as total_profit + distinct_categories2, where total_profit is the sum of all profits in the subsequence, and distinct_categories is the number of distinct categories from all the categories in the selected subsequence.

Your task is to find the maximum elegance from all subsequences of size k in items.

Return an integer denoting the maximum elegance of a subsequence of items with size exactly k.

Note: A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order.

 

Example 1:

Input: items = [[3,2],[5,1],[10,1]], k = 2
Output: 17
Explanation: In this example, we have to select a subsequence of size 2.
We can select items[0] = [3,2] and items[2] = [10,1].
The total profit in this subsequence is 3 + 10 = 13, and the subsequence contains 2 distinct categories [2,1].
Hence, the elegance is 13 + 22 = 17, and we can show that it is the maximum achievable elegance. 
Example 2:

Input: items = [[3,1],[3,1],[2,2],[5,3]], k = 3
Output: 19
Explanation: In this example, we have to select a subsequence of size 3. 
We can select items[0] = [3,1], items[2] = [2,2], and items[3] = [5,3]. 
The total profit in this subsequence is 3 + 2 + 5 = 10, and the subsequence contains 3 distinct categories [1,2,3]. 
Hence, the elegance is 10 + 32 = 19, and we can show that it is the maximum achievable elegance.
Example 3:

Input: items = [[1,1],[2,1],[3,1]], k = 3
Output: 7
Explanation: In this example, we have to select a subsequence of size 3. 
We should select all the items. 
The total profit will be 1 + 2 + 3 = 6, and the subsequence contains 1 distinct category [1]. 
Hence, the maximum elegance is 6 + 12 = 7.  
 

Constraints:

1 <= items.length == n <= 105
items[i].length == 2
items[i][0] == profiti
items[i][1] == categoryi
1 <= profiti <= 109
1 <= categoryi <= n 
1 <= k <= n
 */

class Solution {
public:
    using LL=long long;
    using PII=pair<LL,LL>;
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.rbegin(),items.rend());
        LL sum=0;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<k;i++){
            sum+=items[i][0];
            m[items[i][1]].push_back(i);
        }

        LL t=m.size();
        LL ans=sum+t*t;
        priority_queue<PII,vector<PII>,greater<>> pq;

        for(int i=0;i<k;i++){
            pq.push({items[i][0],items[i][1]});
        }
        for(int i=k;i<items.size();i++){
            if(m.find(items[i][1])!=m.end())
                continue;
            while(!pq.empty()){
                auto [profit,cate]=pq.top();
                pq.pop();
                if(m[cate].size()>1){
                    sum-=profit;
                    sum+=items[i][0];
                    t++;
                    m[cate].pop_back();
                    m[items[i][1]].push_back(i);
                    ans=max(ans,sum+t*t);
                    break;
                }
            }
        }
        return ans;
    }
};