#include <map>
#include <unordered_map>
#include <set>

class NumberContainers {
public:
     unordered_map<int, int> indexToNumber; 
     unordered_map<int, std::set<int>> numberToIndices; 

    NumberContainers() {

    }

    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) == numberToIndices.end() || numberToIndices[number].empty()) {
            return -1;
        }
        return *numberToIndices[number].begin();
    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */