#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define inf 10000
int countNOdes (pnode* head)
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
void add_d(p_d_node * f , pnode p)
{
    p_d_node d =(p_d_node) malloc(sizeof(p_d_node));
    d->w =inf;
    d->node_id = p->id;
    d->visit =0;
    d->next =(*f);
    (*f) = d;
}
void make_D(p_d_node * f , pnode * head)
{
    // int count= countNOdes(head);
    pnode p = *head;
    *f = NULL;
    // p_d_node d = *f;
    while (p)
    {
        add_d(f, p);
        p=p->next;
    }
}
p_d_node find_min(p_d_node f)
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
p_d_node find_d_by_id(p_d_node f, int id)
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

void Dijk (pnode* head, int sr, p_d_node* f)
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
int short_path(pnode* head, int src, int dst)
{
    p_d_node d =NULL;
    make_D(&d,head);
    Dijk(head, src, &d);
    int min_w =((find_d_by_id(d, dst))->w);
    return min_w;
    ///// NEED TO DO TOTAL_DELETE TO d;
    free(d);
}
int * reversNUm(int curr, int size)
{
    int t = curr;
    int sum_of_digit = 0;
    while(t > 0)
    {
        t = t/10;
        sum_of_digit++;
    }
    int * arr = (int *)malloc(sizeof(int)*size);
    /// freeing in the tsp function
    if(size > sum_of_digit)
    {
        int w = curr;
        arr[size -1] =0;
        for (int i=0;i<size-1;i++)
        {
            arr[i] = w%10;
            w=w/10;
        }
        return arr;
    }else{
        int w = curr;
        for (int i=0;i<size;i++)
        {
            arr[i] = w%10;
            w=w/10;
        }
        return arr;
    }
}
int TSP(pnode *head, int cur, int count)
{
    int sum =0;
    int *arr = reversNUm(cur,count);
    // printf("per :");
    for(int i=0; i<count-1;i++)
    {
        
        sum += short_path(head, arr[i], arr[i+1]);
    }
    // printf("%d",sum);
    free(arr);
    return sum;
}
void per (pnode *q,p_d_node * head, int size, int num,int count, int* min)
{
    
    if(size==0)
    {
        int res = TSP(q,num, count);
        if((*min) > res)
        {
            *min = res;
        }
    }
    p_d_node p = *head;
    while(p)
    {
        if(p->visit==0)
        {
            p->visit =1;
            per(q, head, size-1, num*10 + p->node_id,count+1, min);
            p->visit =0;
        }
        p = p->next;
    }
}
void total_remove(pnode * head)
{
    pnode p = *head;
    while(p)
    {
        pnode temp = p;
        p= temp->next;
        pedge e =temp->edges;
        while(e)
        {
            pedge t = e;
            e =t->next;
            free(t);
        }
        free(temp);
    }
    printf("Done!");
}
void c_tsp(pnode* head)
{
    int * min = (int*) malloc(sizeof(int));
    ///freeing at the end of the function
    *min = inf;
    int size;
    p_d_node d = NULL;
    pnode p =NULL;
    int my_id;
    // printf("ENTER SIZE:");
    scanf("%d", &size);
    int size9= 0;
    for (int i=0; i<size; i++)
    {
        pnode t = (pnode) malloc(sizeof(node));
        if(scanf("%d", &my_id));
        pnode f = find_node(my_id, *head);
        if(f == NULL)
        {
            continue;
        }
        t->id = f->id;
        t->edges = f->edges;
        t->next = p;
        p = t;
        size9++;
    }
    make_D(&d, &p);
    // total_remove(&p);
    per(head,&d, size9, 0, 0,min);
    
    /// need to do total_delete to d/
    if((*min) == inf)
    {
        *min = -1;

    }
    printf("TSP shortest path: %d\n", *min);
    free(min);
}