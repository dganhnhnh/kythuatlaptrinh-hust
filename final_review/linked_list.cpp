#include <iostream>
using namespace std;

struct S1{
    int info;
    struct S1 *next;
};

void printList(S1 *head){
    while(head){
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    S1 *head = (S1*)malloc(sizeof(S1));
    head ->info=1;
    head-> next =NULL;
    printList(head);
    /* code */
    S1 *cur = (S1*)malloc(sizeof(S1));
    cur-> info=0;
    cur-> next=head;
    head = cur;
    printList(head);

    return 0; 
}
