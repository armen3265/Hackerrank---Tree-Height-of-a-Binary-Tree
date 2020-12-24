#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    typedef pair<Node,int> myPair;
    int height(Node* root) {
        myPair heights(*root,0);
        int height = 0;
        
        stack<myPair> st;
        
        st.push(heights);
        
        while(!st.empty())
        {
            myPair temp = st.top();
            st.pop();
            if(temp.first.left)
            {
                myPair left(*temp.first.left, temp.second + 1);
                st.push(left);
            }
            if(temp.first.right)
            {
                myPair right(*temp.first.right, temp.second + 1);
                st.push(right);
            }
            if(height < temp.second)
            {
                height = temp.second;
            }
        }
        return height;
    }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}
