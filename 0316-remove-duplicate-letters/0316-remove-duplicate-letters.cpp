class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastInd(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            lastInd[s[i]-'a']=i;
        }

        vector<bool> seen(26,false);
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            int ind=s[i]-'a';
            if(seen[ind]==true)
               continue;
            while(!st.empty() && st.top()>s[i] &&
             i<lastInd[st.top()-'a'])
             {
                 seen[st.top()-'a']=false;
                 st.pop();
             }
            st.push(s[i]);
            seen[ind]=true;
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};