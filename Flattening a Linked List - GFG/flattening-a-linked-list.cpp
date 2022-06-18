// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* SortedMerge(Node* a, Node* b){
    Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(Node** headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    FrontBackSplit(head, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);
 
    *headRef = SortedMerge(a, b);
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root){
    MergeSort(&root);
    
    Node* temp = root;
    while(temp != NULL){
        Node* prev = temp; 
        Node* curr = temp->bottom;
        Node* next;
        Node* t1 = root;
        while(curr != NULL){
            t1 = root;
            next = curr->bottom;
            int x = curr->data;
            if(x < root->data){
                prev->bottom = next;
                curr->next = root;
                curr->bottom = NULL;
                root = curr;
                curr = next;
                continue;
            }
            while(t1->next != NULL && x > (t1->next)->data){
                t1 = t1->next;
            }
            prev->bottom = next;
            curr->next = t1->next;
            curr->bottom = NULL;
            t1->next = curr;
            curr = next;
        }
        temp = temp->next;
    }
    temp = root;
    while(temp != NULL){
        temp->bottom = temp->next;
        temp = temp->next;
    }
    return root;
}


