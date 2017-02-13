#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv,char *args[])
{
    //freopen("input.txt","r",stdin);
    //freopen("lsresult.txt","w",stdout);
    if(argv!=2)
    {
        return 1;
    }
    char cmd[1024];
    sprintf(cmd,"ls $HOME/%s>lsresult.txt",args[1]);
    system(cmd);
    FILE *fp=fopen("lsresult.txt","r");
    if(feof(fp))
    printf("something\'s bad\n");
    //freopen("output.txt","wa",stdout);
    sprintf(cmd,"mkdir \"$HOME/%s Sorted\"",args[1]);
    system(cmd);
    char filename[1024],f1[1024]="______";
    while(1)
    {
        fscanf(fp," %[^\n]s",filename);
        if(strcmp(f1,filename)==0)
            break;
        //printf("%s\n",filename);
        int ext=strlen(filename)-4;//a
        if(strcmp(".txt",filename+ext)==0||strcmp(".dat",filename+ext)==0)
        {
            sprintf(cmd,"sort -n \"$HOME/%s/%s\" -o \"$HOME/%s Sorted/%s\"",args[1],filename,args[1],filename);
            system(cmd);
        }
        strcpy(f1,filename);
   }
    return 0;
}
