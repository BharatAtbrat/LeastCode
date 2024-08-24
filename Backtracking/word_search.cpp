//Medium
//Time: O(n x 3^l) -> n = # of cells, l = length of word
//   Space: O(l)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0 ; i < rows ; i++){
            for(int j =0 ; j<cols;j++){
                if(board[i][j] == word[0]){
                    //iterate until first letter found
                    if(dfs(board, word, 0, i, j, rows, cols)){
                        //if recursive call doesnt return 
                        //true then yeahh
                        return true;
                    }
                }
            }
        }
        return false;
    }
private: 
bool dfs(vector<vector<char>>& board, string word, int index, int i ,int j, int rows, int cols){
    //condn for overflow underflow yadayada

    if(i< 0 || i >= rows || j <0 || j>= cols || board[i][j] != word[index])
{
    return false;
}
if (index == word.size() -1 ){
    return true;
    //if we stay true until last index that means the word is found
}
board[i][j] = '#';
//instead of storing each visisted letter in a set
//we makr the letter in the board as # and restore is after one iteration

//dfs directions 
if(dfs(board, word, index+1, i - 1, j , rows , cols) //left
    || dfs(board, word, index+1, i + 1, j, rows, cols)   //right
    || dfs(board, word, index+1, i, j-1, rows, cols) //down
    || dfs(board, word, index+1 , i , j+1, rows, cols)) //up
    {
        return true;
    }
    board[i][j] = word[index]; //reset the board;
    return false;
}
};