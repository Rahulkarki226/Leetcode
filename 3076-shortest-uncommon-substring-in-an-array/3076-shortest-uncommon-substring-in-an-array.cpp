class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) { 
    int n = arr.size(); 
    unordered_multiset<string> substrings; 
 
    for(auto str : arr) { 
        unordered_multiset<string> substringSet; 
        for(int i = 0; i < str.size(); i++) { 
            string temp = ""; 
            for(int j = i; j < str.size(); j++) { 
                temp += str[j]; 
                substringSet.insert(temp); 
                if (substringSet.count(temp) > 1) { 
                    continue; 
                } 
                substrings.insert(temp); 
            } 
        } 
    } 
 
    vector<string> result(n); 
 
    for(int k = 0; k < n; k++) { 
        string str = arr[k]; 
        for(int i = 0; i < str.size(); i++) { 
            string temp = ""; 
            for(int j = i; j < str.size(); j++) { 
                temp += str[j]; 
                if (substrings.count(temp) <= 1) { 
                    if (result[k] == "") result[k] = temp; 
                    else { 
                        if (result[k].size() > temp.size()) { 
                            result[k] = temp; 
                        } else if (result[k].size() == temp.size() && result[k] > temp) { 
                            result[k] = temp; 
                        } 
                    } 
                } 
            } 
        } 
    } 
 
    return result; 
}
};