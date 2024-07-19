class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0,len=0;
        int l=0,r=0;
        vector<int>hash(256,-1);

        while(r<s.size()){
        if(hash[s[r]]!=-1 && hash[s[r]]>=l){
            l = hash[s[r]]+1;
        }
        len = r-l+1;
        ans = max(ans,len);
        hash[s[r]]=r;
        r++;
        }       
        return ans;      
    }
};