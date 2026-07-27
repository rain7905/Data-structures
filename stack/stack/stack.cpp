#include "stack.h"
void stinit(st* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0;
    pst->capacity = 0;
}

void stdestroy(st* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = 0;
    pst->capacity = 0;
}

void stprint(st* pst)
{
    assert(pst);
    for (int i = pst->top - 1; i >= 0; i--)
    {
        printf("%d ", pst->a[i]);
    }
    printf("\n");
}

void stpush(st* pst, stdatatype x)
{
    assert(pst);
    if (pst->capacity == pst->top)
    {
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        stdatatype* tmp = (stdatatype*)realloc(pst->a, newcapacity * sizeof(stdatatype));
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
    }
    pst->a[pst->top] = x;
    pst->top++;
}

void stpop(st* pst)
{
    assert(pst);
    assert(!stempty(pst));
    pst->top--;
}

stdatatype sttop(st* pst)
{
    assert(pst);
    assert(!stempty(pst));
    return pst->a[pst->top - 1];
}

bool stempty(st* pst)
{
    assert(pst);
    return pst->top == 0;
}

int stsize(st* pst)
{
    assert(pst);
    return pst->top;
}