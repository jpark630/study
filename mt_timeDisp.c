#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#define THREAD_NUM 1

#include <termios.h>
#include <fcntl.h>
/*
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
 
*/
//Task function prototypes.
static void *disp_time() {
    time_t rawt;
    struct tm *t;
    time(&rawt);
    t = localtime(&rawt);
    printf("Time: %02d:%02d:%02d\r", t->tm_hour, t->tm_min, t->tm_sec);
    fflush(stdout);
}
//----------------------------------------------------------
int main( void )
{
    char c, ent;
    pthread_t tid[1];
    pthread_attr_t attr[1];
    int status[1];
    printf("Jungwon Park, 201801626\n");
    printf("Press any key and Enter to quit the program.... \n");
    fflush(stdout);
    
    pthread_attr_init(&attr[0]);
    pthread_create((&tid[0]), &attr[0], disp_time, NULL);
   // while(1) {
    //    disp_time();
      //  sleep(1); // 1 second
      //
    //}
    scanf("%c%c",&c,&ent);
    if(ent=='\n') {
        pthread_join(tid[0],NULL);
    };
    fflush(stdout);
    printf("Bye~\n");
    return 0;
}

