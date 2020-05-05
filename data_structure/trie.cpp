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
        cout << index << endl;
        if (!currNode->children[index]) {
            currNode->children[index] = new TreeNode();
        }
        currNode = currNode->children[index];
    }
    
    currNode->isEnd = true;
}

int main()
{
    vector<string> s{"hello", "morning", "hour", "heath", "meeting", "heli"};
    TreeNode root = TreeNode();

    for (int i = 0; i < s.size(); i++) {
        insert(&root, s[i]);
    }
    
    cout << root.children[7]->children[4]->children[11]->children[11]->isEnd << endl;
    
    return 0;
}
