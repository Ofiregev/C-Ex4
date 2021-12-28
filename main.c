#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define inf 10000

int countNOdes (pnode* head)//This function count how mant nodes we have in the graph
{
    pnode p = *head;
    int count =0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}
void add_d(p_d_node * f , pnode p)//This function add new dijkstra node to the list of the algorithm
{
    p_d_node d =(p_d_node) malloc(sizeof(p_d_node));
        if (d == NULL)
        {
            printf("eroor");
        }
    d->w =inf;
    d->node_id = p->id;
    d->visit =0;
    d->next =(*f);
    (*f) = d;
}
void make_D(p_d_node * f , pnode * head)//This function create the list for the dijkstra algorithm
{
    int count= countNOdes(head);
    pnode p = *head;
    *f = NULL;
    p_d_node d = *f;
        while (p)
    {
        add_d(f, p);
        p=p->next;
    }
}
p_d_node find_min(p_d_node f)//This function run all over the list of d_node and return the one with the minimum weight
{
    int min = inf;
    p_d_node adress = NULL;
    while(f)
    {
        if(f->visit==0)
        {
            if(f->w < min)
            {
                min = f->w;
                adress =f;
            }
        }
        f =f->next;
    }
    return adress; 
    /// if the adress is Null so we are Done doing Dijkstera.
}
p_d_node find_d_by_id(p_d_node f, int id)//This function run on the list of the d_nodes and return the specific node
{
    while(f)
    {
        if(f->node_id==id)
        {
            return f;
        }
        f = f->next;
    }
    return NULL;
}

void Dijk (pnode* head, int sr, p_d_node* f)//Dijksra algorithm- find the shortests path from a specific node in the graph
{

    p_d_node prev =find_d_by_id((*f), sr); 
    // setting the src to be visited and w=0;
    if(prev==NULL)
    {
       return; 
    }
    prev->visit =1;
    prev->w = 0;
    while(prev!=NULL)  /// if there is more nodes we didnt iterat 
    {
        pedge e = find_node(prev->node_id, *head)->edges;

        /// the list of this node edges
        while(e)
        // there is more egdes to this node
        {
            p_d_node temp = find_d_by_id((*f),e->dest->id);
            // find the adress of this struct and check the short path there.
            if(temp->w > ((e->weight) +  (prev->w)))
            {
                temp->w =((e->weight) +  (prev->w));
            }
            e =e->next;
        }
        prev->visit =1;
        prev = find_min(*f);
        /// iteration on the nodes untill we get everyone.
    }
}
int short_path(pnode* head, int src, int dst)//This function return the shortest path between two nodes
{
    p_d_node d =NULL;
    make_D(&d,head);
    Dijk(head, src, &d);
    int min_w =((find_d_by_id(d, dst))->w);
    printf("%d",min_w);
    p_t_f q = free_dn_list;
    q(d);
    return min_w;
    
} 
pnode find_node(int id, pnode head)//This function find node by id in the graph
{
    while (head != NULL)
    {
        if (head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

pnode addNOdeB(pnode *head)//We need to check this function
{
    int id;
    printf("please enter node id");
    if (scanf("%d", &id) == 0)
    {
        printf("type integer value");
        return NULL;
    }
    pnode ptn = find_node(id, *head);
    if (ptn == NULL)
    {
        ptn = (pnode)malloc(sizeof(node));
        if (ptn == NULL)
        {
            printf("eroor");
            return ptn;
        }
        ptn->id = id;
        ptn->next = *head;
        *head = ptn;
    }
    return ptn;
}

pnode addNode(pnode *head)//This function adding new node to the graph (The new node become the head of the linked list)

// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
{
    int id;
    printf("please enter node id");
    if (scanf("%d", &id) == 0)
    {
        printf("type integer value");
        return NULL;
    }
    pnode ptn = find_node(id, *head);
    if (ptn == NULL)
    {
        ptn = (pnode)malloc(sizeof(node));
        if (ptn == NULL)
        {
            printf("eroor");
            return ptn;
        }
        ptn->id = id;
        ptn->next = *head;
        *head = ptn;
    }
    return ptn;
}

void removeALLNodes(pnode *head)
{
    while (*head)
    {
        deleteFirstNode(head);
    }
}

void removeNodeByid(pnode *head, int id)//This function delete node by id
{
    if ((*head) == NULL)
    {
        return;
    }
    if ((*head)->id == id)
    {
        deleteFirstNode(head);
        return;
    }
    pnode prev = *head;
    pnode p = (*head)->next;

    while (p)
    {
        if (p->id == id)
        {
            removeNode(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
void deleteFirstNode(pnode *head)//this function delete the first node in the list and free the memory of the node
{
    if (!*head)
        return;
    pnode p = *head;
    *head = p->next;
    free(p);
}

void removeNode(pnode *prev)//Thid function remove a regular node (not the first)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
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
void get_edge_place(pnode *head, pnode *src)//This function get the place which we node to insert in edge
{
    printf("dest id: ");
    pnode d = addNode(head);
    int w;
    printf("please enter w: ");
    if (scanf("%d", &w) != 0)
    {
        pEdge p = (*src)->edges;

        insert_edge(&p, d, w);
        (*src)->edges = p;
    }
}

void removeALLedges(pEdge *head)
{
    while (*head)
    {
        deleteFirst(head);
    }
}

void deleteFirst(pEdge *head)
{
    if (!*head)
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

void build_graph_cmd(pnode *pn)
{
/// pn->id ||(*pn).id || pn =other_pn
    int w;
    char x;
    printf("please enter n:");
    if (scanf("%c", &x));
    if (x == 'n')
    {

        pnode src0 = addNode(pn); //0
        pnode src1 = addNode(pn); //1
        pnode src2 = addNode(pn); //2
        pnode src3 = addNode(pn); //3
        get_edge(pn, &src0); //1->1
        get_edge(pn, &src0); //2->1
        get_edge(pn, &src1); //2->2
        get_edge(pn, &src2); //3->6
        get_edge(pn, &src3); //0->5
        p_d_node d = NULL;
        make_D(&d,pn);
        short_path(pn,src0->id,2);
        p_t_f d = free_dn_list;
        
        // while (*pn)
        // {
        //     printf("%d", (*pn)->id);
        //     *pn = (*pn)->next;
        // }
         //3
        

      

        // buildMatrix(pn);
        // createMatrix(pn);
        // int w = findWbySrc(pn,src1->id,src2->id);
        // printf("%d\n",w);

        //     pnode p = *pn;
        //     while (p)
        //     {
        //         removeByid(&(p->edges),src2->id);
        //         p = p->next;
        //     }
        //     removeALLedges(&(src2->edges));
        // }

        if (pn == NULL)
        {
            printf("not good");
        }
    }
}
typedef void(*p_t_f)(void*);

void free_graph(pnode * head)
{
    pnode  t = *head;
    while (*head)
    {
        removeALLedges((*head)->edges);
        t = head;
        *head = (*head)->next;
        free(t);
    }
    free(head);
}
void free_dn_list(p_d_node * head)
{
    p_d_node  t = *head;
    while (*head)
    {
        t = head;
        *head = (*head)->next;
        free(t);
    }
    free(head);
}





int main()
{

    pnode pn = NULL;
    build_graph_cmd(&pn);
    // addNode(&pn);
    // addNode(&pn);
    // addNode(&pn);
    // addNode(&pn);
    while (pn)
    {
        //printf("%d ,", pn->id);
        //printf("%d", pn->edges->weight);
        // printf("%d",pn->edges->weight);
        // pn->edges = pn->edges->next;
        pn = pn->next;
    }
    p_t_f d = free_graph;
    d(pn);
    printf("It worked!");

    // printf("%d", pn->next->id);
    return 0;
}