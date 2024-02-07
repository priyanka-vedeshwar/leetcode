class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c ==1){
            return true;
        }
        int beg =0, end = sqrt(c);
        while(beg <= end){
            long long int sum = (long long)(beg*beg)+(long long)(end*end);
            if (sum == (long long)c){
                return true;
            }else if (sum < (long long)c){
                beg++;
            }else{
                end--;
            }
        }
        return false;
    }
};