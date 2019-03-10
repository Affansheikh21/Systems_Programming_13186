#include <stdio.h>
#include <stdlib.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <errno.h>
       #include <unistd.h>
int main()
{
 int fd = open("/home/affan/Documents/practice_file",O_CREAT | O_RDWR,0777);

    if  (fd == -1) {
    printf("%d",errno);
    perror("Error: ");
    }

    char * buff[1];
    int r=10;
    int len=66; // size of file 66 bytes
        while(len!=0 && r!=0){

        r = read(fd,buff,len);



            if(r==-1) {
            printf("%d",errno);
            perror("Error:");
            }



        else {

        int w = write(STDOUT_FILENO,buff,r);
            if(w == -1) {
            perror("Error: ");

            }
            len-= r;




        }

        }


}
