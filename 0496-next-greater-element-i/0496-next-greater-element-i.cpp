class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(!st.empty())
                mp[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }

        n=nums1.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums1[i])==mp.end())
                  ans[i]=-1;
            else
                ans[i]=mp[nums1[i]];
        }
        return ans;

    }
};