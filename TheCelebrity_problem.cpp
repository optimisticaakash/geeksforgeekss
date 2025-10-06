//Approach1 : using arrays
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> knowMe(n , 0);
        vector<int> Iknow(n , 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i!= j && mat[i][j] == 1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(knowMe[i] == n-1 && Iknow[i] == 0){
                return i;
            }
        }
        
        return -1;
    }
};

//T.C : O(2N)
//S.C :O(N2)

//Approach2: using two pointer
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        int top = 0;
        int down = n-1;
        
        while(top < down){
            if(mat[top][down] == 1){
                top= top+1;
            }else if(mat[down][top] == 1){
                down = down-1;
            }else{
                top=top+1;
                down= down-1;
            }
        }
        
        if(top > down) return -1;
        
        for(int i = 0; i < n; i++){
            if(i == top) continue;
            
            if(mat[top][i] == 0  && mat[i][top] == 1);//its okay keep checking
            
            else return -1;
        }
        
        return top;
    }
};

//T.C :O(2N)
//S.C :(1)

//Approach3 : using single  variable 
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int celebrity = 0;
        
        //find potential candidate
        for(int i = 0; i < n; i++){
            if(mat[celebrity][i] == 1) celebrity = i;
        }
        
        //verify the candidate
        for(int i = 0; i < n; i++){
            if( i != celebrity){
                if(mat[celebrity][i] == 1 || mat[i][celebrity] == 0){
                    return -1;
                }
            }
        }
        
        return celebrity;
    }
};
//T.C :O(2N)
//S.C ::O(1)

//Approach4 : using stack
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        
        for(int i = 0; i < n;i++){
            st.push(i);
        }
        
        while(st.size() > 1){//jbtk  minimum 1 pair hai loop chlate rhenge
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(mat[i][j] == 0){
                st.push(i);
            }else{
                st.push(j);
            }
        }
        
        
        int candidate = st.top();
        
        for(int i = 0; i < n;i++){
            if((i!= candidate) && (mat[i][candidate] == 0 || mat[candidate][i] == 1)){
                return -1;
            }
        }
        
        return candidate;
    }
};
//T.C :O(3n)
//S.C :O(N)
