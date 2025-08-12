//Appraoch 1 : using recurison 

void insertINstack(stack<int> &s , int x){
    if(s.empty() || s.top() <= x){//agar stack empty hai ya current top element 
    //x se small hai to , push x 
    s.push(x);
    return;
    }
    //agar uper wala case nhi hai toh 
    int temp = s.top();
    s.pop();

    insertINstack(s , x);

    s.push(temp);
}
void SortedStack ::sort() {
    // Your code here
    
    //base case 
    if(s.empty()) return;
    
    int top_element = s.top();
    s.pop();
    
    SortedStack ::sort();
    insertINstack(s , top_element);
    
    
}

//T.C : O(n2) 
//S. C: :O(n) 


//Approach 2 : using another stack 
//1.⁠ ⁠first stack s , isse top element ko top me save krke s se nikal denge
// 2.⁠ ⁠2nd stack lets say tempst agar empty hai to usme push krdenge  top ko
//⁠ ⁠ye hum loop me kr rhe hai jb tk s empty na ho jaye
//3 . phir agar tempst.top me jo element hai agar woh top element se bada hai tb tk hum tempst.top ko s me push krte rhenge ye bhi loop me chalegaa
//or agar topelement > tempst.top se to use tempst me push kre denge siimple
void SortedStack ::sort() {
    // Your code here
    stack<int> tempst;
    
    while(!s.empty()){
        int top_element = s.top();
        s.pop();
        
        
        while(!tempst.empty() && tempst.top() > top_element ){
            s.push(tempst.top());
            tempst.pop();
        }
        
        tempst.push(top_element);
        
        
    }
    
    s = tempst;
}
//T.C : O(n2) 
//S.C : O(n) 
