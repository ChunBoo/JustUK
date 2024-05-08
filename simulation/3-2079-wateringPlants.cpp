 int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int mx=capacity;
        for(int i=0;i<plants.size();i++)
        {
            if(plants[i]<=capacity)
            {
                ans++;
                capacity-=plants[i];
            }
            else
            {
                ans+=i;
                capacity=mx;
                ans+=i+1;
                capacity-=plants[i];
            }
        }
        return ans;
    }
};