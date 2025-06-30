//Approach1: linear Search

class Solution {
  public:
    bool CanWePlace(vector<int> &stalls, int dist , int k){
        int cntCows = 1;
        int LastCow = stalls[0];
        
        for(int i = 1; i < stalls.size() ; i++){
            if(stalls[i] - LastCow >= dist){
                cntCows = cntCows+1;
                LastCow = stalls[i];
            }
            
            if(cntCows >= k) return true; //jaise hi no of cows placed hogyi return true
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin() , stalls.end());
        int n = stalls.size();
        
        int last = stalls[n-1] - stalls[0];
        
        for(int i = 1; i<= last; i++){
            if(CanWePlace(stalls,i,k) == true) continue;
            else{
                return (i-1);
            } 
        }
        //all distances work return the last distance
        return last;
        
    }
};

//T.c : O(nlogn) + O(max-min) * O(n) 
//S.C : O(1) 

//Approach2: using binary search 

class Solution {
  public:
    bool CanWePlace(vector<int> &stalls, int dist , int k){
        int cntCows = 1;
        int LastCow = stalls[0];
        
        for(int i = 1; i < stalls.size() ; i++){
            if(stalls[i] - LastCow >= dist){
                cntCows = cntCows+1;
                LastCow = stalls[i];
            }
            
            if(cntCows >= k) return true; //jaise hi no of cows placed hogyi return true
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin() , stalls.end());
        int n = stalls.size();
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(CanWePlace(stalls,mid,k)==true){
                low = mid+1;//max dhudhne ke liye
            }else{
                high = mid-1;
            }
        }
        return high;
        
    }
};
//T.C ; O(nlogn) + O(n) * O(log(max-min))
//S.C : O(1)
