



#ifndef GRAPH_
#define GRAPH_



typedef struct GRAPH_NODE *pnode;

typedef struct GRAPH_EDGE{
    int weight;
    pnode dest;
    struct GRAPH_EDGE *next;
} edge, *pEdge,*pedge;

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


void deleteFirst(pEdge *head);
void removeByid(pEdge * head,int dest);
void removeALLedges(pEdge *head);
void removeEdge(pEdge *prev);

void insert_edge(pEdge *head,pnode dest, int w);
void get_edge_place(pnode *head, pnode* src);
int findWbySrc(pnode *head,int src,int dest);
int findByid(pEdge * head,int dest);



pnode find_node(int id, pnode head);
pnode addNOdeB (pnode *head);//We need to check this function
pnode addNode (pnode *head);

void removeNodeByid(pnode * head,int id);
void deleteFirstNode(pnode *head);
void removeNode(pnode *prev);
void removeALLNodes(pnode *head);

void build_graph_cmd(pnode *pn);


void make_D(p_d_node * f, pnode * head);
void Dijk (pnode* head, int sr, p_d_node* f);
int short_path(pnode* head, int src, int dst);
p_d_node find_d_by_id(p_d_node f, int id);
p_d_node find_min(p_d_node f);
void make_D(p_d_node * f , pnode * head);
void add_d(p_d_node * f , pnode p);
int countNOdes (pnode* head);

















#endif