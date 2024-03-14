class Solution {
public:
    int atmost(vector<int>&nums,int goal)
    {
        int n=nums.size();
        int i=0,j=0,c=0,sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal && i<=j)
            {
                sum-=nums[i];
                i++;
            }
            c+=j-i+1;
            j++;
        }
        return c;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};