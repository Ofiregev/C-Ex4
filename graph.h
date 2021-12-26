



#ifndef GRAPH_
#define GRAPH_



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

void deleteFirst(pEdge *head);
void removeByid(pEdge * head,int dest);
void removeALLedges(pEdge *head);
void removeEdge(pEdge *prev);

void insert_edge(pEdge *head,pnode dest, int w);
void get_edge(pnode *head, pnode* src);

pnode find_node(int id, pnode head);
pnode addNOdeB (pnode *head);
pnode addNode (pnode *head);

void removeNodeByid(pnode * head,int id);
void deleteFirstNode(pnode *head);
void removeNode(pnode *prev);




void build_graph_cmd(pnode *pn);












#endif