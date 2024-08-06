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
      
      int i=1,count=0;
      for(auto itr : keys)
      {
        if(i>=1 && i<=8) count += itr*1;
        else if(i>=9 && i<=16) count += itr*2;
        else if(i>=17 && i<=24) count += itr*3;
        else count += itr*4;
        i++;
      }
      return count;
    }
};