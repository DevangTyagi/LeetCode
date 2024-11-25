class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
      string curr = "";
      for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 3 ; j++){
          curr += to_string(board[i][j]);
        }
      }  
      int level = 0;
      string target = "123450";
      unordered_map<int,vector<int>> mp;
      mp[0] = {1,3};
      mp[1] = {0,2,4};
      mp[2] = {1,5};
      mp[3] = {0,4};
      mp[4] = {1,3,5};
      mp[5] = {2,4};
      queue<string>q;
      unordered_set<string>visited;
      q.push(curr);
      while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            string str = q.front();
            q.pop();
            if(str == target)
            return level;
            int ind_zero = str.find('0');
            for(auto swapidx : mp[ind_zero]){
                string newstr = str;
                swap(newstr[ind_zero],newstr[swapidx]);
                if(visited.find(newstr) == visited.end()){
                    q.push(newstr);
                    visited.insert(newstr);
                }
            }
        }
        level++;
      }
      return -1;
    }
};