class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_count=0,ten_count=0,twenty_count=0;
        for(auto itr : bills){
            if(itr == 5) five_count++;
            else if(itr == 10){
                ten_count++;
                if(five_count!=0)
                five_count--;   
                else 
                return false;               
            }
            else 
            {
            twenty_count++;
              if(five_count!=0 && ten_count!=0)  
              { 
                  ten_count--;
                  five_count--;
              }   
              else if(five_count>=3) 
              five_count -= 3;
              else
               return false;  
            }         
        }
        return true;
    }
};