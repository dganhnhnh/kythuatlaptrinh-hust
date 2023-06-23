// Nguyen Duong Anh 20210082
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node *prepend(Node *head, int data)
{
    // cấp phát bộ nhớ động 
    Node *temp = (Node*) malloc(100 * sizeof(head)); 
    temp-> data = data;
    temp-> next=head;
    head=temp;
    return head;
}

// print the list content on a line
void print(Node *head)
{
    do {
        cout<< head-> data<<" ";
        head = head-> next;
    }while(head != NULL);

    // if (head == NULL)
    //     return;
    // cout << head->data <<" ";
    // print(head->next);
}

// return the new head of the reversed list
Node *reverse(Node *head)
{
    Node *tempNext = (Node*) malloc(100 * sizeof(head)); 
    Node *tempPrev = (Node*) malloc(100 * sizeof(head)); 
    tempNext = head-> next;
    head->next = NULL;
    // cout<<"tempNext: "<<tempNext->data<<", ";

    while(tempNext != NULL){
        // cout<<"head: "<<head-> data<<", ";
        tempPrev = head;
        head = tempNext;
        // cout<<"new head: "<<head-> data<<", ";

        tempNext = head->next;
        head-> next = tempPrev;
        // cout<<"new head next: "<<tempPrev-> data<<", ";
        // cout<< "\n";
    }
    return head;
}

int main()
{
    int n, u;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        head = prepend(head, u);
        cout << head->data;
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
// Nguyen Duong Anh 20210082