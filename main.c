#include <stdio.h>
typedef struct GRAPH_NODE_ *pnode;

     typedef struct edge_
    {
        int weight;
        pnode dest;
        struct edge_ *next;
    } edge, *pedge;
        
    
    typedef struct GRAPH_NODE_{
        int id;
        pedge edges;
        struct GRAPH_NODE_ *next;
    }node, *pnode;

void build_graph_cmd(pnode *head)
{
    int num ;
    if (scanf("%d", &num) != 0)
    {
    *head = (pnode)malloc(num * sizeof(node));
    if (*head == NULL)
    {
        printf("error\n");
    }
    }
}
pnode find_node(int id, pnode head)
{
    while ((head->next !=NULL))
    {
        if(head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;

}

pnode add_node( pnode *head)
{
    int id;
    if (scanf("%d", &id) == 0)
    {
        printf("null");
    }
    pnode pn = find_node(id, *head);
    if (pn == NULL)
    {
    pn = (pnode) malloc (sizeof(node));
    if(pn!=NULL){
    pn->id = id;
    pn->next = head;
    head = &pn;
    return pn;
    }
    }
}




int main(int argc, char const *argv[])
{
    node n= {NULL,NULL,NULL};
    pnode pn = &n;
    build_graph_cmd(&pn);
    add_node(&pn);
    add_node(&pn);
    add_node(&pn);
    printf("%d", pn->id);
    free(pn);
    // if(pn !=NULL)
    // {
    //     printf("yayy\n");
    //     free(pn);
    //     printf("%p", pn->id);
    // }
    // if(pn ==NULL)
    // {
    //     printf("yofi!");
    // }

    // node n1;
    // node n2;
    // n1.id = 3;
    // n2.id = 4;
    // edge e;
    // e.weight = 5;
    // e.dest = &n2;
    // e.next = NULL;
    // n1.edges = &e;
    
    // printf("%d", n1.edges->weight);

    
    return 0;
}





    



