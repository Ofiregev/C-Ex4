#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



void insert_edge(pEdge *head,pnode dest, int w)
{
        pEdge pte;
        pte = (pEdge) malloc(sizeof(edge));
        pte->dest = dest;
        pte->weight = w;
        pte->next = *head;
        *head = pte;
    
    return;
}
void get_edge(pnode *head, pnode* src)
{
  printf("dest id: ");
  pnode d = addNode(head);
  int w;
  printf("please enter w: ");
        if (scanf("%d",&w )!=0)
        {
            pEdge p = (*src)->edges;
           
            insert_edge(&p,d,w);
            (*src)->edges = p;

        }
}


void removeALLedges(pEdge *head)
{
    while(*head)
    {
        deleteFirst(head);
    }
}

void deleteFirst(pEdge *head){
if(!*head) return;
pEdge p =*head;
*head = p->next;
free(p);
}

void removeEdge(pEdge *prev)
{
    pEdge p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}

void removeByid(pEdge * head,int dest)
{
    if((*head)== NULL)
    {
        return;
    }
    if((*head)->dest->id == dest)
    {
        deleteFirst(head);
        return;
    }
    pEdge prev = *head;
    pEdge p = (*head)->next;
    
    while (p)
    {
        if(p->dest->id == dest)
        {
            removeEdge(&prev);
        }
        p = p->next;
        prev = prev->next;

    }
    




}
int findByid(pEdge * head,int dest)
{
    if((*head)== NULL)
    {
        return -1;
    }
    pEdge p = (*head);
    
    while (p)
    {
        if(p->dest->id == dest)
        {
            return (*head)->weight;
        }
        p = p->next;
    }
    return NULL;
}
int findWbySrc(pnode *head,int src,int dest)
{
    pnode ptn= find_node(src, *head);
    if(ptn !=NULL)
    {
        pEdge edgeArr = ptn->edges;
        int w = findByid(&edgeArr,dest);
        return w;
    }
    return NULL;
    
}
