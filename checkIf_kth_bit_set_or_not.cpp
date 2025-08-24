//Approach1 : using brute force convert to binary string then check
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        string s ;
        while( n >0){
            s += (n%2) ?'1':'0';
            n/=2;
        }
        
        if(s[k]=='1' && k < s.size()) return true;
        
        return false;
    }
};

//T.C : O(log2n)
//S.C : O(log2n)

//Approach2 : using left shirt(<<)
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        //using left shift <<
        
        if(n &(1<<k)) return true;
        
        return false;
    }
};

//T.C : O(1)
//S.C : O(1) 

//Approach3 : using right shift (>>)

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        //using right shift
        if((n>>k) & 1)return true;
        
        return false;
    }
};

//T.C : O(1)
//S.C : O(1) 
