class Solution {
public:
    bool isPalindrome(string s,int st,int end)
    {
        while(st<=end)
        {
            if(s[st++]!=s[end--])
                return false;
        }
        return true;
    }
    void partitionUtil(int ind,string s,vector<string>&path,
    vector<vector<string>> &res)
    {
        if(ind==s.size())
        {
            res.push_back(path);
            return ;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(s,ind,i))
            {
                path.push_back(s.substr(ind,i-ind+1));
                partitionUtil(i+1,s,path,res);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partitionUtil(0,s,path,res);
        return res;
    }
};