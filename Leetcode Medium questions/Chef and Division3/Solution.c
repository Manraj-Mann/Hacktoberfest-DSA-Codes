#include <stdio.h>
void main()
{
    int T, N, K, D, A;
    scanf("%d", &T);
    while (T > 0)
    {
        int S = 0;
        scanf("%d%d%d", &N, &K, &D);
        for (int a = 1; a <= N; a += 1)
        {
            scanf("%d", &A);
            S = S + A;
        }
        if (S / K >= D)
        {
            printf("%d\n", D);
        }
        else
        {
            printf("%d\n", S / K);
        }
        T--;
    }
}