class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        if(n == 1)
        return events[0][0];
        int time = events[0][1];
        int minindex = events[0][0];
        for(int i=1;i<n;i++){
            if(events[i][1]-events[i-1][1] > time){
                    time = events[i][1]-events[i-1][1];
                    minindex =  events[i][0];               
                }
            if(events[i][1]-events[i-1][1] == time && events[i][0] < minindex){
                    minindex =  events[i][0];               
                }
        }
        return minindex;
    }
};