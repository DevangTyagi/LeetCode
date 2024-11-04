class Solution {
public:
    string compressedString(string word) 
    {
      string comp = "";
      int size = word.size();
      int i=0;
      while(i < size){
       int count = 0;
       char c = word[i];
       while(i<size && count<9 && word[i]==c){
        count++;
        i++;
       }
        comp += to_string(count) + c;
      }
      return comp;
    }
};