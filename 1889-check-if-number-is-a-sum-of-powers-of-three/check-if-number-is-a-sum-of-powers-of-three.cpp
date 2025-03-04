class Solution {
public:
    bool checkPowersOfThree(int n) {
        unordered_map<int,int>mpp;
        int main_num = n;
        while(main_num) {
            int num = 1,count =0;
            while(num <= main_num) {
              num *= 3;
              count++;
            }
            if(num >  main_num){
                count--;
                num /= 3;
            }
            if(mpp[count] != 0)
            return false;
            mpp[count]++;
            main_num -= num;
        }
        return main_num == 0;
    }
};