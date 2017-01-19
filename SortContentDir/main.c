#include <stdio.h>
#include <stdlib.h>

int main(int argv,char *args[])
{
    freopen("input.txt","r",stdin);
    //freopen("lsresult.txt","w",stdout);
    if(argv!=2)
    {
        return 1;
    }
    char cmd[1024];
    sprintf(cmd,"ls $HOME/%s>lsresult.txt",args[1]);
    system(cmd);
    freopen("lsresult.txt","r",stdin);
    //freopen("output.txt","wa",stdout);
    sprintf(cmd,"mkdir \"$HOME/%s Sorted\"",args[1]);
    system(cmd);
    char filename[1024];
    while(1)
    {
        if(!scanf("%s",filename))
            break;
        printf("%s",filename);
        int ext=strlen(filename)-4;//a
        if(strcmp(".txt",filename+ext)==0)
        {
            sprintf(cmd,"sort \"$HOME/%s/%s\" -o \"$HOME/%s Sorted/%s\"",args[1],filename,args[1],filename);
            system(cmd);
        }
   }
    return 0;
}
