#include <stdio.h>
#include <stdlib.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <errno.h>
int main()
// This code will create a new file with the name new file, and will grant rwx access to all the users
{
 int fd = open("/home/affan/Documents/newfile",O_CREATE,0777);

    if  (fd == -1) {
    printf("%d",errno);
    perror("Error: ");
    }

    else {
        printf("%s","File opened successfully");

    }

}


