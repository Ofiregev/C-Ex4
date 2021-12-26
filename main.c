#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *pn)
/// pn->id ||(*pn).id || pn =other_pn
{
    // int v;
    // printf("please enter1:");

    // scanf("%d", &v);
    int w;
    char x;
    printf("please enter n:");
    if(scanf("%c",&x));
    if (x == 'n')
    {
       
        pnode src1 = addNode(pn);//1
        pnode src2 = addNode(pn);//2

        get_edge(pn,&src1);//2
        get_edge(pn,&src2);//3
        get_edge(pn,&src2);//4
        get_edge(pn,&src2);//1
        int w = findWbySrc(pn,src1->id,src2->id);
        printf("%d\n",w);
        

    //     pnode p = *pn;
    //     while (p)
    //     {
    //         removeByid(&(p->edges),src2->id);
    //         p = p->next;
    //     }
    //     removeALLedges(&(src2->edges));  
    // }
   
    if(*pn==NULL)
    {
        printf("not good");
    }
}
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
        printf("%d ,", pn->id);
        // printf("%d",pn->edges->weight);
        // pn->edges = pn->edges->next;
        pn = pn->next;
    }
    printf("It worked!");
    
    
    
    
    // printf("%d", pn->next->id);
    return 0;
}