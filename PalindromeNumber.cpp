class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        double sum = 0;
        if(x<0){
            return false;
        }
            while(x>0){
            int r = x % 10;
            sum = sum * 10 + r;
            x = x/10;
            }
            if(original == sum){
                return true;
            }
            return false;
    }
    
};
