#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *head)
{
    deleteGraph_cmd(head);
    int v;
    scanf("%d", &v);
    printf("%d", v);
    char n;
    for (int i = 0; i < v; i++)
    {
        scanf("%c", &n);
        if (n == 'n')
        {
            printf("%c", n);
            insert_node_cmd(head);
        }
    }
}

pnode getnode(pnode *head, int id)
{
    pnode n = (*head);
    while (n != NULL)
    {
        if (n->node_num == id)
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

pedge getedge(pnode *head,int src, int id, int w)
{
    pnode n = (*head);
    pedge e = n->edges;
    while(n!=NULL)
    {
        while (e != NULL)
        {
            if (e->endpoint->node_num == id && e->weight == w)
            {
                return e;
            }
            e = e->next;
        }
        e = n->next->edges;
    }
    return NULL;
}

void insert_node_cmd2(pnode *head)
{
    int src = -1;
    scanf("%d", &src);
    pnode s = (*head);
    pnode d = (*head);
    pedge e = NULL;
    int flag = 1;
    s = getnode(s, src);
    if (s == NULL)
    {
        s = (pnode)malloc(sizeof(node));
        s->node_num = src;
    }
    int dest = -1;
    if (scanf("%d", &dest) == 0)
    {
        return;
    }
    d = getnode(d, dest);
    if (d == NULL)
    {
        d = (pnode)malloc(sizeof(node));
        d->node_num = dest;
    }
    e = getedge(

}

void insert_node_cmd(pnode *head)
{
    int src = -1;
    scanf("%d", &src);
    pnode n = (*head);
    pnode temp = n;
    pnode s = NULL;
    pnode d = NULL;
    int flag = 1;
    while (temp != NULL)
    {
        if (temp->node_num == src)
        {
            s = temp;
            temp = n;
        }
        temp = temp->next;
    }
    if (s == NULL)
    {
        s = (pnode)malloc(sizeof(node));
        s->node_num = src;
    }
    // printf("%d", s->node_num);
    printf("\n");
    while (flag)
    {
        int dest = -1;
        if (scanf("%d", &dest) == 0)
        {
            return;
        }
        int w = -1;
        scanf("%d", &w);
        pedge e = (pedge)malloc(sizeof(edge));
        while (s->edges != NULL)
        {
            if (s->edges->endpoint->node_num == dest && s->edges->weight == w)
            {
                return;
            }
        }
        while (temp != NULL && flag)
        {
            if (temp->node_num == dest)
            {
                d = temp;
                e->endpoint = d;
                e->weight = w;
                printf("%d", d->node_num);
                printf("\n");
                printf("%d", w);
                printf("\n");
                while (flag)
                {
                    if (s->edges == NULL)
                    {
                        s->edges = e;
                        flag = 0;
                    }
                    s->edges = s->edges->next;
                }
                temp = n;
            }
            temp = temp->next;
        }
        if (d == NULL)
        {
            d = (pnode)malloc(sizeof(node));
            d->node_num = dest;
            e->endpoint = d;
            e->weight = w;
            printf("%d", d->node_num);
            printf("\n");
            printf("%d", w);
            printf("\n");
            flag = 1;
            while (flag)
            {
                if (s->edges == NULL)
                {
                    s->edges = e;
                    flag = 0;
                }
                s->edges = s->edges->next;
            }
        }
    }
    flag = 1;
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
    while (head != NULL)
    {
        printf("node: %d", head->node_num);
        pedge e = head->edges;
        while (e != NULL)
        {
            printf("edge: ,dest- %d ,w- %d", e->endpoint->node_num, e->weight);
            printf("\n");
            e = e->next;
        }
        head = head->next;
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
