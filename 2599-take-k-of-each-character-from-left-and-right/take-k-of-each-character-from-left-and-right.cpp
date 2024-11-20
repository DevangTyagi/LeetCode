class Solution {
public:
    int takeCharacters(string s, int k) {
      unordered_map<char,int>mpp;
      vector<int> freq(3, 0);
      int maxlen = 0;
      for(char &it : s){
        mpp[it]++;
      } 
      if (mpp['a'] < k || mpp['b'] < k || mpp['c'] < k)
      return -1;
      int i=0,j = 0;
      while(j < s.size()){
       freq[s[j] - 'a']++;
       while(freq[0] > mpp['a'] - k || freq[1] > mpp['b'] - k || freq[2] > mpp['c'] - k){
        freq[s[i] - 'a']--;
        i++;
       }
       maxlen = max(maxlen,j-i+1);
       j++;
      }
      return s.size() - maxlen;
    }
};