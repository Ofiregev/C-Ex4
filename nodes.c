#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


pnode find_node(int id, pnode head)
{
    while(head!=NULL)
    {
        if(head->id==id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

pnode addNOdeB (pnode *head)
{
int id;
    printf("please enter node id");
    if(scanf("%d",&id)==0)
    {
        printf("type integer value");
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
        *head =  ptn;
    }
    return ptn;
}



pnode addNode (pnode *head)

// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
{
    int id;
    printf("please enter node id");
    if(scanf("%d",&id)==0)
    {
        printf("type integer value");
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
        *head =  ptn;
    }
    return ptn;
}

void removeALLNodes(pnode *head)
{
    while(*head)
    {
        deleteFirstNode(head);
    }
}

void removeNodeByid(pnode * head,int id)
{
    if((*head)== NULL)
    {
        return;
    }
    if((*head)->id == id)
    {
        deleteFirstNode(head);
        return;
    }
    pnode prev = *head;
    pnode p = (*head)->next;
    
    while (p)
    {
        if(p->id == id)
        {
            removeNode(&prev);
        }
        p = p->next;
        prev = prev->next;

    }

}
void deleteFirstNode(pnode *head){
if(!*head) return;
pnode p =*head;
*head = p->next;
free(p);
}

void removeNode(pnode *prev)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}

