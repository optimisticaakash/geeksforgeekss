//Approach 1 : using  plain recursion 
// User function Template for C++

class Solution {
  public:
    bool isValid(const string&s){
        for(int i = 1; i < s.size(); i++){
            if(s[i] =='1' && s[i-1] == '1')return false;
        }
        return true;
    }
    void stringGenerater(int n , string curr, vector<string>&ans){
        if(curr.size() == n){
            if(isValid(curr))ans.push_back(curr);
            return ;
        }
        
        
        //generate all binary string having last char0
        stringGenerater(n   , curr+"0", ans);
        
        
        //generate all binary string having last char 1
        stringGenerater(n , curr + "1", ans);
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        
        stringGenerater(num , "", ans);
        
        return ans;
    }
};
//T.C : O(2^n * n)
//S.C : O(n) 

//Approach 2: using recursion + pruning
class Solution {
  public:
    void stringGenerater(int n , string curr , char last , vector<string>&ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return ;
        }
        
        
        //choice 1  //hum 0 kb bhi string me add kr ske hai 
        stringGenerater(n   , curr+"0"  , '0' , ans);
        
        
        // choice 2 pr 1 hum string metb hi add kr skte hai jb last char 1 na ho 
        if(last != '1'){
            stringGenerater(n , curr + "1" , '1' , ans);
        }
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        
        stringGenerater(num , "" , '0' , ans);
        
        return ans;
    }
};

//T.C : O(2^n)
//S.C : O(n) 

//Approach 3 : using backtracking

// User function Template for C++

class Solution {
  public:
    //approach 3 : using backtracking
    void stringGenerater(int n , string curr, vector<string>&ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return ;
        }
        
        
        //choice 1  add 0
        curr.push_back('0');
        stringGenerater(n , curr, ans);
        curr.pop_back();
        
        
        //choice 2 , add 1 if last is not 1
        if(curr.empty() || curr.back() != '1'){
            curr.push_back('1');
            stringGenerater(n,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        string curr;//"" empty string hai 
        stringGenerater(num ,curr, ans);
        
        return ans;
    }
};

//Approach 4 : bit manupulation -> jab kr lenge tb aunga

//T.C : O(2^n)
//S.C : O(n)
//jb kr lenge tb kreunga
