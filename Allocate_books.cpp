//Approach1: using linear search 
//code : 

class Solution {
  public:
    int countStudent(vector<int> &arr, int pages){
        int std = 1; 
        int pagesStud = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(pagesStud + arr[i] <= pages){
                pagesStud += arr[i];
            }else{
                std++;
                pagesStud = arr[i];
            }
        }
        return std;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        int minpage = *max_element(arr.begin() , arr.end());
        int sumofpages = accumulate(arr.begin() , arr.end() , 0);
        
        if(arr.size() < k) return -1;
        for(int pages = minpage; pages <= sumofpages; pages++){
            if(countStudent(arr,pages) <= k){
                return pages;
            }
        }
        
        return -1;
        
    }
};

//T.C ; O(n) * O(sum-max+1)

//Approach2: using binary search 
class Solution {
  public:
    int countStudent(vector<int> &arr, int pages){
        int std = 1; 
        int pagesStud = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(pagesStud + arr[i] <= pages){
                pagesStud += arr[i];
            }else{
                std++;
                pagesStud = arr[i];
            }
        }
        return std;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        int minpage = *max_element(arr.begin() , arr.end());
        int sumofpages = accumulate(arr.begin() , arr.end() , 0);
        
        int low = minpage;
        int high = sumofpages;
        
        if(arr.size() < k) return -1;
        while(low <= high){
            int mid = (low + high)/2;
            
            int noOfstudent = countStudent(arr,mid);
            
            if(noOfstudent > k) low = mid+1;
            else high = mid-1;
        }
        return low;
        
    }
};
//T.C : O(log10(sum-max+1)) * O(n) 
