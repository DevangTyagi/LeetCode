class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>larger;
        int count = 0;
        for(auto itr : nums) {
            if(itr < pivot)
            smaller.push_back(itr);
            else if(itr == pivot)
            count++;
            else
            larger.push_back(itr);
        }
        while(count--){
         smaller.push_back(pivot);
        }
        if(larger.size()!=0)
        smaller.insert(smaller.end(),larger.begin(),larger.end());
        return smaller;
    }
};