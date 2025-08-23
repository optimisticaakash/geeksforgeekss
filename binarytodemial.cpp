//Approach 

class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int n = b.size();
        
        int p2 = 1;
        int num = 0;
        
        for(int i = n-1; i >= 0; i--){
            if(b[i]=='1'){
                num = num + p2;
            }
            p2 = p2*2;
        }
        
        return num;
    }
};
//T.C : O(n)
//S.C : O(1)
