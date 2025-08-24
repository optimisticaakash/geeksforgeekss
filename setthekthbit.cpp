//Appraoch 1 : bruteforce
class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        string s;
        while(n> 0){
            s +=(n%2) ? '1':'0';
            n/=2;
        }
        
        if(k >= s.size()){
            s.append(k-s.size()+1 ,'0');
        }
        s[k] ='1';
        
        int len = s.size();
        int p2 = 1; 
        int num = 0;
        //iterate lsb to msb
        for(int i =0; i  < len; i++){
            if(s[i]=='1'){
                num += p2;
            }
            p2 *= 2;
        }
        return num;
        
    }
};

//T.C : O(logn) + O(k) + O(len) = O(max(logn ,k))
//S.C : O(max(logn ,k))

//Approach 2 Using left shirt
class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return n | (1 << k);
    }
};
//T.C : O(1)
//S.C : O(1)
