//Approach 1 : bruteforce
// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> arr;
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m ; j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        
        sort(arr.begin() , arr.end());
        
        return arr[(m*n)/2];
    }
};

//T.C : O(m*n) + O(m*nlog(m*n)


//approach2 : using binary search// User function template for C++

class Solution {
  public:
    int upperbound(vector<int> &row , int x , int n){
        int low = 0; 
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(row[mid] > x){
                ans = mid;
                high = mid-1;//look for more small index on left
            }else{
                low = mid+1;//look for great
            }
        }
        return ans;
    }
    int blackbox(vector<vector<int>> &mat ,int n , int m,  int x){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upperbound(mat[i] , x , m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int  n = mat.size();
        int m = mat[0].size();
        
        int low = INT_MAX , high = INT_MIN;
        
        for(int i = 0; i < n; i++){
            low = min(low , mat[i][0]);
            high = max(high , mat[i][m-1]);
        }
        
        
        int req = (m*n)/2;
        while(low <= high){
            int mid = (low+high)/2;
            
            int smaller_equals = blackbox(mat , n , m , mid);
            if(smaller_equals <= req){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
//T.C : O (n) + O(log*10^9 * n * logm)
