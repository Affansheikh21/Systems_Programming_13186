#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void Add(){

int counter=0;
    while(counter!=-1) {
char str[30];   //array that is going to store the input
int res=0;
int total=0;
write(STDOUT_FILENO," Enter Numbers: \n", sizeof(" Enter Numbers: \n"));
int sizeofinput = read(STDIN_FILENO,str,sizeof(str));


char * inval;
inval=strchr(str,'0');
if(inval!=NULL){
counter=-1;
break;
}

char * token = NULL;
token = strtok(str," ");

while(token!= NULL){
res = atoi(token);
total = total +res;
token = strtok(NULL, " ");
}

    char display[50];
    sizeofinput = sprintf(display,"%d",total);
    write(STDOUT_FILENO,display,sizeofinput);
    write(STDOUT_FILENO,"\n",sizeof("\n"));
}

    write(STDOUT_FILENO,"exit\n ", sizeof("exit\n "));

}



int main()
{
   Add();
}
