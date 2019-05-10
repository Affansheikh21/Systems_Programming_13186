#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * start_thread(void * message) {

    printf("%s\n",(const char *) message);
    return message;
}

int main(void) {

        pthread_t thing1, thing2;
        const char *message1 = "Thing 1";
        const char *message2 = "Thing 2";

        pthread_create(&thing1,NULL,start_thread,(void *) message1);
        pthread_create(&thing2,NULL,start_thread,(void *) message2);

        // join both the threads to the main thread
        // Joining a thread means that one waits for the other to end,
        // so that you can safely access its result or continue after both have finished their jobs.
        pthread_join(thing1,NULL);
        pthread_join(thing2,NULL);
        return 0;


}
