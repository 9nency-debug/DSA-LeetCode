class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        string str;
        int vacancy = 1;
        while(getline(s, str, ',')){
            if(str == "#"){
                vacancy--;
            }else{
                vacancy++;
            }
            if(vacancy == 0) break;
        }
        if(getline(s, str, ',') || vacancy != 0) return false;
        return true;
    }
};