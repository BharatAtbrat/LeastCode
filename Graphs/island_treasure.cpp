class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q ;
        for(int i = 0 ; i < rows; i++){
            for(int j =0 ; j < cols; j++){
                if(grid[i][j]==0){
                    //if there is a wall we add it to queue
                    q.push({i,j});//this is so we can do a bfs
                }
            }
        }

        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        //these are directions for exploring down
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i =0; i<4;i++){
                int x = row + dirs[i][0];
                int y = col + dirs[i][1]; //add different directions 

                if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y] != INT_MAX){
                    continue;//edge cases when out of range, or hit a wall
                }

                grid[x][y] = grid[row][col] + 1;
                q.push({x,y}); //
            }

        }
    }
};
