class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int count = 0;
        queue<int>q;        
        for(auto &itr : nums){
        mpp[itr]++;
        q.push(itr);
        }
        if(mpp.size() == nums.size())
        return 0;
        while(!q.empty()){
            int size = (q.size() < 3) ? q.size() :3;
            for(int i=0;i<size;i++){
                int top = q.front();
                q.pop();
                mpp[top]--;
                if(mpp[top] == 0)
                mpp.erase(top);
            }
            count++;
            bool true_map = true;
            for(auto itr : mpp){                
                if(itr.second > 1)
                {
                 true_map = false;
                 break;
                }
            }
            if(true_map)
            break;
        }
        return count;
    }
};