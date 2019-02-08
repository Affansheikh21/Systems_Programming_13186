#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
int main()
{

/*Read integer values from one file and apply arithmetic operations on them and write solution to another file
*/
// write means display or store in file
// read means take values from input or read from file
int f1 = open("/home/affan/Documents/100MB.txt",  O_RDWR);
int f2 = open("/home/affan/Documents/destination", O_RDWR | O_CREAT,0777);
    if (f1 == -1) {
    write(STDOUT_FILENO,errno,sizeof(errno));
    perror("Error: ");
    }

    double total_time;
    clock_t start, end;
char * buff[1];

int readinput = read(f1,buff,1);
int a = write(f2,buff,readinput);
start = clock();
while(readinput >0){
        readinput = read(f1,buff,1);
        write(f2,buff,readinput);
        fsync(f2);

}
end = clock();

total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\nTime taken to copy 100MB data from source file to destination file with buffer size 1000: %f seconds", total_time);
close(f1);
close(f2);

}
