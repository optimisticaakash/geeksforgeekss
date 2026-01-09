//Approach 1 : bruteforce
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        int mini = INT_MAX;
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] < mini ){
                mini = arr[i];
                cnt = i;
            }
        }
        
        return cnt;
    }
};


//T.C : O(N)

//Approach 2 : binary search
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        int l = 0;
        int r = n-1;
        
        while(l < r){
            int mid = l + (r-l)/2;
            
            if(arr[mid] < arr[r]){
                r = mid;
            }else if(arr[mid] > arr[r]){
                l = mid+1;
            }
        }
        
        return l;//or we can return r
    }
};

//T.C : O(logn)
//S.C : O(1) 
