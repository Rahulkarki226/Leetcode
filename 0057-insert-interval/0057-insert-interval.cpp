class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int st=newInterval[0],end=newInterval[1];
       int n=intervals.size(),i=0;
       
       vector<vector<int>> ans;
       //first part
       while(i<n && intervals[i][1]<st)
       {
           ans.push_back(intervals[i]);
           i++;
       }

       //merge part
       while(i<n && intervals[i][0]<=end)
       {
         newInterval[0]=min(intervals[i][0],newInterval[0]);
         newInterval[1]=max(intervals[i][1],newInterval[1]);
         i++;
       }
       ans.push_back(newInterval);

       //remaining part

       while(i<n)
       {
        ans.push_back(intervals[i]);
        i++;
       }
       return ans;

        
    }
};