#include<stdio.h>

int fix(int y,int m,int q)
{
    int h;
    if(m==1||m==2) return fix(y-1,m+12,q);
    h=(q+((26*(m+1))/10)+y+(y/4)+6*(y/100)+(y/400))%7;
    return h;
}

int main()
{
    int q,m,y,h,i,j,count=0;
    printf("Enter year:");
    scanf("%d",&y);
    printf("Enter month(1-12):");
    scanf("%d",&m);
    printf("\nCalender for:\n\n");
    if(m==1) printf("JANUARY,%d",y);
    else  if(m==2) printf("FEBRUARY,%d",y);
    else  if(m==3) printf("MARCH,%d",y);
    else  if(m==4) printf("APRIL,%d",y);
    else  if(m==5) printf("MAY,%d",y);
    else  if(m==6) printf("JUNE,%d",y);
    else  if(m==7) printf("JULY,%d",y);
    else  if(m==8) printf("AUGUST,%d",y);
    else  if(m==9) printf("SEPTEMBER,%d",y);
    else  if(m==10) printf("OCTOBER,%d",y);
    else  if(m==11) printf("NOVEMBER,%d",y);
    else  if(m==12) printf("DECEMBER,%d",y);
    printf("\n\n SUN MON TUE WED THU FRI SAT\n");
    for(i=1; i<=6; i++)
    {
        if(fix(y,m,1)==i)
        {
            count=i;
            for(j=1; j<count; j++)
            {
                printf("    ");
            }
            break;
        }
    }
    if(fix(y,m,1)==0)
    {
        count=7;

        for(i=1; i<=24; i++)
        {
            printf(" ");
        }
    }

    for(q=1; q<=31; q++)
    {
        printf("%4d",q);
        if((q+count-1)%7==0) printf("\n");
        if((y%4!=0||y%100==0)&&y%400!=0&&m==2&&q==28) break;
        if((y%4==0||y%400==0)&&m==2&&q==29) break;
        if((m==4||m==6||m==9||m==11)&&q==30) break;
    }
    printf("\n");
}
