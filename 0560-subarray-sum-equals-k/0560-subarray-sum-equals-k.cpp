class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prfsum=0,ans=0;
        int n=nums.size();
        unordered_map<int,int> freq;
        freq[0]=1;
        for(int i=0;i<n;i++)
        {
            prfsum+=nums[i];
            if(freq.find(prfsum-k)!=freq.end())
            {
                ans+=freq[prfsum-k];
            }
            freq[prfsum]++;
        }
        return ans;
    }
};