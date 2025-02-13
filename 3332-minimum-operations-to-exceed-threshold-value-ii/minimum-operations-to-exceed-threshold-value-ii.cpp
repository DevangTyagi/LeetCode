class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<long long, vector<long long> , greater<long long>> pq;
        for(auto &itr : nums) 
        pq.push(itr);
        while(!pq.empty() && pq.size() >= 2 && pq.top() < k) {
            long long smallest_1 = pq.top();
            pq.pop();
            long long smallest_2 = pq.top();
            pq.pop();
            count++;
            long long new_ele = min(smallest_1,smallest_2)*2 + max(smallest_1,smallest_2);
            pq.push(new_ele);
        }
        return count;
    }
};