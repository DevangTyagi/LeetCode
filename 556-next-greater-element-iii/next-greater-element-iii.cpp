class Solution {
public:
    int nextGreaterElement(int num) 
    {
        long long n = num;
        stack<long long>S;
        vector<long long>temp;
        long long rem;
        if(n==INT_MAX) return -1;
        while(n)
        {
            rem = n%10;
            n=n/10;            
            if(!S.empty() && rem<S.top())
            {
                while(!S.empty())
                {
                    temp.push_back(S.top());
                    S.pop();
                }
                break;
            }
            S.push(rem);
        }
        if(temp.empty()){
            return -1;
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            if(temp[i]>rem)
            {
                long long tem_ele=temp[i];
                temp[i]=rem;
                rem=tem_ele;
                break;
            }
        }
        sort(temp.begin(),temp.end());
        n=n*10+rem;
        for(int i=0;i<temp.size();i++)
        {
        if(n*10+temp[i]>INT_MAX) return -1;
          n=n*10+temp[i];  
        }
        return int(n);
    }
};