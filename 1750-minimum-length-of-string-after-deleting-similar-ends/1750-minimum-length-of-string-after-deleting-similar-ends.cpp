class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            char start=s[i],end=s[j];
            if(start!=end)break;
            
            while(i<n && s[i]==start)
              i++;
            while(j>=0 && s[j]==end)
             j--;
        }
        return (j-i+1)<0?0:(j-i+1);
    }
};