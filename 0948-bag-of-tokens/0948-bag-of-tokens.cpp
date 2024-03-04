class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int res=0,score=0;
        int i=0,j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                score++;
                res=max(res,score);
                i++;
            }
            else if(score>0)
            {
                score--;
                power+=tokens[j--];
            }
            else
               break;
        }
        return res;
    }
};