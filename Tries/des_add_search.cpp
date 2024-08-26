//Google ka questions hai pucha to acha hai sar dard ho gaya 

//Super similar to implementing a trie with add and search

//Medium : the only difference is in this the word can also contain . dots 
//if .bba then we can choose any letter in place of . and find if there exists the other letters 

//We make use of dfs to call the function for our standard case similar to the basic trie

//But if we get a ., then we simply iterate over 26 elements and see if the other 
//letters in that branch of the trie matches the word, also make sure to check if the last letter 
//is marked and then return the output 

//Time: O(m x 26^n) -> m = # of words, n = length of words
//   Space: O(n)
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class WordDictionary {
private:
    TrieNode* root;
    bool searchInNode(string word, TrieNode* node, int i) {

        // base case 1 for dfs
        if (node == NULL)
            return false;
        // base case 2 for dfs
        if (i == word.size())
            return node->isEnd;
        // final check to see if the last letter is marked as end

        if (word[i] != '.') {
            // int curr = word[i] - 'a';
            // curr karke bhi use kar sakte but direct kar rahe
            return searchInNode(word, node->children[word[i] - 'a'], i + 1);
            // this is the classic case when the letter is not a .
            // we simply call dfs with the next node and set the curr node to
            // the children
        }
        // Now the case with .
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, node->children[j], i + 1)) {
                return true;
                // eg .cd found . we call dfs, now j=0 to 26 we see j=0 ke lie
                // if all other letter in the word match j=0 aka 'a'
                // if not we go j=1 aka b , we essentially replaced . with b
                // and now we check the trie if branch beginning with b has
                // childre c and d or not . we iteratre throughout the 26
                // letters to check if
                // there is any branch of these letters that match the word
            }
        }
        return false;
    }

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;
        int curr = 0;
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL)
                // if no children then initialize
                node->children[curr] = new TrieNode();
            node = node->children[curr];
        }
        node->isEnd = true;
    }

    bool search(string word) { return searchInNode(word, root, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */