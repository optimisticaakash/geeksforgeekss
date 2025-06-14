//link : https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//Approach1: bruteforce 

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        //generate all the possible subarray 
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                if(sum == 0){
                    maxlen = max(maxlen , j-i+1);
                }
            }
        }
        
        return maxlen;
    }
};

//T.C : O(n^2)
//S.C : O(1)

//Approach2: optimal 
//using hashing and prefixsum 

//class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int,int> mpp;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0){
                maxlen = i+1;
            }else{
                if(mpp.find(sum) != mpp.end()){
                    maxlen = max(maxlen , i-mpp[sum]);
                }else{
                    mpp[sum] = i;
                }
            }
        }
        return maxlen;
    }
};
//T.C : O(n)
//S.C : O(1)

