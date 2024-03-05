class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0,i=0,n=pushed.size();

        while(i<n)
        {
            // matched
            if(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else // not match
            {
                st.push(pushed[i]);
                i++;
            }
        }

        while(!st.empty())
        {
            if(st.top()!=popped[j])
               return false;
            
            j++;
            st.pop();
        }
        return true;
    }
};