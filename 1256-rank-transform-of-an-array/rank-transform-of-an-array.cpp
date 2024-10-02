class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int>ans;
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>s;
        int i=1;
        for(auto it : temp){
          if(s.find(it)==s.end()){
            s[it]=i;
            ++i;
          }
        }
        for(auto itr : arr){
          ans.push_back(s[itr]) ;
        }
        return ans;
    }
};