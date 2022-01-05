#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode temp = (pnode)(malloc(sizeof(node)));
    pnode *head = &temp;
    insert_node_cmd2(head);
    // char c;
    // scanf("%c", &c);
    // insert_node_cmd(head);
    //printGraph_cmd(*head);
    // while (c == 'A' || c == 'B' || c == 'C')
    // {
    //     if (c == 'A')
    //     {
    //         build_graph_cmd(head);
    //     }
    //     if (c == 'B')
    //     {
    //         scanf("%c", &c);
    //     }
    //     if (c == 'C')
    //     {
    //         scanf("%c", &c);
    //     }
    //     printGraph_cmd(*head);
    // }

    return 0;
}
