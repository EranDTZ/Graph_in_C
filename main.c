#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char c;
    pnode temp = NULL;
    pnode *head = &temp;
    scanf("%c", &c);
    while (c == 'A' || c == 'B' || c == 'C')
    {
        if (c == 'A')
        {
            build_graph_cmd(head);
        }
        if (c == 'B')
        {
            scanf("%c", &c);
        }
        if (c == 'C')
        {
            scanf("%c", &c);
        }
    }
    return 0;
}
