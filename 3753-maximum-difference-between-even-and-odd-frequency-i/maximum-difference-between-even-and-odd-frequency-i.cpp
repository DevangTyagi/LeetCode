class Solution {
public:
    int maxDifference(string s) {
        int maxodd = INT_MIN;
        int mineven = INT_MAX;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++) {
            mpp[s[i]]++;
        }
        for(auto &it : mpp) {
            if(it.second % 2 != 0 && it.second > maxodd)
            maxodd = it.second;
            if(it.second % 2 == 0 && it.second < mineven)
            mineven = it.second;
        }
        return maxodd - mineven;
    }
};