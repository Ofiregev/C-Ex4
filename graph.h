



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

typedef struct DN_
{
    int node_id;
    int node_w;
    int visited;
}d_node, *p_d_node;


void deleteFirst(pEdge *head);
void removeByid(pEdge * head,int dest);
void removeALLedges(pEdge *head);
void removeEdge(pEdge *prev);

void insert_edge(pEdge *head,pnode dest, int w);
void get_edge(pnode *head, pnode* src);
int findWbySrc(pnode *head,int src,int dest);
int findByid(pEdge * head,int dest);



pnode find_node(int id, pnode head);
pnode addNOdeB (pnode *head);
pnode addNode (pnode *head);

void removeNodeByid(pnode * head,int id);
void deleteFirstNode(pnode *head);
void removeNode(pnode *prev);
void removeALLNodes(pnode *head);




void build_graph_cmd(pnode *pn);
void bellman_ford(int **arr,int n);
void shortestPath(int i, int j);
int createMatrix(pnode *head);
void buildMatrix(pnode *head);

d_node* Dijkstra(pnode *head, pnode src);
void relax(pnode *head, p_d_node dis,int src, int nei);
int disByid(p_d_node head, int id);
p_d_node pdnByid(p_d_node head, int id);
void sort(p_d_node dis,int size);
int count_nodes(pnode *head);


















#endif