#include <stdio.h>
#include "graph.h"
#include <stdlib.h>


void free_graph(pnode * head)
{
    pnode  t = *head;
    while (*head)
    {
        remove_all(&((*head)->edges));
        t = *head;
        *head = (*head)->next;
        free(t);
    }
    free(*head);
}
void free_dn_list(p_d_node * head)
{
    p_d_node  t = *head;
    while (*head)
    {
        t = *head;
        *head = (*head)->next;
        free(t);
    }
    free(head);
}
void com_a(pnode * head,int flag,int newflag)
{
    if(flag!=newflag)
    {
        free_graph(head);
    }
    int size;
    size = scanf("%d", &size);
    return;
}
char com_n(pnode * head)
{
    // printf("insert new block \n");
    pnode p = addNode(head);
    if(p != NULL)
    {// remove_all(&(p->edges));
         remove_all(&(p->edges));
    }
    char c;
    // int d;
    // int w;
    do{
        if(add_edge(head, &p)==NULL)
        {
            c = getchar();
            return c;
        }
    } while(1);
}
char com_b(pnode * head)
// printf("insert new block \n");
{
    pnode p = addNode(head);
    remove_all(&(p->edges));
    char c;
    do{
        if(add_edge(head, &p)==NULL)
        {
            c = getchar();
            return c;
        }
    } while(1);
}
void com_d(pnode *head)
{
    pnode p = addNode(head);
    /// find the adress of this node
    remove_all(&(p->edges));
    /// remove all the edges from this node
    remove_to_id(head, p->id);
    /// remove edges to this node
    delete_node_byid(head, p->id);
    // delete this node after we free each edges/
    // printf("DONE");
}
void com_s(pnode * head)
{
    int src;
    int dst;
    if( scanf("%d", &src));
    if( scanf("%d", &dst));
    int res = short_path(head, src, dst);
    // if(res ==inf)
    // {
    //     printf("%d", -1);
    // }
    printf("Dijsktra shortest path: %d\n", res);
}
void com_t(pnode * head)
{
    c_tsp(head);
}
void cmd(pnode * head)
{
    char c;
    int f =1;
    int flag = 1;
    int run =1;
    while(run)
    {
        // printf("welcome");
        if(f==1)
        {
        if(scanf("%c", &c)==EOF)
        {
            run =0;
        }
        }
        if(c=='A')
        {
            
            f=1;
            com_a(head,f,flag);
            flag ++;
            continue;
        }
        if(c=='B')
        {
            f =0;
            c = com_b(head);
            continue;
        }
        if(c=='n')
        {
            f =0;
            c = com_n(head);
            continue;
        }
        if(c=='D')
        {
            f = 1;
            com_d(head);
            continue;
        }
        if(c=='S')
        {
            f =1;
            com_s(head);
            continue;
        }
        if(c=='T')
        {
            f = 1;
            com_t(head);
            continue;
        }
    }
}

int main()
{
    pnode pn =NULL;
    cmd(&pn);
    free_graph(&pn);
    return 0;
}