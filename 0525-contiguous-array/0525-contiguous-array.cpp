class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefSum=0,ans=0;
        unordered_map<int,int> firOc{{0,-1}};
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefSum+=nums[i]==1?1:-1;
            if(firOc.count(prefSum)) ans=max(ans,i-firOc[prefSum]);
            else  firOc[prefSum]=i;
        }
        return ans;
    }
};