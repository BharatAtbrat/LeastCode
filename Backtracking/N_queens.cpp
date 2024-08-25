//Hard FB (fb is notorious for difficult questions apparently)

//TC O(n*n) or O(n!)
//SC O(n^2) 2d grid vector based to max n^2 

/* Logic: place in diff rows 
now place in one of the n cols and check if col + posDiagt+ negDiag 
are different than the already stored in set, set stores the previous queen ke 
posdiag and negdiag. 
Then do the std backtracking by checking each row (row+1 ) when exploring 
recursively 
*/

class Solution {
private:
    unordered_set<int> cols; //for columns 
    unordered_set<int> posDiag; //for +ve diag R+C
    unordered_set<int> negDiag; //for -ve diag R-C constant

void backtrack(int n , int row, vector<vector<string>>& res, vector<string>& board){
    //base case se wapas jaenge
    if(row==n){
        res.push_back(board);
        return;
    }
    //Now we write the logic for moving through each row
    //and move through each col to check valid 
    for(int col = 0 ; col <n;col++){
        //condn to check if this posn is valid for queen
        if( cols.find(col) != cols.end()      //check if col already occupied
            or posDiag.find(row+col) != posDiag.end() //check if pos diag already occupied
            or negDiag.find(row-col) != negDiag.end())// check -ve diag already occupied
            {
                continue; //if any of these is true
                //then posn is conflicting ie move to next
            }
        //now normally insert and do backtracking exploration logic 
            cols.insert(col);
            negDiag.insert(row-col);
            posDiag.insert(row+col);
            board[row][col] = 'Q'; //update the board value too
        //call backtrack and explore next row
            backtrack(n, row + 1,res, board );
            //remove all added to explore without the value
            cols.erase(col);
            negDiag.erase(row-col);
            posDiag.erase(row+col);
            board[row][col] = '.'; // reset board too
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> res;
       vector<string> board(n,string(n,'.'));
       //set n values of the board to '.'
       backtrack(n,0,res,board);
       return res;
       //hamara board 2d hi hai 
    }
};

