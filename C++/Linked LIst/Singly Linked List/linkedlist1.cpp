#include <stdio.h>
#include <malloc.h>
struct List
{
    char data;
    struct List *next;
};
typedef struct List Linked;
int main()
{
    Linked *start;
    Linked node1, node2, node3, node4;
    int i;
    start = (struct List *)malloc(sizeof(Linked));
    start = &node1;
    node1.data = 'A';
    node1.next = &node2;
    node2.data = 'B';
    node2.next = &node3;
    node3.data = 'C';
    node3.next = &node4;
    node4.data = 'D';
    for (i = 0; i < 4; i++)
    {
        printf("%c", start->data);
        start = start->next;
    }
        printf("\n Press a key");

    return 0;
}
