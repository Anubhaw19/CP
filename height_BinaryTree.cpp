int maxDepth(Node* root) {
    if(root){
        height = max(maxDepth(root->left), maxDepth(root->right))
        return height + 1
    }
    return 0
}
