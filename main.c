#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define maxint 10000

d_node* Dijkstra(pnode *head, pnode src)
{
    int sum_nodes = count_nodes(head);
    printf("%d",sum_nodes);
    p_d_node distance = (p_d_node)malloc(sizeof(d_node) * sum_nodes);
    pnode p = *head;
    int i = 0;
    while (p)
    {
        if(p->id == src->id)
        {
            distance[i].node_id = (p)->id;
            distance[i].node_w= 0;
            distance[i].visited = 0;
            p=p->next;
            i++;
            continue;
        }
        distance[i].node_id = (p)->id;
        distance[i].node_w = maxint;
        distance[i].visited = 0;
        i++;
        p = (p)->next;
    }
    printDist(distance);
    while (distance[0].visited!=1)
    {
        //     pnode src0 = addNode(pn); //0
        // pnode src1 = addNode(pn); //1
        // pnode src2 = addNode(pn); //2
        // pnode src3 = addNode(pn); //3
        // get_edge(pn, &src0); //1->1
        // get_edge(pn, &src0); //2->1
        // get_edge(pn, &src1); //2->2
        // get_edge(pn, &src2); //3->6
        // get_edge(pn, &src3); //0->5
    
        sort(distance, sum_nodes);
        // printDist(distance);
        pnode v = find_node((distance)->node_id ,*head);
        distance[0].visited = 1;
        if((v->edges)== NULL)
        {
            
        }else
        {
        pEdge e = v->edges;
        while (e)
        {
            relax(head,distance,v->id,e->dest->id);
            e = e->next;
        }
        }
        // printDist(distance);
    }
    // printf("%d",disByid(distance,3));
    return distance;
}
void printDist(p_d_node head)
{
    p_d_node n =head;
    while (head)
    {
        printf("%d__",head->node_w);
        head = head +sizeof(d_node);
    }
    printf("-----------"); 
}


void relax(pnode *head, p_d_node dis,int src, int nei)
{
    pnode n = find_node(src , *head);
    pEdge e = n->edges;
// findByid(&e,nei)
    int curr_w = disByid(dis,src) +findWbySrc(head,src,nei) ;

    if(disByid(dis,nei) > curr_w)
    {
        p_d_node g=  pdnByid(dis,nei);
        g->node_w = curr_w;
        g->visited = 1;
    }
}

int disByid(p_d_node head, int id)
{
    p_d_node p = head;
    while (p)
    {
        if(p->node_id == id)
        {
            printf("%d\n", p->node_w);
            return p->node_w;
        }
        p++;
    }
    return -1;
}
p_d_node pdnByid(p_d_node head, int id)
{
    p_d_node p = head;
    while (p)
    {
        if(p->node_id == id)
        {
            return p;
        }
        p++;
    }
    return NULL;
}



void sort(p_d_node dis,int size)
{
    int vis = 0;
    p_d_node dist = dis;
    for (int j = 0;j<size;j++)
    {
        if ((dist+j)->visited == 1)
        {
            d_node temp = dist[j];
            dist[j] = dist[size-1-vis];
            dist[size-1-vis] = temp;
            vis++;
        }
    }
    for (int i = 0;i<size-vis;i++)
    {
        for(int j = 0;j<size-vis-1-i;j++)
        {
            if((dist+j)->node_w >(dist+j+1)->node_w)
            {
                d_node temp = dist[j];
                dist[j] = dist[j+1];
                dist[j+1] =temp;
            }
        }
    }
}
int count_nodes(pnode *head)
{
    pnode p = *head;
    int count = 0;
    while (p)
    {
        count ++;
        p = (p)->next;
    }
    return count;

}
    
pnode find_node(int id, pnode head)
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

pnode addNOdeB(pnode *head)
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

pnode addNode(pnode *head)

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

void removeNodeByid(pnode *head, int id)
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
void deleteFirstNode(pnode *head)
{
    if (!*head)
        return;
    pnode p = *head;
    *head = p->next;
    free(p);
}

void removeNode(pnode *prev)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}

void insert_edge(pEdge *head, pnode dest, int w)
{
    pEdge pte;
    pte = (pEdge)malloc(sizeof(edge));
    pte->dest = dest;
    pte->weight = w;
    pte->next = *head;
    *head = pte;

    return;
}
void get_edge(pnode *head, pnode *src)
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
int findByid(pEdge *head, int dest)
{
    if ((*head) == NULL)
    {
        return maxint;
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
int findWbySrc(pnode *head, int src, int dest)
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
    
        Dijkstra(pn,src0);
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
int createMatrix(pnode *head)
{
    pnode p = *head;
    int sum = 0;
    while (p)
    {
        sum++;
        p = p->next;
    }
    int **matrix = (int **)malloc(sum * sizeof(int *));
    for (int i = 0; i < sum; i++)
        matrix[i] = (int *)malloc(sum * sizeof(int));

    for (int i = 0; i < sum; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            int w = findWbySrc(head, i, j);
            if (w != -1)
            {
                matrix[i][j] = findWbySrc(head, i, j);
            }
            else
            {
                matrix[i][j] = 1000;
            }
        }
    }
    printf("%d----", matrix[1][2]);
    // bellman_ford(matrix,1);
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
    printf("It worked!");

    // printf("%d", pn->next->id);
    return 0;
}