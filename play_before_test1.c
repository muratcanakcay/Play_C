#include <stdio.h>

void main()
{
    int i, j, K, N;
    K = 7;
    N = 6;
    for (i=K; i>0; i--)
        {
            for (j=0; j<N+i-1; j++)
            {
                printf(" ");
            }
            for (j=0; j<i; j++)
            {
                printf("%d", j+1);
            }
        printf("\n");
        }

    int n = 0, p = -3, q;
    for (n=-3, q=5; n<++q; n++, q--, p=q%2)
        {
            printf("*** n=%d p=%d q=%d\n", n, p, q);
            if (p==n)
                continue;
            printf("%d: n=%d p=%d q=%d\n", ++n+3, n, p, q);
            if (n>1)
                break;
        }

}





    // int a,b,c,d,K,N,p,q;
    // K = 7;
    // N= 6;
    // p = K;
    // q = N;
    // for(a=0;a<K;a++)
    // {
    //     for(b=0;b<p+q; b++)
    //     {
    //         for(c=0; c<q;c++)
    //         {
    //             printf("_");
    //         }
    //         for(d=p; d>0; d--)
    //         {
    //             printf("%d", d);
    //         }
    //     }
    // p = p - 1;
    // q = q + 1;
    // printf("\n");
    // }
// }
