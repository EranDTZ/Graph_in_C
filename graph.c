#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *head)
{
    deleteGraph_cmd(head);
    int v;
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        char n;
        scanf("%c", &n);
        if (n = 'n')
        {
            insert_node_cmd(head);
        }
    }
}

void insert_node_cmd(pnode *head)
{
    int src;
    scanf("%d", &src);
    pnode n = *head;
    pnode temp = n;
    pnode s;
    pnode d;
    while (temp->next != NULL)
    {
        if (temp->node_num == src)
        {
            s = temp;
            temp = n;
        }
    }
    if (s == NULL)
    {
        s = (pnode)malloc(sizeof(node));
        s->node_num = src;
    }
    while (1)
    {
        int dest;
        if (scanf("%d", &dest) == 0)
        {
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->node_num == dest)
                {
                    d = temp;
                    temp = n;
                }
            }
            if (d == NULL)
            {
                d = (pnode)malloc(sizeof(node));
                d->node_num = dest;
            }
            n->edges->endpoint = d;
            int w;
            scanf("%d", &w);
            n->edges->weight = w;
        }
    }
}

// void delete_node_cmd(pnode *head)
// {
//     pnode n = *head;
//     int d;
//     scanf("%d", &d);
//     pnode h;
//     while (n->next != null)
//     {
//         if (n->next->node_num == d)
//         {
//             h = n->next;
//             while (h->next->edges->next != NULL)
//             {
//                 free(h->next->edges)
//                     // h->next->edges->weight = NULL;
//                     h->next->edges = h->next->edges->next;
//             }
//             free(n->next);
//         }
//     }
// }

void printGraph_cmd(pnode head)
{
pnode h = head;
while (h != NULL)
{
    printf("node: %d",h->node_num);
    pedge e = h->edges;
    while (e != NULL)
    {
        printf("edge: ,dest- %d ,w- %d", e->endpoint->node_num,e->weight);
        printf("\n");
    }
}
printf("\n");
} // for self debug


void deleteGraph_cmd(pnode *head)
{
    pnode h = *head;
    while (h != NULL)
    {
        pedge e = h->edges;
        while (e != NULL)
        {
            pedge temp = e;
            e = e->next;
            free(temp);
        }
        pnode temp = h;
        h = h->next;
        free(temp);
    }
    *head = NULL;
}
// void shortsPath_cmd(pnode head);
// void TSP_cmd(pnode head);
