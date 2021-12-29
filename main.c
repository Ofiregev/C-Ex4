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
int wight_edge_byid( int src,int dst, pnode * head)
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

void per(pnode* head, p_d_node *e, int cur, int size, int count, int* min)
{
    if(size==0)
    {
        int res = TSP(head, cur, count);
        if((*min) > res)
        {
            printf("sooo");
            *min = res;
        }
    }
    p_d_node d = *e;
    while(d)
    {
        if(d->visit==0)
        {
            d->visit =1;
            cur = cur*10 + (d->node_id);
            per(head, e, cur, size-1, count+1, min);
        }
        d->visit =0;
        d = d->next;
    }
}
int * reversNUm(int curr, int size)
{
    int t = curr;
    printf("%d",t);
    int sum_of_digit = 0;
    while(t > 0)
    {
        t = t/10;
        sum_of_digit++;
    }
    int * arr = (int *)malloc(sizeof(int)*size);
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
    for(int i=0; i<count-1;i++)
    {
        sum += short_path(head, arr[i], arr[i+1]);
    }
    return sum;
}
int c_tsp(pnode  head)
{
    p_d_node d = NULL;
    pnode  l=NULL;
    int size =0;
    int n;
    if(scanf("%d", &size));
    for( int i=0 ; i< size ;i++)
    {
        if(scanf("%d", &n));
        pnode temp = (pnode) malloc(sizeof(node));
        temp->id = n;
        temp->edges = find_node(n, head)->edges;
        temp->next = l;
        l = temp;
    }

    make_D(&d, &l);
    int* res = (int*) malloc(sizeof(int));
    *res = inf;
    per(&l, &d, 0, size, 0  ,res);
    return(*res);
}
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
            if(temp->w > ((e)->weight) +  (prev->w))
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
    // printf("%d",min_w);
    // p_t_f q = free_dn_list;
    // q(d);
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
            removeNode(&prev);
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

void removeNode(pnode *prev)//Thid function remove a regular node (not the first)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    //remove_all(p->edges);
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
















/// pn->id ||(*pn).id || pn =other_pn
    // int w;
    // char x;
    // int stam;
    // scanf("%d",&stam);
    // printf("please enter n:");
    // scanf("%c", &x);
    // while (x == 'n')
    // {
    //     pnode src = addNode(pn); 

    //     int d;
    //     while (scanf("%d ",&d)==1)
    //     {
    //         int w;
    //         scanf("%d",w);
    //         get_edge_place(pn,src,d,w);
    //         scanf("%d ",&d);
    //     }
    //     while (*pn)
    //     {
    //         printf("%d",(*pn)->id);
    //     }
        
        
       
        









    // pnode src0 = addNode(pn); //0
    // pnode src1 = addNode(pn); //1
    // pnode src2 = addNode(pn); //2
    // pnode src3 = addNode(pn); //3
    // get_edge_place(pn, &src0,1,1); //1->1
    // get_edge_place(pn, &src0,2,1); //2->1
    // get_edge_place(pn, &src1,2,2); //2->2
    // get_edge_place(pn, &src2,3,6); //3->6
    // get_edge_place(pn, &src3,0,5);
    // c_tsp(*pn); //0->5
    //     // p_d_node d = NULL;
        // make_D(&d,pn);
        // short_path(pn,src0->id,2);
        // p_t_f q = free_dn_list;
        // q(d);
        // scanf("%c", &x);
        
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

        // if (pn == NULL)
        // {
        //     printf("not good");
        // }
    



void free_graph(pnode * head)
{
    pnode  t = *head;
    while (*head)
    {
        remove_all((*head)->edges);
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
void com_a(pnode * head)
{
    if((*head)!=NULL)
    {
        free_graph(head);
    }
    int size;
    if(scanf("%d", &size)==1);
    return;
}
char com_n(pnode * head)
{
    printf("imsert new block \n");
    pnode p = addNode(head);
    remove_all(&(p->edges));
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
{
    return ('n');
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
}
void com_s(pnode * head)
{
    int src;
    int dst;
    if( scanf("%d", &src));
    if( scanf("%d", &dst));
    int res = short_path(head, src, dst);
    printf("%d", res);
}
char com_t(pnode * head)
{
    int res = c_tsp(head);
    char c =getchar();
    printf("%d", res);
    return c;
}
void cmd(pnode * head)
{
    char c;
    int call;
    int f =1;
    while(1)
    {
        printf("welcome");
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
            com_a(head);
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
            f =1;
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
            f =0;
            c= com_t(head);
            continue;
        }
        if(c == 'q')
        {
            return;
        }
    }
}

int main()
{
    pnode pn =NULL;
    // pnode s1 = addNode(&pn); //0
    // pnode s2 = addNode(&pn);  ///1
    // pnode s3= addNode(&pn);   //2
    // // pnode s4 = addNode(&pn);   //3
    // // add_edge(&pn, &s1);
    // // add_edge(&pn, &s1);
    // // add_edge(&pn, &s2);
    // // add_edge(&pn, &s3);
    // // add_edge(&pn, &s4);
    // p_d_node d= NULL;
    // int i=0;
    // make_D(&d, &pn);
    // per(&d, 3, 0);
    cmd(&pn);
    printf("Done");
    return 0;
}