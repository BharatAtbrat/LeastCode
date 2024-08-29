//Medium 

//Logic is easy just need to understand ki subboxes ka logic kaise kaam karta hai 

/* Create sets for each row col and subbox , now iteratre through grid (harcoded 9x9 to tc O(81))
    Check if . , we move on 
    calculate box index by formula r/3*3 + c/3 it gives the correct subbox 
    If duplicate found in either of the 3 sets 
    return false 
ow keep adding the element into the sets

*/

//TC O(1) SC O(27) constant 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9]
        unordered_set<int> col[9];
        unordered_set<int>box[9];

        for(int r = 0 ; r< board.size();r++){
            for(int c = 0 ; c < board.size();c++){
                if(board[r][c]=='.') continue;
               int boxindex = r/3 *3 + c/3;
                if(row[r].count(board[r][c]) ||
                    col[c].count(board[r][c]) ||
                     box[boxindex].count(board[r][c])){
                        return false;
                     }
                    row[r].insert(board[r][c]);
                    col[c].insert(board[r][c]);
                    box[boxindex].insert(board[r][c]);
            }
        }
        return true;
    }
};
