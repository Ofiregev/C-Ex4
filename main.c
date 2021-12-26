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






void build_graph_cmd(pnode *pn)
/// pn->id ||(*pn).id || pn =other_pn
{
    // int v;
    // printf("please enter1:");

    // scanf("%d", &v);
    int w;
    char x;
    printf("please enter n:");
    scanf("%c",&x);
    if (x == 'n')
    {
       
        pnode src1 = addNode(pn);//1
        pnode src2 = addNode(pn);//2

        get_edge(pn,&src1);//2
        get_edge(pn,&src2);//3
        get_edge(pn,&src2);//4
        get_edge(pn,&src2);//1

        pnode p = *pn;
        while (p)
        {
            removeByid(&(p->edges),src2->id);
            p = p->next;
        }
        removeALLedges(&(src2->edges));  
    }
   
    if(*pn==NULL)
    {
        printf("not good");
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


int main()
{
    
    pnode pn = NULL;
    build_graph_cmd(&pn);
    // addNode(&pn);
    // addNode(&pn);
    // addNode(&pn);
    // addNode(&pn);
    // while (pn)
    // {
    //     printf("%d ,", pn->id);
    //     printf("%d",pn->edges->weight);
    //     pn->edges = pn->edges->next;
    // }
    // pn = pn->next;
    
    
    
    // printf("%d", pn->next->id);
    return 0;
}