//Recursive Solution
int maxDepth(Node* root) {
    if(root){
        height = max(maxDepth(root->left), maxDepth(root->right))
        return height + 1
    }
    return 0
}
//***************************

//Iterative Solution

int maxDepth(TreeNode *root) { 
    // Base Case 
    if (root is NULL) 
        return 0
    // Create an empty queue for level order tarversal 
    Queue q
    q.push(root)
    int height = 0
    while (true) {          //instead while(q.size()){ h++; ...}
        int currLevelNodes = q.size()
        if (currLevelNodes == 0) 
            return height
        height = height + 1
        while (currLevelNodes > 0) 
        { 
            TreeNode node = q.front()
            q.pop()
            if (node.left is not NULL) 
                q.push(node.left)
            if (node.right is not NULL) 
                q.push(node.right)
            currLevelNodes = currLevelNodes - 1
        }
    }
}
//**********************************
