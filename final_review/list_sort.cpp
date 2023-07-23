#include <iostream>
using namespace std;

int length=0;

struct S1
{
    int info;
    struct S1 *next;
};

void printList(S1 *head)
{
    while (head)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

// void swap(S1 **a, S1 **b)
// {
//     S1 *tmp = (*b)->next;
//     (*b)->next = (*a);
//     (*a)->next = tmp;

//     cout<<(*a)-> info<<" ";
//     cout<<(*b)-> info <<endl;
//     // return b;
// }
S1 *swap(S1 *a, S1 *b)
{
    S1 *tmp = b->next;
    b->next = a;
    a->next = tmp;

    return b;
}

void listSort(S1 **head)
{
    S1 **h;
    int swapped;
    // bubble sort
    int count = length;
    for (int i=0; i<length; i++)
    {
        
        h = head;
        swapped =0;
        // while(count--)
        for (int j=0; j<count-i-1; j++)
        {
            S1 *tmp1 = *h;
            S1 *tmp2 = tmp1->next;
            if (tmp1->info > tmp2->info)
            {
                *h = swap(tmp1, tmp2);
                swapped =1;
            }
            cout<<(*h)<<endl;
            cout<<h<<endl;
            // *h = ((*h)->next);
            // why 
            h = (&(*h)->next);
            // cout<< (*tmp1)->info<<endl;
        }
        if(swapped==0) break;
    }
}

int main(int argc, char const *argv[])
{
    S1 *head = new S1;
    head->info = 5;
    length++;
    S1 *cur = new S1;
    cur->info = 2;
    head->next = cur;
        length++;

    S1 *cur2 = new S1;
    cur2->info = 1;
    cur->next = cur2;
        length++;

    cur2->next = NULL;
    // head=swap(cur,cur2);
    // printList(head);
    // cur=swap(cur,cur2);
    // printList(cur);
    // cur2=swap(cur,cur2);
    // printList(cur2);
    printList(head);
    listSort(&head);
    printList(head);

    return 0;
}
