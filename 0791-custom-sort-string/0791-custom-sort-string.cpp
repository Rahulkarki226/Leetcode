class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> map;
        int n=order.size();
        for(int i=0;i<n;i++)
        {
            map[order[i]]=i;
        }
        sort(s.begin(),s.end(),[&](char a,char b)
        {
            return map[a]<map[b];
        });
        return s;
    }
};