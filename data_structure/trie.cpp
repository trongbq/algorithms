#include <iostream>
#include <vector>

using namespace std;

const unsigned int ALPHABET_SIZE = 26;

class TreeNode {
public:
    TreeNode *children[ALPHABET_SIZE];
    bool isEnd;
public:
    TreeNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
        isEnd = false; 
    }
};

void insert(TreeNode *node, string s) {
    TreeNode *currNode = node;
    
    for (int i = 0; i < s.size(); i++) {
        int index = ((int) s[i]) - 97;

        if (!currNode->children[index]) {
            currNode->children[index] = new TreeNode();
        }
        currNode = currNode->children[index];
    }
    
    // Mark final node to be the end of a word
    currNode->isEnd = true;
}

bool search(TreeNode *root, string s) {
    TreeNode *currNode = root;
    
    for (int i = 0; i < s.size(); i++) {
        int index = ((int) s[i]) - 97;
        
        if (!currNode->children[index]) {
            return false;
        }
        currNode = currNode->children[index];
    }
    
    return currNode->isEnd;
}

int main()
{
    vector<string> s{"hello", "morning", "hour", "heath", "meeting", "heli"};
    
    cout << "Inserting into trie..." << endl;
    TreeNode *root = new TreeNode();
    for (int i = 0; i < s.size(); i++) {
        insert(root, s[i]);
    }
    
    bool f1 = search(root, "hour");
    cout << (f1 ? "Found" : "Not found") << " `hour` in the trie!" << endl;
    bool f2 = search(root, "honest");
    cout << (f2 ? "Found" : "Not found") << " `honest` in the trie!" << endl;
    
    return 0;
}
