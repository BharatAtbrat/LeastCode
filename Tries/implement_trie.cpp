//Medium
//Trie is nice we create Trie class 
//with the following functions 
// insert(string word) - insert into trie TC O(n) SC O(n)
// search(string word) - true if present TC O(n) SC O(1)
// startswith(string prefix ) - true if starts TC O(n) SC )91


//Microsoftie ne pucha 
//Check node declaration and usage with root node
//ggwp

//We create Trie node on our own first 
class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd; // to mark last letter for any word 

        //constructor initialization

        TrieNode() {
            for(int i =0 ; i < 26;i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
};

class Trie {
private: 
    TrieNode* root;
public:
    Trie() {
        //initialize trienode
       root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        int curr =0;
        for(int i =0 ; i <word.size();i++){
            //
            curr = word[i] - 'a';
            if(node->children[curr] == NULL){
                //if no children we initialize
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr]; //move to next child 
            //of cur node
        }   
        //once reached at the last node we mark the letter as 
        //as last 
        node->isEnd = true;
         }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0 ;

        for(int i =0 ; i< word.size();i++){
            curr = word[i] - 'a'; //convert letter to number
            if(node->children[curr] == NULL) return false;
            node = node->children[curr];
        } 
        return node->isEnd; //if last letter then the search
        //is succesful and the word is found
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;

        for(int i = 0 ; i < prefix.size();i++){
            curr = prefix[i] -'a';
                if(node->children[curr] == NULL) return false;
                node = node->children[curr];
            }
            return true; //we dont check if the letter is marked
            //last because we are only searching for starts with
        }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */