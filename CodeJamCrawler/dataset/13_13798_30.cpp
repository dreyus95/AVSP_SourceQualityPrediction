#include<stdio.h>
int main()
{
    char t[4][4];
    int i,j,n,p,ok,a;
    FILE* f1=NULL;
    FILE* f2=NULL;
    f1=fopen("A-small-attempt1.in","r");
    fscanf(f1,"%d",&n);
    for(a=0;a<n;a++)
    {
        for(i=0;i<4;i++)
        {
            fscanf(f1,"%s",&t[i]);
        }
        ok=0;p=0;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='X' && t[i][1]=='X' && t[i][2]=='X' && t[i][3]=='X') ok=1;
            if(t[0][i]=='X' && t[1][i]=='X' && t[2][i]=='X' && t[3][i]=='X') ok=1;
        }
        if(t[0][0]=='X' && t[1][0]=='X' && t[2][0]=='X' && t[3][0]=='X') ok=1;
        if(t[0][0]=='X' && t[1][1]=='X' && t[2][2]=='X' && t[3][3]=='X') ok=1;
        if(t[0][3]=='X' && t[1][2]=='X' && t[2][1]=='X' && t[3][0]=='X') ok=1;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='O' && t[i][1]=='O' && t[i][2]=='O' && t[i][3]=='O') ok=2;
            if(t[0][i]=='O' && t[1][i]=='O' && t[2][i]=='O' && t[3][i]=='O') ok=2;
        }
        if(t[0][0]=='O' && t[1][0]=='O' && t[2][0]=='O' && t[3][0]=='O') ok=2;
        if(t[0][0]=='O' && t[1][1]=='O' && t[2][2]=='O' && t[3][3]=='O') ok=2;
        if(t[0][3]=='O' && t[1][2]=='O' && t[2][1]=='O' && t[3][0]=='O') ok=2;
        
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='T' && t[i][1]=='X' && t[i][2]=='X' && t[i][3]=='X') ok=1;
            if(t[0][i]=='T' && t[1][i]=='X' && t[2][i]=='X' && t[3][i]=='X') ok=1;
        }
        if(t[0][0]=='T' && t[1][0]=='X' && t[2][0]=='X' && t[3][0]=='X') ok=1;
        if(t[0][0]=='T' && t[1][1]=='X' && t[2][2]=='X' && t[3][3]=='X') ok=1;
        if(t[0][3]=='T' && t[1][2]=='X' && t[2][1]=='X' && t[3][0]=='X') ok=1;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='T' && t[i][1]=='O' && t[i][2]=='O' && t[i][3]=='O') ok=2;
            if(t[0][i]=='T' && t[1][i]=='O' && t[2][i]=='O' && t[3][i]=='O') ok=2;
        }
        if(t[0][0]=='T' && t[1][0]=='O' && t[2][0]=='O' && t[3][0]=='O') ok=2;
        if(t[0][0]=='T' && t[1][1]=='O' && t[2][2]=='O' && t[3][3]=='O') ok=2;
        if(t[0][3]=='T' && t[1][2]=='O' && t[2][1]=='O' && t[3][0]=='O') ok=2;
        
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='X' && t[i][1]=='T' && t[i][2]=='X' && t[i][3]=='X') ok=1;
            if(t[0][i]=='X' && t[1][i]=='T' && t[2][i]=='X' && t[3][i]=='X') ok=1;
        }
        if(t[0][0]=='X' && t[1][0]=='T' && t[2][0]=='X' && t[3][0]=='X') ok=1;
        if(t[0][0]=='X' && t[1][1]=='T' && t[2][2]=='X' && t[3][3]=='X') ok=1;
        if(t[0][3]=='X' && t[1][2]=='T' && t[2][1]=='X' && t[3][0]=='X') ok=1;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='O' && t[i][1]=='T' && t[i][2]=='O' && t[i][3]=='O') ok=2;
            if(t[0][i]=='O' && t[1][i]=='T' && t[2][i]=='O' && t[3][i]=='O') ok=2;
        }
        if(t[0][0]=='O' && t[1][0]=='T' && t[2][0]=='O' && t[3][0]=='O') ok=2;
        if(t[0][0]=='O' && t[1][1]=='T' && t[2][2]=='O' && t[3][3]=='O') ok=2;
        if(t[0][3]=='O' && t[1][2]=='T' && t[2][1]=='O' && t[3][0]=='O') ok=2;
        
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='X' && t[i][1]=='X' && t[i][2]=='T' && t[i][3]=='X') ok=1;
            if(t[0][i]=='X' && t[1][i]=='X' && t[2][i]=='T' && t[3][i]=='X') ok=1;
        }
        if(t[0][0]=='X' && t[1][0]=='X' && t[2][0]=='T' && t[3][0]=='X') ok=1;
        if(t[0][0]=='X' && t[1][1]=='X' && t[2][2]=='T' && t[3][3]=='X') ok=1;
        if(t[0][3]=='X' && t[1][2]=='X' && t[2][1]=='T' && t[3][0]=='X') ok=1;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='O' && t[i][1]=='O' && t[i][2]=='T' && t[i][3]=='O') ok=2;
            if(t[0][i]=='O' && t[1][i]=='O' && t[2][i]=='T' && t[3][i]=='O') ok=2;
        }
        if(t[0][0]=='O' && t[1][0]=='O' && t[2][0]=='T' && t[3][0]=='O') ok=2;
        if(t[0][0]=='O' && t[1][1]=='O' && t[2][2]=='T' && t[3][3]=='O') ok=2;
        if(t[0][3]=='O' && t[1][2]=='O' && t[2][1]=='T' && t[3][0]=='O') ok=2;
        
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='X' && t[i][1]=='X' && t[i][2]=='X' && t[i][3]=='T') ok=1;
            if(t[0][i]=='X' && t[1][i]=='X' && t[2][i]=='X' && t[3][i]=='T') ok=1;
        }
        if(t[0][0]=='X' && t[1][0]=='X' && t[2][0]=='X' && t[3][0]=='T') ok=1;
        if(t[0][0]=='X' && t[1][1]=='X' && t[2][2]=='X' && t[3][3]=='T') ok=1;
        if(t[0][3]=='X' && t[1][2]=='X' && t[2][1]=='X' && t[3][0]=='T') ok=1;
        for(i=0;i<4;i++)
        {
            if(t[i][0]=='O' && t[i][1]=='O' && t[i][2]=='O' && t[i][3]=='T') ok=2;
            if(t[0][i]=='O' && t[1][i]=='O' && t[2][i]=='O' && t[3][i]=='T') ok=2;
        }
        if(t[0][0]=='O' && t[1][0]=='O' && t[2][0]=='O' && t[3][0]=='T') ok=2;
        if(t[0][0]=='O' && t[1][1]=='O' && t[2][2]=='O' && t[3][3]=='T') ok=2;
        if(t[0][3]=='O' && t[1][2]=='O' && t[2][1]=='O' && t[3][0]=='T') ok=2;
        if(ok==0)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(t[i][j]=='.') p=1;
                }
            }
        }
        f2=fopen("out.txt","a");
        if(ok==1) fprintf(f2,"Case #%d: X won\n",a+1);
        if(ok==2) fprintf(f2,"Case #%d: O won\n",a+1);
        if(ok==0 && p==0) fprintf(f2,"Case #%d: Draw\n",a+1);
        if(ok==0 && p==1) fprintf(f2,"Case #%d: Game has not completed\n",a+1);
        fclose(f2);
    }
    fclose(f1);
    return 0;
}
        
