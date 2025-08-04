//Approach 1 : 

class Solution {
  public:
    void reverse(stack<int> &St) {
        // code here
        //base case
        if(St.empty()) return;
        
        int top = St.top();
        St.pop();
        
        //Recursion call
        reverse(St);
        
        stack<int> temp;
        while(!St.empty()){
            temp.push(St.top());
            St.pop();
        }
        St.push(top);
        while(!temp.empty()){
            St.push(temp.top());
            temp.pop();
        }
        
    }
};

//T.C : O(n^2)
//S.C  : O(n)

//Approach2 : using another function which insert at bottom 
class Solution {
  public:
    void insertBottom(stack<int> &St , int element){
        //base case
        if(St.empty()){
            St.push(element);
            return;
        }
        
        int top = St.top();
        St.pop();
        
        insertBottom(St , element);
        St.push(top);
    }
    void reverse(stack<int> &St) {
        // code here
        
        //base case
        if(St.empty()) return ;
        
        int top = St.top();
        St.pop();
        
        //recursive call to reverse string
        reverse(St);
        
        //now inserting top element at the bottom
        insertBottom(St , top);
        
    }
};
//T.C : O(n^2:
//S.C : O(1) auxially space 
