class Solution {
public:
    int minimumPushes(string word) 
    {
      vector<int>keys(26,0);
      for(auto ch : word)
      {
        keys[ch-'a']++;
      }
      sort(keys.begin(),keys.end(),greater<int>());
      
      int i=0,count=0;
      for(auto itr : keys)
      {
        if(i>=0 && i<=7) count += itr*1;
        else if(i>=8 && i<=15) count += itr*2;
        else if(i>=16 && i<=23) count += itr*3;
        else count += itr*4;
        i++;
      }
      return count;
    }
};