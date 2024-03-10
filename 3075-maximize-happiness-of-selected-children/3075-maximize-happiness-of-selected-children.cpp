class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        int n=hap.size();
        long long sum=0;
        sort(hap.rbegin(),hap.rend());
        int c=0;
        for(int i=0;i<k;i++)
        {
            int num=hap[i]-c;
            if(num<=0)
                 return sum;
            sum+=num;
            c++;
            
        }
        return sum;
        
    }
};