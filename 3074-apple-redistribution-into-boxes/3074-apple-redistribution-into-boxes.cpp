class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto x:apple)
        {
            sum+=x;
        }
        sort(capacity.rbegin(),capacity.rend());
        int n=capacity.size();
        for(int i=0;i<n;i++)
        {
            sum-=capacity[i];
            if(sum<=0)
            {
                return i+1;
            }
        }
        return -1;
    }
};