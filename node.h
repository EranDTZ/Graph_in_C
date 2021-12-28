#ifndef GRAPH_
#define GRAPH_
#include <stdio.h>
#include "node.h"
#include "edge.h"
#include "edge.c" 

typedef struct GRAPH_NODE_ *pnode;;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

#endif