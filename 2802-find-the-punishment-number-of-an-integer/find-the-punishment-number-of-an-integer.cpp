class Solution {
public:
    bool Partition_check(string square_num , int target) {
        if(square_num.empty() && target == 0)
        return true;
        if(target < 0)
        return false;
        for(int i=0;i<square_num.size();i++) {
            string left = square_num.substr(0,i+1);
            string right = square_num.substr(i+1);
            int leftnum = stoi(left);
            if(Partition_check(right,target-leftnum))
            return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
       int req_sum = 0;
       for(int i=1;i<=n;i++) {
        int sq_num = i * i;
        if(Partition_check(to_string(sq_num) , i)) 
        req_sum += sq_num;
       } 
       return req_sum;
    }
};