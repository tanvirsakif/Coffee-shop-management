#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>




//Restaurant globals
int token = 0,tokens[50], payment_counter=0;

int main_page();
int menu_order();
void Bill_show(int arID[],int arqty[],int counter);
void Bill_Payment();


int main(void)
{

    char k,j,n,d;
    k = main_page();

    if(k=='1')
    {
        menu_order();

    }

    else if(k=='2')
    {
        Bill_Payment();
    }

    else if(k=='3')
    {
        int billClear = 1;
        system("cls");
        system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  Play Bytes Restaurant\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tThis session order recieved : %d\n\n",token);
        printf("\t\t\tThis session bill paid      : %d\n\n",payment_counter);
        for(int i = 0; i < 50; i ++)
        {
            if(tokens[i] != 0)
            {
                printf("\t\t\t\tYet to pay          : %dtk (token %d)\n\n",tokens[i], i);
                billClear = 0;
            }
        }
        if(!billClear)
        {
            printf("\n\n\t\t\t\tYou are about to leave without clearing payment.");
            getch();
            Bill_Payment();
        }

        Sleep(2000);
        return 0;
    }

 }


int main_page()
{
    int i;
    system("title Play Bytes Restaurant");
    system("cls");
    system("color 0B");

    printf("\n\n\n\n\n\t\t\t\t      @@_@-\n\t\t\t\t\t    `'*'`\tWelcome\n\t\t\t\t\t\t\t  to\n\t\t\t\t\t\t  Play Bytes Restaurant\t\t \n\t\t\t\t\t\t\t\t\t`'*'`-@@_@\n\n");
    printf("\n\n\n\n\t\t\t\t\t\t      BITE THE BYTE. (^_^)\n\n                       ");
    for (i=0;i<30;i++)
     {
        printf("  ~");
     }
    printf("\n\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    Select any of them -          $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    1. New Order.                 $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    2. Bill Payment.              $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    3. Exit.                      $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");





    char n;
    while(1)
    {
        fflush(stdin);
        printf("\n\n\n                         Enter Your Choice: ");
        scanf("%c",&n);
        fflush(stdin);
        if(n != '1' && n != '2' && n != '3')
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
            continue;
        }
        else break;
    }
    return n;
}


int menu_order()
{

    int arID[100],decision,arqty[100],Bill[100],counter=0;
    work:
    system("cls");
    system("color 4F");
    printf("\n\t\t\t\tFOOD MENU\n\t\t\t\t---------\n");

    printf("\n\tSides :\n\n");
    printf("\t1. French Fries (150gm)                .......................... 90/=\t  \n");
    printf("\t2. Chicken Fingers(5PCS)               .......................... 130/=\t  \n");

    printf("\n\tCoffee & Tea :\n\n");
    printf("\t3. Hot coffee .......................... 50/=\n");
    printf("\t4. Hot Chocolate Coffee .......................... 70/=\n");
    printf("\t5. Milk tea .......................... 20/=\n");
    printf("\t6. Iced tea .......................... 30/=\n");
    printf("\t7. Lemon tea .......................... 25/=\n");
    printf("\t8. Orange tea .......................... 25/=\n");
    printf("\t9. Black Coffee .......................... 55/=\n");
    printf("\t10. Cold Coffee ...................  60/=\n");
    printf("\t11. Chocolate Cold Coffee ....................  65/=\n");
    printf("\t12. Iced Caramel Coffee ..................  60/=\n");
    printf("\t13. Capacino .....  70/=\n");

    printf("\n\tDRINKS :\n\n");
    printf("\t14. Coca-Cola      ........................ 40/=\n");
    printf("\t15. Pepsi          ........................ 40/=\n");
    printf("\t16. Mountain Dew   ........................ 40/=\n");
    printf("\t17. Water          ........................ 15/=\n");
    printf("\n\n\tOrder your dish: (Enter 0 to finish order)\n");
    for(;;)
    {
        counter++;
        give_arID_again:
        printf("\t Enter Food ID: ");
        scanf("%d",&arID[counter-1]);
        if(arID[counter-1]>17)
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
            goto give_arID_again;
        }

        if(arID[counter-1]==0)
        {
            break;
        }
        give_arqtry_again:
        printf("\t Enter Quantity: ");
        scanf("%d",&arqty[counter-1]);
        if(arqty[counter-1]<0)
        {
         printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
         goto give_arqtry_again;
        }

    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\tThanks for your order. We are getting ready the dishes. Press 1 to see your bill ");

    scanf("%d",&decision);
    printf("\n\n\n\n\n\n\n\n");

    counter--;

    if(decision==1)
    {
        Bill_show(arID,arqty,counter);
    }

    else if(decision==2)
    {
       goto work;
    }

    else if(decision==3)
    {
        main();
    }

}

void Bill_show(int arID[],int arqty[],int counter)
{

    int n;
    system("cls");
    system("color B0");

    int i,sum=0;
    int costs[100]={90,130,50,70,20,30,25,25,55,60,65,60,70,40,40,40,15};
    char items[100][100]={"French Fries (150gm)","Chicken Fingers(5PCS)","Hot coffee","Hot Chocolate Coffee","Milk tea","Iced tea","Lemon tea","Orange tea","Black Coffee","Cold Coffee","Chocolate Cold Coffee","Iced Caramel Coffee","Capacino","Coca-Cola","Pepsi","Mountain Dew","Water"};
    printf("\n\nYour Bill:\n\n\n\t\tItem(s)\t\t\t\t     Quantity\t\t\t Cost\n\n\n\n");

    for(i=0;i<counter;i++)
    {
        printf("\t%2d. %-30s ________\t%-5d piece(s) ____ %7d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
        sum=sum+(costs[arID[i]-1]*arqty[i]);
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    token ++;
    tokens[token]=sum;
    printf("\tYour token number is %d. Use this token while paying the bill.\n\n\n\n\n\t\t\t",token);
    //printf("<enter (1) to give another order>\n\n\t\t\t<enter (2) to go to the main menu>");

    printf("\n\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    Select any of them -          $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    1. to give another order.     $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    2. to go to the main menu.    $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


    do{
        printf("\n\n\t\n\t\t\tEnter your choice: ");
        scanf("%d",&n);
        if(n != 1 && n != 2 )
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");

        }
    }while(n != 1 && n != 2 );


    if(n==1)
    {
        menu_order();
    }

    else if(n == 2)
    {

        printf("\n\n\t\n\t\t\tPay your bill from main menu.");
        getch();
        main();
    }

}

void Bill_Payment()
{

    int k,i,cash,changer,n;
    redo:
    system("cls");
    system("color 3F");
    printf("\n\n\n\t\t\tEnter your token number: ");
    scanf("%d",&k);
    printf("\n\t\t\tYour bill is = %d",tokens[k]);
    if(tokens[k]) payment_counter++;


    work:
            printf("\n\t\t\tPay your bill: ");
            scanf("%d",&cash);
    changer = cash-tokens[k];
    if(changer == 0)
    {
        printf("\n\t\tThanks for your payment. Have a great day!\n");
    }
    else if (changer<0)
    {
        system("cls");
        printf("\n\t\t\tAmount is not sufficient. :(\n\t\tPlease pay the fair price of your bill\n");
        goto work;
    }
    else
    {
        printf("\n\n\n\t\tHere is your change : (%d - %d) = %d Tk.\n\t\t  ",cash,tokens[k],changer);

            for(i=0;i<19;i++)
            {
                printf("_");
            }
            if(changer>=1000 )
                {printf("\n\t\t1000 Tk. note(s) = %d\n",changer/1000);
                changer=changer%1000;}
            if(changer>=500 && changer<1000)
            {printf("\n\t\t 500 Tk. note(s) = %d\n",changer/500);
            changer=changer%500;}
            if(changer>=100 && changer<500)
            {printf("\n\t\t 100 Tk. note(s) = %d\n",changer/100);
            changer= changer%100;}
            if(changer>=50 && changer<100)
            {printf("\n\t\t  50 Tk. note(s) = %d\n",changer/50);
            changer=changer%50;}
             if(changer>=10 && changer<50)
            {printf("\n\t\t  10 Tk. note(s) = %d\n",changer/10);
            changer=changer%10;}
            if(changer>=5 && changer<10)
            {printf("\n\t\t   5 Tk. note(s) = %d\n",changer/5);
            changer=changer%5;}
            if(changer>=2 && changer<5)
            {printf("\n\t\t   2 Tk. note(s) = %d\n",changer/2);
            changer=changer%2;}
            if(changer>=1 && changer<2)
            {printf("\n\t\t   1 Tk. note(s) = %d\n",changer/1);
            changer=changer%1;}

            printf("\t\t  ");
            for(i=0;i<19;i++)
            {
                printf("_");
            }

        printf("\n\n\n\n\n\t\t\tThanks for your payment.\n\t\t\t    Have a great day!\n");


        tokens[k] = 0;

    }

    tokens[k] = 0;


    printf("\n\n\t\t\t<Enter (1) to pay another bill.>\n\t\t\t<Enter (2) to go back main menu>\n\n\n\t\t\tEnter your choice: \t");
        scanf("%d",&n);
        if(n==2)
        {
            main();
        }
        else if(n==1)
        {
           goto redo;
        }
}

