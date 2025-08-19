//Approach1 : ek array bana kr jisme hum subset store kr rhe hai last me usme loop kr lenge
class Solution {
  public:
  void solve(int i , vector<int> &arr,   vector<int>&temp ,vector<int>&answer){
      if(i == arr.size()){
          int sum = 0;
          for(int i : temp){
              sum += i;
          }
          answer.push_back(sum);
          return ;
      }
      
      //pick case
      temp.push_back(arr[i]);
      solve(i+1 , arr , temp , answer);
      temp.pop_back();
      
      //not pick case
      solve(i+1 , arr , temp , answer);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>answer;
        vector<int>temp;
        
        solve(0 , arr ,temp , answer);
        
        return answer;
    }
};

//T.C : O(2^n * k)
//S.C : O(n) + O(2^n*k)

//Approach2 : sum ko parameter me pass krkeclass Solution {
  public:
  void solve(int i , vector<int> &arr,int sum,vector<int>&answer){
      if(i == arr.size()){
          answer.push_back(sum);
          return ;
      }
      
      //pick case
      solve(i+1 , arr , sum + arr[i], answer);
      
      //not pick case
      solve(i+1 , arr , sum , answer);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>answer;
    
        int sum = 0;
        solve(0 , arr ,sum , answer);
        
        return answer;
    }
};
//T.C : O(2^n)
//S.C : O(n) + o(2^n) -> itne sum ko store krne ke liye array 
