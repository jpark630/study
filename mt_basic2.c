//Standard includes. 
#include <stdio.h>
#include <unistd.h>
//Kernel includes. 
#include <pthread.h>
#include <time.h>
#define MAX_RUN_COUNT 3

//Task function prototypes. 
static void *hufsTask1( void * arg )
{
    int runCount = 0;
    printf("hufsTask1 started.\n");
    fflush(stdout);
    while(1) {
                printf("hufsTask1 [%d] is running.\n", ++runCount);
                fflush(stdout);
                sleep(1); // 1 second 
                if(runCount >= MAX_RUN_COUNT) break;
    }
}

static void *hufsTask2( void * arg )
{
    int runCount = 0;
    printf("hufsTask2 started.\n");
    fflush(stdout);
    while(1) {
                printf("hufsTask2 [%d] is running.\n", ++runCount);
                fflush(stdout);
                sleep(2); // 2 second
                if(runCount >= MAX_RUN_COUNT) break;
    }
}

static void *hufsTaskX( void * arg )
{
    int runCount = 0;
    int taskIndex = *(int*) arg ;
    printf("hufsTask%d started.\n", taskIndex);
    fflush(stdout);
    while(1) {
                printf("hufsTask%d [%d] is running.\n", taskIndex, ++runCount);
                fflush(stdout);
                sleep(taskIndex *1);
                if(runCount >= MAX_RUN_COUNT) break;
    }
}
//----------------------------------------------------------

int main( void )
{
        int arg = 5;
        int status[5];
        int i;
        pthread_t thread_t[5];
        int result;

        printf("Start: Jungwon Park, 201801626\n");
/*        printf("Before creating hufsTask1.\n");
        fflush(stdout);
        if( pthread_create( &thread_t[0] , NULL, hufsTask1 ,NULL) < 0){
                printf("Error: was failed to create thread.");
        }

        printf("Before creating hufsTask2.\n");
        fflush(stdout);
        if( pthread_create( &thread_t[1], NULL, hufsTask2, NULL) <0 ){
                printf("Error: was failed to create thread.");
        }

        printf("Before creating hufsTask3.\n");
        fflush(stdout);
        if( pthread_create( &thread_t[2], NULL, hufsTaskX, &arg) < 0 ){
                printf("Error: was failed to create thread.");
        }
*/
    for(int n = 0; n < arg; n++){
        printf("Before creating hufsTask%d.\n", n+1);
        fflush(stdout);
        if(pthread_create((&thread_t[n]), NULL, hufsTaskX, &n)<0){
            printf("Error: was failed to create thread.");
        }
    }
        printf("After creating all tasks: now joining...\n");
        fflush(stdout);

        for(i=0 ; i<5 ; i++)
                pthread_join(thread_t[i],(void**)&status[i]);

    printf("The End: Jungwon Park, 201801626\n");
	return 0;
}
