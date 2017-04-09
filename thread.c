#include<stdio.h>
#include<pthread.h>
void *add(void *abc)
{
	printf("This is a thread and its id is %lu\n", pthread_self());
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, &add, NULL);
	pthread_join(tid, NULL);
	return 0;
}
