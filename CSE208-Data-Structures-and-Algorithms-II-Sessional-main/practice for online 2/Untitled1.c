#include<stdio.h>

int main()
{
    int x, max=-1,sum=0,pos=0,s,i=0,j,t,flg=0;

    char c;
    while(scanf(" %c", &c)!=0)
    {
        if(c == 'q')
            break;
        if(flg==1)
        {
            flg = 0;
            x = c - '0';
            x = -1*x;
        }
        else if(c == '-')
        {
            flg=1;
        }
        else
        {
            x = c - '0';
        }

        if(c>='0' && c<='9')
        {
            if(x > 0)
            {
                t=1;
                pos++;
                sum=sum+x;
                i++;

            }
            else if(x<0)
            {
                t=0;
                if(max < pos)
                {
                    max = pos;
                    s = sum;
                    j=i-max;
                    sum=0;
                    pos=0;

                }
                i++;
                pos=0;
                sum=0;

            }
        }


    }


    if(t==1)
    {
        max = pos;
        s = sum;
        j=i-max;
    }
    printf("Length of LPS:%d\nSum of LPS:%d\nStarting Position of LPS:%d(Assuming that position starts from 0)",max,s,j);



    return 0;
}
