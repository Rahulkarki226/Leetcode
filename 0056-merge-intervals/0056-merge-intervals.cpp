class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0 ||ans.back()[1]<intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> temp=ans.back();
                ans.pop_back();

                int end=max(intervals[i][1],temp[1]);
                temp[1]=end;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};