#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pedge add_edge(pnode* head, pnode *src)
{
    pnode dst= addNode(head);
    if(dst==NULL)
    {
        return NULL;
    }
    int w;
    if(scanf("%d",&w)==1);
    pEdge p = (pEdge) malloc(sizeof(edge));
    p->weight =w;
    p->next = (*src)->edges;
    p->dest = dst;
    (*src)->edges = p;
    return (*src)->edges;
}
pedge find_edge(int id, pedge * head)
{
    if(*head==NULL) {return NULL;}
    pedge p = *head;
    while(p){
        if(p->dest->id ==id)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int weight_edge_byid( int src,int dst, pnode * head)
{
    pnode p= find_node(src, *head);
    if(p->edges==NULL){return -1;}
    pedge e = find_edge(dst, &(p->edges));
    if(e!=NULL)
    {
        return e->weight;
    }
    return -1;
}
void delete_first_edge (pedge* head)
{
    if(*head==NULL)
    {
        return;
    }
    pedge p = *head;
    *head = p->next;
    free(p);
}
void remove_edge (pEdge* prev)
{
    pEdge p = (*prev)->next;
    (*prev)->next=(*prev)->next->next;
    free(p);
}
void remove_by_id(int dst, pedge * head)
{
    if(*head==NULL) {return;}
    if((*head)->dest->id==dst)
    {
        delete_first_edge(head);
        return;
    }
    pEdge p =(*head)->next;
    pedge prev =*head;
    while(p!=NULL)
    {
        if(p->dest->id==dst)
        {
            remove_edge(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
void remove_all(pEdge * head)
{
    while((*head)!=NULL)
    {
        delete_first_edge(head);
    }
}
void remove_to_id(pnode * head, int id)
{
    pnode p = *head;
    while(p)
    {
        remove_by_id(id, &((p)->edges));
        p =(p)->next;
    }
}
void insert_edge(pEdge *head, pnode dest, int w)//This function insert new node to the linked list
{
    pEdge pte;
    if((pEdge)malloc(sizeof(edge))==NULL)
    {
        printf("error");
    }else{
    pte = (pEdge)malloc(sizeof(edge));
    pte->dest = dest;
    pte->weight = w;
    pte->next = *head;
    *head = pte;
    }

    return;
}

void deleteFirst(pEdge *head)
{
    if (!(*head))
        return;
    pEdge p = *head;
    *head = p->next;
    free(p);
}

void removeEdge(pEdge *prev)
{
    pEdge p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}

void removeByid(pEdge *head, int dest)
{
    if ((*head) == NULL)
    {
        return;
    }
    if ((*head)->dest->id == dest)
    {
        deleteFirst(head);
        return;
    }
    pEdge prev = *head;
    pEdge p = (*head)->next;

    while (p)
    {
        if (p->dest->id == dest)
        {
            removeEdge(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
int findByid(pEdge *head, int dest)//This function gets the pointer to the list of edges and the destenation id and return the w of the edge
{
    if ((*head) == NULL)
    {
        return inf;
    }
    pEdge p = (*head);

    while (p)
    {
        if (p->dest->id == dest)
        {
            return (*head)->weight;
        }
        p = p->next;
    }
    return -1;
}
int findWbySrc(pnode *head, int src, int dest)//This function gets src id and dest id and return the weight of the edge between them,return -1 if there isnt an edge
{
    pnode ptn = find_node(src, *head);
    if (ptn != NULL)
    {
        pEdge edgeArr = ptn->edges;
        if(edgeArr == NULL)
        {
            return -1;
        }
        int w = findByid(&edgeArr, dest);
        return w;
    }
    return -1;
}
