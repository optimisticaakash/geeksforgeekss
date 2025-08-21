//approach1 : using recursion
class Solution {
  public:
    int n;
    vector<string> answer;

    void solve( int i , int j ,vector<vector<int>>& maze , string&path){
        //base case
      
        if(i<0 || i >= n || j<0 || j >= n || maze[i][j] == 0){
            return ;
        }
        
        if(i == n-1 && j== n-1){
            answer.push_back(path);
            return;
        }
        
        maze[i][j] = 0;
        //recursion trust
        
        path.push_back('D');//down
        solve(i+1,j,maze,path);
        path.pop_back();
        
        path.push_back('L');//left
        solve(i,j-1,maze,path);
        path.pop_back();
        
        path.push_back('R');//right
        solve(i,j+1,maze,path);
        path.pop_back();
        
        path.push_back('U');//up
        solve(i-1,j,maze,path);
        path.pop_back();
        
      
        
        maze[i][j]=1;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze.size();
         
        if(maze[0][0]==0)return{};
        string path = "";
        
        solve(0 , 0, maze , path);
        
        return answer;
    }
};

//T.C : O(3^(n^2))
//S.C : :O(n^2 + n*n*k)
