//Classic graph problem
//Given grid where '1' is land & '0' is water, return # of islands

//converty the matrix in a diamond shape and then use dfs to iterate 
//only when there are 1's , whenever you visit a neighbor 1, mark it 0 (aka visited)
//call dfs until base case aka total range 
//dfs explore all 4 directions 
//Medium Google, Uber fav question 
//200 LC 
//TC O(m*n) for loops
//SC O(m*n) recursion stack may go worst case mai till the end to search for aneighbor
//hence m*n sc
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0 ; 
        for(int i =0 ; i < m ; i++){
            for(int j = 0 ;j < n;j++){
                //call dfs if element is 1
                if(grid[i][j]=='1'){
                dfs(grid, i,j,m,n);
                islands++;}
            }

        }
        return islands;
    }
private:
    void dfs (vector<vector<char>>& grid, int i, int j, int m, int n){
        //base case for dfs 
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        //marking the grid as zero 
        //to ensure =1 wali condn na accept hojaye for nodes we have already visited
        //ow we iterate through 4 directions using dfs

        dfs(grid, i+1, j , m , n);
        dfs(grid, i-1,j,m,n);
        dfs(grid, i,j+1,m,n);
        dfs(grid, i, j-1,m,n);

    }
};