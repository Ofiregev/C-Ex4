#ifndef GRAPH_
#define GRAPH_

#define inf 10000


typedef struct GRAPH_NODE *pnode;

typedef struct GRAPH_EDGE{
    int weight;
    pnode dest;
    struct GRAPH_EDGE *next;
} edge, *pEdge, *pedge;

typedef struct GRAPH_NODE{
    int id;
    pEdge edges;
    struct GRAPH_NODE * next;
} node , *pnode;

typedef struct DN_{
    int node_id;
    int w;
    int visit;
    struct DN_* next;
}d_node, *p_d_node;

pnode find_node(int id, pnode head);
pnode addNode (pnode *head);


pedge add_edge(pnode* head, pnode *src);
int weight_edge_byid( int src,int dst, pnode * head);
pedge find_edge(int id, pedge * head);


void delete_first (pedge* head);
void remove_edge (pEdge* prev);
void remove_by_id(int dst, pedge * head);
void remove_all(pEdge * head);
void remove_to_id(pnode * head, int id);

void delete_first_node(pnode * head);
void delete_node(pnode* prev);
void delete_node_byid(pnode * head, int id);
void delete_all_node(pnode * head);

void make_D(p_d_node * f, pnode * head);
void Dijk (pnode* head, int sr, p_d_node* f);
int short_path(pnode* head, int src, int dst);
p_d_node find_d_by_id(p_d_node f, int id);
p_d_node find_min(p_d_node f);
void make_D(p_d_node * f , pnode * head);
void add_d(p_d_node * f , pnode p);
int countNOdes (pnode* head);


int TSP(pnode *head, int cur, int count);
// void per(pnode* head, p_d_node *e, int cur, int size, int count, int* min);
int c_tsp(pnode* head);


#endif