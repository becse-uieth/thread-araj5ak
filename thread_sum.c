# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

void * add(void * a)
{
	int  sum;
        int * d;
        d = (int *) a;
        sum = d[0]+ d[1];
        return (void *)sum;
}
int main ()
{
        pthread_t tid;
        int a[2], c;
        printf ("Enter two Numbers\n");
	scanf ("%d%d", &a[0], &a[1]);
	pthread_create (&tid, NULL, &add, a);
        pthread_join (tid, (void *)&c);
	printf ("sum = %d\n", c);
        return 0;
}

