#include<stdio.h>
int main()
{
    int t,i,j,w,on,pt,ii,jj,x,o,k=1;
    char d[5][5];
    scanf("%d\n",&t);
    while(k<=t)
    {
        on=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%c\n",&d[i][j]);
                //printf("%c",d[i][j]);
                if(d[i][j]=='.')
                    on=1;
                  
            }
        }
            o=x=0;
            for(i=0;i<4;i++)
            {
                 if( (d[i][0]=='X' || d[i][0]=='T') && (d[i][1]=='X' || d[i][1]=='T') && (d[i][2]=='X' || d[i][2]=='T') && (d[i][3]=='X' || d[i][3]=='T') )
                      x=1;
                 //printf("%c%c%c%c\n",d[i][0],d[i][1],d[i][2],d[i][3]);
            }
            for(i=0;i<4;i++)
            {
                 if( (d[0][i]=='X' || d[0][i]=='T') && (d[1][i]=='X' || d[1][i]=='T') && (d[2][i]=='X' || d[2][i]=='T') && (d[3][i]=='X' || d[3][i]=='T') )
                      x=1;
            }
            if( (d[0][0]=='X' || d[0][0]=='T') && (d[1][1]=='X' || d[1][1]=='T') && (d[2][2]=='X' || d[2][2]=='T') && (d[3][3]=='X' || d[3][3]=='T') )
                  x=1;
            if( (d[0][3]=='X' || d[0][3]=='T') && (d[1][2]=='X' || d[1][2]=='T') && (d[2][1]=='X' || d[2][1]=='T') && (d[3][0]=='X' || d[3][0]=='T') )
                  x=1;
                  
                  
            for(i=0;i<4;i++)
            {
                 if( (d[i][0]=='O' || d[i][0]=='T') && (d[i][1]=='O' || d[i][1]=='T') && (d[i][2]=='O' || d[i][2]=='T') && (d[i][3]=='O' || d[i][3]=='T') )
                      o=1;
            }
            for(i=0;i<4;i++)
            {
                 if( (d[0][i]=='O' || d[0][i]=='T') && (d[1][i]=='O' || d[1][i]=='T') && (d[2][i]=='O' || d[2][i]=='T') && (d[3][i]=='O' || d[3][i]=='T') )
                      o=1;
            }
            if( (d[0][0]=='O' || d[0][0]=='T') && (d[1][1]=='O' || d[1][1]=='T') && (d[2][2]=='O' || d[2][2]=='T') && (d[3][3]=='O' || d[3][3]=='T') )
                  o=1;
            if( (d[0][3]=='O' || d[0][3]=='T') && (d[1][2]=='O' || d[1][2]=='T') && (d[2][1]=='O' || d[2][1]=='T') && (d[3][0]=='O' || d[3][0]=='T') )
                  o=1;
            if(o==1)
                 printf("Case #%d: O won\n",k);
            else if(x==1)
                 printf("Case #%d: X won\n",k);
            else if(on==1)
                 printf("Case #%d: Game has not completed\n",k);
            else
                 printf("Case #%d: Draw\n",k);
            k++;
    }
    return 0;
}