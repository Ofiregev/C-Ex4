#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


pnode find_node(int id, pnode head)//This function find node by id in the graph
{
    while (head != NULL)
    {
        if (head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


pnode addNode(pnode *head)//This function adding new node to the graph (The new node become the head of the linked list)

// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
{
    int id;
    if(scanf("%d",&id)==0)
    {
        return NULL;
    }
    pnode ptn= find_node(id, *head);
    if(ptn==NULL)
    {
        ptn = (pnode) malloc(sizeof(node));
        if(ptn==NULL)
        {
            printf("eroor");
            return ptn;
        }
        ptn->id =id;
        ptn->next = *head;
        ptn->edges =NULL;
        *head =  ptn;
    }
    return ptn;
}
void delete_all_node(pnode *head)
{
    while (*head)
    {
        delete_first_node(head);
    }
}

void delete_node_byid(pnode *head, int id)//This function delete node by id
{
    if ((*head) == NULL)
    {
        return;
    }
    if ((*head)->id == id)
    {
        delete_first_node(head);
        return;
    }
    pnode prev = *head;
    pnode p = (*head)->next;

    while (p)
    {
        if (p->id == id)
        {
            delete_node(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
void delete_first_node(pnode *head)//this function delete the first node in the list and free the memory of the node
{
    if (!*head)
        return;
    pnode p = *head;
    *head = p->next;
    free(p);
}

void delete_node(pnode* prev)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}