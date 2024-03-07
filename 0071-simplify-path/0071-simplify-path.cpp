class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        stringstream ss(path);
        string str;
        while(getline(ss,str,'/'))
        {
            if(!dir.empty() && str==".."){
                dir.pop_back();
            }
            else if(str!="" && str!=".." && str!="."){
                dir.push_back(str);
            }
        }
        string ans="";
        for(string s:dir)
        {
            ans+="/"+s;
        }
        return ans.empty()?"/":ans;

        
    }
};