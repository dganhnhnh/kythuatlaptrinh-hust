#include <iostream>
using namespace std;

struct T_node
{
    int info;
    T_node *next;
};

void nodefree(/*@keep@*/ /*@null@*/ T_node *np)
{
    if (!np)
        return;
    /*@-mustfreeonly@*/
    if (np->next)
        return; /* don't free, has oo data */
    free(np);
    // np->info=NULL;
    /*@=keeptrans@*/
}

T_node *head = (T_node *)malloc(sizeof(T_node));
// head trỏ đến đầu của alist
// T_node *a_list = head;

void printList(T_node *head)
{
    while (head)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

void removeNode(T_node *p)
{
    T_node **i = &head;
    T_node *prev = NULL;
    for (; (*i) != NULL && ((*i) != p); *i = ((*i)->next))
    {
        // cout << "(*i) in loop: " << (*i) << endl;
        prev = *i;
    }
    // cout << "(*i) out loop: " << (*i) << endl;
    // if (*i != 0)
    if (*i != NULL)
    {
        // (*i) = (*i)->next;
        prev->next = (*i)->next;
    }

    if (p != NULL)
    {
        nodefree(p);
    } // giải phóng node trỏ bởi p

}

int main(int argc, char const *argv[])
{
    /* code */
    head->info = 1;
    head->next = NULL;
    /* code */
    T_node *cur = (T_node *)malloc(sizeof(T_node));
    cur->info = 2;
    cur->next = NULL;
    head->next = cur;

    T_node *cur2 = (T_node *)malloc(sizeof(T_node));
    cur2->info = 3;
    cur2->next = NULL;
    cur->next = cur2;

    printList(head);

    removeNode(cur);
    printList(head);

    return 0;
}
