//Approach1 : using brute force 
//generating every subarray 

//Code1 : 
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int cnt = 0;
        for(int i = 0; i < n;i++){
            int XOR = 0;
            for(int j = i; j < n; j++){
                XOR ^= arr[j];
                if(XOR == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//T.C = O(n^2)
//S.C = O(1)

//Approach2 : optimal 
//using concept of prefix xor and hashing
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mpp;
        int xr = 0;
        mpp[xr]++;//(0.1)
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            xr = xr^arr[i];
            //looking for k
            int x = xr^k;
            cnt += mpp[x];//jitni bar x aaya utna cnt badha do 
            mpp[xr]++;
        }
        
        return cnt;
    }
};

//T.C : O(n) //if unordered_map 
//O(nlogn) for map

//T.C : O(n) 
