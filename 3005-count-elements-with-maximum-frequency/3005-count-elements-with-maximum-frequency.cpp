class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int cnt=0;
        int max=0;
        for(auto it:mp)
        {
            if(max<it.second)
            {
                max=it.second;
                cnt=it.second;
            }
            else if(max==it.second)
            {
                cnt+=it.second;
            }
        }
        return cnt;
    }

};