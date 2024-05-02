class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n=quality.size();
        int sumQ=0;

        vector<int> h(n);
        iota(h.begin(),h.end(),0);
        ranges::sort(h,[&](int x,int y){return wage[x]*quality[y]<wage[y]*quality[x];});

        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(quality[h[i]]);
            sumQ+=quality[h[i]];
        }

        double ans=sumQ*((double)wage[h[k-1]]/quality[h[k-1]]);
        for(int i=k;i<n;i++){
            int q=quality[h[i]];
            if(q<pq.top()){
                sumQ-=pq.top()-q;
                pq.pop();
                pq.push(q);
                ans=min(ans,sumQ*((double)wage[h[i]]/q));
            }
        }
            return ans;

    }
};