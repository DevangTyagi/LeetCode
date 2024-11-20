class Solution {
public:
    int takeCharacters(string s, int k) {
      unordered_map<char,int>mpp;
      unordered_map<char,int>freq;
      int maxlen = 0;
      for(char &it : s){
        mpp[it]++;
      } 
      if(k == 0)
      return 0;
      if (mpp['a'] < k || mpp['b'] < k || mpp['c'] < k)
      return -1;
      int i=0;
      int j = 0;
      while(j < s.size() && i < s.size()){
       freq[s[j]]++;
       while(freq[s[j]] > mpp[s[j]] - k && i < s.size()){
        freq[s[i]]--;
        i++;
       }
       if(j >= i)
       maxlen = max(maxlen,j-i+1);
       j++;
      }
      return s.size() - maxlen;
    }
};