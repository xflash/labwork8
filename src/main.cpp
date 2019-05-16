// Example program
#include <iostream>
#include <string>
using namespace std;

struct Node {
 int value;
 Node* prev;
 Node* next;
};

Node* create_list(int nb_elements) {
    cout << "Creating list of "<<nb_elements<< " elements" << endl;

    if(nb_elements<=0) {
        cerr << "Creating list of "<<nb_elements<< " elements" << endl;
        return NULL;
    }

    Node* root = new Node;
    root->value=rand()%100;
    root->prev=NULL;
    root->next=NULL;

    Node* ptr=root;

    while(nb_elements-- > 1) {
        Node* newNode = new Node;
        newNode->value=rand()%100;
        newNode->prev=ptr;
        ptr->next=newNode;
        newNode->next=NULL;
        ptr=newNode;
    }

    return root;
}

void display_list(Node* root) {
     Node* ptr=root;
     while(ptr!=NULL) {
         cout<<ptr->value<<"; ";
         ptr=ptr->next;
     }
     cout<<endl;
}


/* Bubble sort the given linked list */
void bubbleSort(Node *start)
{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap(ptr1->value, ptr1->next->value);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


int main() {

    srand(time(0));

    int nb;
    cout << "How many elements? ";
    cin >> nb;

    Node* root=create_list(nb);
    cout<<"Unsorted list"<<endl;
    display_list(root);
    bubbleSort(root);
    cout<<"Sorted list"<<endl;
    display_list(root);
}
