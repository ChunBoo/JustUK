class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        const int kN=classes.size();
        auto ratio=[&](int i,int deta=0){
            return static_cast<double>(classes[i][0]+deta)/(classes[i][1]+deta);
        };
        priority_queue<pair<double,int>> q;
        for(int i=0;i<kN;++i)
            q.emplace(ratio(i,1)-ratio(i),i);
        
        while(extraStudents--){
            const auto [gain,i]=q.top();
            q.pop();
            ++classes[i][0];
            ++classes[i][1];
            q.emplace(ratio(i,1)-ratio(i),i);
        }
        double ans=0;
        for(int i=0;i<kN;++i)
            ans+=ratio(i);
        return ans/kN;
    }
};