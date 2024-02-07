class Solution {
public:
    int arrangeCoins(int n) {
        int count{},temp{n};
        for(int i =0;i<n;i++){
            temp -= i+1;
            if(temp <0){
                return i;
            }    
        }
    return 1;
    }
};