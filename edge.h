#ifndef GRAPH_
#define GRAPH_

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

#endif
