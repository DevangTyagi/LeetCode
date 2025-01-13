class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mpp;
        int minlen = 0;
        for(char &ch : s)
            mpp[ch]++;
        for(auto itr : mpp){
            int freq = itr.second;
            if(freq > 3 && freq%2 ==0)
            minlen = minlen+2;
            else if(freq >= 3 && freq%2 !=0)
            minlen = minlen+1;
            else
            minlen = minlen + freq;
        }
        return minlen;
    }
};