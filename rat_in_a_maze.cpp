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

//Appraoch 2 : 
class Solution {
  public:
    int n;
    vector<string> answer;
    vector<pair<pair<int,int>, char>> directions = {
            {{1,0}, 'D'},  // Down
            {{0,-1}, 'L'}, // Left
            {{0,1}, 'R'},  // Right
            {{-1,0}, 'U'}  // Up
        };

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
        
        for(auto dir: directions){
            int new_i = i+dir.first.first;
            int new_j = j+dir.first.second;
            
            
            if(new_i >= 0 && new_i <n && new_j >= 0 && new_j < n && maze[new_i][new_j] == 1){
                path.push_back(dir.second);
                solve(new_i , new_j , maze , path);
                path.pop_back();
            }
        }
      
        
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

//Time Complexity: O(4^(n*n)) (exponential, backtracking)

//Space Complexity: O(n*n + k*n) (recursion + storing paths)
