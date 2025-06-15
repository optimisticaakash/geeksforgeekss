//Approach 1 : using two pointer 
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        vector<int> ans;
        int left = 0;
        int right = 0;
        
        while(left < n && right < m){
            if(a[left] <= b[right]){
                ans.push_back(a[left]);
                left++;
            }else{
                ans.push_back(b[right]);
                right++;
            }
        }
        
        while(left < n){
            ans.push_back(a[left]);
            left++;
        }
        
        while(right < m){
            ans.push_back(b[right]);
            right++;
        }
        
        for(int i = 0; i < ans.size() ; i++){
            if(i < n){
                a[i] = ans[i];
            }else{
                b[n-i] = ans[i];
            }
        }
        
        return ;
    }
};
//T.C = O(n+m) + O(n+m)
//S.C = O(n+m)

//Approach 2 : optimal (without using extra space 
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        int left = n-1;
        int right = 0;
        
        while( left >= 0 && right < m){
            if(a[left] > b[right]){
                swap(a[left] , b[right]);
                left--;
                right++;
            }else{
                break;
            }
        }
        
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
    }
};

//T.C : O(min(n, m)) + O(nlogn) + O(mlogm) 
//S.C : O(1)

//Appraoch 3 :optimal using gap method 

class Solution {
  public:
  
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2 , int ind1 , int ind2){
        if(arr1[ind1] > arr2[ind2]){
            swap(arr1[ind1] , arr2[ind2]);
        }
    }
    void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        // code here
        //Gap method
        
        int n = arr1.size();
        int m = arr2.size();
        int len = n+m;
        int gap = (len/2) + (len%2);
        while(gap > 0){
            int left = 0;
            int right = left+gap;
            while(right < len){
                //arr1 and arr2
                if(left < n && right >= n){
                    swapIfGreater(arr1 , arr2 , left , right -n);
                }
                //arr2 and arr2
                else if(left >= n){
                    swapIfGreater(arr2 , arr2 , left-n, right -n);
                }
                //arr1 and arr1
                else{
                    swapIfGreater(arr1 , arr1 , left , right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
    }
};

//T.C : O(log2(n+m) + O(m+n)
//S.C : O(1) 

