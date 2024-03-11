class Solution {
public:

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&](vector<int> arr1,vector<int> arr2)
        {
            return arr1[k]>arr2[k];
        });
        return score;
    }
};