    int height_util(Node* root){
        if(root == nullptr) return 0;
        return 1 + max(height_util(root->left), height_util(root->right));
    }
    int height(Node* root) {
        return height_util(root) - 1;
    }
