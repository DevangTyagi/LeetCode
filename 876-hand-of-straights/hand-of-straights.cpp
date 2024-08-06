class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size()%groupSize != 0)
        return 0;
        map<int,int>mpp;
        for(auto itr : hand)
        {
          mpp[itr]++;
        }
        while(!mpp.empty())
        {
          int curr = mpp.begin()->first;
          for(int i=0;i<groupSize;i++)
          {
            if(mpp[curr+i]==0)
            return false;

            mpp[curr+i]--;

            if(mpp[curr+i]==0)
            mpp.erase(curr+i);
          }
        }
        return true;
    }
};