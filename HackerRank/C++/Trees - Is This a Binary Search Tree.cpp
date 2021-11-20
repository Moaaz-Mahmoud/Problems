/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool checkBST_util(Node* nd, int mn, int mx){
        if(nd == nullptr) return true;
        return 
            nd->data < mx && nd->data > mn          && 
            checkBST_util(nd->left, mn, nd->data)   &&
            checkBST_util(nd->right, nd->data, mx);

    }
	bool checkBST(Node* root) {
		return checkBST_util(root, -1000000090, 1000000090);
	}
