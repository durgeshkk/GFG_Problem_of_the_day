//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
#define ll int
class Solution{ 
public:
// Sol 1:
    Node* reverseLL(Node*head){
        Node* p = head;
        Node* q = head->next;
        Node* r;
        while(q != NULL){
            r = q->next;
            q->next = p;
            if(p == head){
                p->next = NULL;
            }
            p = q;
            q = r;
        }
        return p;
    }

    void reorderList(Node* head) {
        if(head->next == NULL){
            return;
        }

        Node* fst = head;
        Node* slow = head;

        while(fst->next != NULL and fst->next->next != NULL){
            fst = fst->next->next;
            slow = slow->next;
        }

        // Reverse from slow->next to end
        Node* h2 = reverseLL(slow->next);
        slow->next = NULL;

        Node* h1 = head;
        Node* tmp = head;
        ll f = 0;
        while(h1 != NULL and h2 != NULL){
            if(f == 0){
                tmp = h1->next;
                h1->next = h2;
                h1 = tmp;                
            }else{
                tmp = h2->next;
                h2->next = h1;
                h2 = tmp;                
            }
            f ^= 1;
        }
    }

// Sol 2:
/*
    void reorderList(Node* head) {
        // Your code here
        vector<ll> v;
        Node* tmp = head;
        while(tmp != NULL){
            v.push_back(tmp->data);
            tmp = tmp->next;    
        }

        Node* tmp2 = head;
        ll f = 0,i = 0,j = v.size()-1;
        while(tmp2 != NULL){
            if(f == 0){
                f = 1;
                tmp2->data = v[i];
                ++i;
            }else{
                f ^= 1;
                tmp2->data = v[j];
                --j;
            } 
            tmp2 = tmp2->next;
        }
        return;
        // return head;
    }
*/
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends