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
T_node *a_list = new T_node[10];

void printList(T_node *head)
{
    while (head)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

void removeNode(T_node **p)
{
    T_node *i = head;
    cout << "i: " << i << endl;
    cout << "i->next: " << i->next << endl;
    cout << "*p: " << *p << endl;
    cout << "*p->info: " << (*p)->info << endl;
    for (; i != NULL && (i != (*p)); i = (i->next))
        cout << "i loop: " << i << endl;
    // if (*i != NULL)
    if (i != 0)
    {
        cout << "i: " << i << endl;   
        // *i = p
        cout << "head: " << head-> info << endl;

        i = i->next;
        // p=p->next;
    }
    cout << "i: " << i << endl;

    if (*p != NULL)
    {
        cout << "(*p)->info: " << (*p)->info << endl;
        cout << "(*p)->next: " << (*p)->next << endl;
        *p=NULL;
        // nodefree((*p));
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
    printList(head);

    removeNode(&cur);
    cout<<cur;
    printList(head);

    return 0;
}
