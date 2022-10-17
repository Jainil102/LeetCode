class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(int i=0; i<sentence.length(); i++){
            s.insert(sentence[i]);
        }
        if(s.size() < 26) return false;
        return true;
    }
};