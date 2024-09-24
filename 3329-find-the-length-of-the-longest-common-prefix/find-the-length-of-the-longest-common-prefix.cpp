class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s;
        int maxlen = 0;
        for(auto itr : arr1){
            while(itr>0 && !s.count(itr)){
                s.insert(itr);
                itr/=10;
            }
        }
        for(auto num : arr2){
            while(num>0 && !s.count(num)){
                num/=10;
            }
            if(num > 0)
            maxlen = max(maxlen,int(log10(num)+1));
        }
        return maxlen;
    }
};