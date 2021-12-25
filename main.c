#include <stdio.h>
#include <stdlib.h>


typedef struct GRAPH_NODE *pnode;

typedef struct GRAPH_EDGE{
    int weight;
    pnode dest;
    struct GRAPH_EDGE *next;
} edge, *pEdge;

typedef struct GRAPH_NODE{
    int id;
    pEdge edges;
    struct GRAPH_NODE * next;
} node , *pnode;

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
       
        pnode src = addNode(pn);
        pnode src2 = addNode(pn);
        get_edge(pn,&src);
        get_edge(pn,&src);
        get_edge(pn,&src2);
        get_edge(pn,&src2);


        
    }
   
    if(*pn==NULL)
    {
        printf("not good");
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
    while (pn){
    if (pn->edges!=NULL)
    {
        printf("%d ,", pn->id);
        printf("%d",pn->edges->weight);
    }
    pn = pn->next;
    }
    
    
    // printf("%d", pn->next->id);
    return 0;
}