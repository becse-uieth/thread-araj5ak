#include <stdio.h>
#include <pthread.h>

void * add ( void * a)
{
	int sum;
	int * b;
	b = (int *)a;
	sum = b[0] + b[1];
	return (void *)sum;
}
int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	int  a[2], c, d;
	a[0] = 2;
	a[1] = 3;
	pthread_create (&tid, &attr, &add, a);
	d = pthread_join (tid, (void *)&c);
	pthread_attr_destroy (&attr);
	if(d != 0)
		printf("Thread not created\n");
	else
		printf("%d\n", c);
	return 0;
}
