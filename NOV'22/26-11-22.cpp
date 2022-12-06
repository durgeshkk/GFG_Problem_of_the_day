//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

#define ll long long int
class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string s){
        // code here
        if(s.size() == 0){return NULL;}
        
        stack<Node*> st;
        int ag = 0,i = 0;
        while(i<s.size()){
            if(s[i] == '(' or s[i] == ')'){
                // --i;
                break;
            }
            // cout<<"HI\n";
            ag = (ag*10 + (s[i]-'0'));
            ++i;
        }

        Node* root = new Node(ag); 
        st.push(root);
        ll cnt = 0;
        // cout<<root->data<<endl;
        // cout<<i<<endl;

        for(i;i<s.size();++i){
            if(s[i] == '('){
                ++cnt;continue;
            }else if(s[i] == ')'){
                if(cnt != 0){
                    st.pop();
                }else{
                    if(s.size() == 2){
                        st.pop();
                    }
                }
                --cnt;
            }else{
                // cout<<i<<" "<<s[i]<<" ";

                int ag = 0;
                while(i<s.size()){
                    if(s[i] == '(' or s[i] == ')'){
                        --i;
                        break;
                    }
                    // cout<<"HI\n";
                    ag = (ag*10 + (s[i]-'0'));
                    ++i;
                }
                // cout<<ag<<endl;continue;
                
                // int dk = stoi(ag);
                Node *tmp = new Node(ag);
                if(st.top()->left == NULL){
                    st.top()->left = tmp;
                }else{
                    st.top()->right = tmp;
                }
                st.push(tmp);
            }   
            // cout<<st.top()->data<<endl;
        }
        return root;
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends