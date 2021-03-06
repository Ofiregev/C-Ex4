#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define inf 10000
#include<stdio.h>

 pedge add_edge(pnode* head, pnode *src)
{
    pnode dst= addNode(head);
    if(dst==NULL)
    {
        return NULL;
    }
    int w;
    if(scanf("%d",&w)==1);
    pEdge p = (pEdge) malloc(sizeof(edge));
    p->weight =w;
    p->next = (*src)->edges;
    p->dest = dst;
    (*src)->edges = p;
    return (*src)->edges;
}
pedge find_edge(int id, pedge * head)
{
    if(*head==NULL) {return NULL;}
    pedge p = *head;
    while(p){
        if(p->dest->id ==id)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int weight_edge_byid( int src,int dst, pnode * head)
{
    pnode p= find_node(src, *head);
    if(p->edges==NULL){return -1;}
    pedge e = find_edge(dst, &(p->edges));
    if(e!=NULL)
    {
        return e->weight;
    }
    return -1;
}
void delete_first_edge (pedge* head)
{
    if(*head==NULL)
    {
        return;
    }
    pedge p = *head;
    *head = p->next;
    free(p);
}
void remove_edge (pEdge* prev)
{
    pEdge p = (*prev)->next;
    (*prev)->next=(*prev)->next->next;
    free(p);
}
void remove_by_id(int dst, pedge * head)
{
    if(*head==NULL) {return;}
    if((*head)->dest->id==dst)
    {
        delete_first_edge(head);
        return;
    }
    pEdge p =(*head)->next;
    pedge prev =*head;
    while(p!=NULL)
    {
        if(p->dest->id==dst)
        {
            remove_edge(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
void remove_all(pEdge * head)
{
    while((*head)!=NULL)
    {
        delete_first_edge(head);
    }
}
void remove_to_id(pnode * head, int id)
{
    pnode p = *head;
    while(p)
    {
        remove_by_id(id, &((p)->edges));
        p =(p)->next;
    }
}

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


pnode addNode(pnode *head)//This function adding new node to the graph (The new node become the head of the linked list)

// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
{
    int id;
    if(scanf("%d",&id)==0)
    {
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
        ptn->edges =NULL;
        *head =  ptn;
    }
    return ptn;
}
void delete_all_node(pnode *head)
{
    while (*head)
    {
        delete_first_node(head);
    }
}

void delete_node_byid(pnode *head, int id)//This function delete node by id
{
    if ((*head) == NULL)
    {
        return;
    }
    if ((*head)->id == id)
    {
        delete_first_node(head);
        return;
    }
    pnode prev = *head;
    pnode p = (*head)->next;

    while (p)
    {
        if (p->id == id)
        {
            delete_node(&prev);
        }
        p = p->next;
        prev = prev->next;
    }
}
void delete_first_node(pnode *head)//this function delete the first node in the list and free the memory of the node
{
    if (!*head)
        return;
    pnode p = *head;
    *head = p->next;
    free(p);
}

void delete_node(pnode* prev)
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

void deleteFirst(pEdge *head)
{
    if (!(*head))
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
    int d;
    int w;
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
    if(res ==inf)
    {
        printf("%d", -1);
    }
    printf("Dijsktra shortest path: %d", res);
}
void com_t(pnode * head)
{
    c_tsp(head);
}
void cmd(pnode * head)
{
    char c;
    int call;
    int f =1;
    int flag = 1;
    while(1)
    {
        // printf("welcome");
        if(f==1)
        {
            if(scanf("%d", &call)!=1)
        {
            c = getchar();
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
            c= com_b(head);
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
    return 0;
}