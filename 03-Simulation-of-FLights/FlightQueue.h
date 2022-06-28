#include <stdio.h>
#include <string.h>

char TakeoffWait[5];  //Array as queue for planes waiting to take-off
char LandingWait[5];  //Array as queue for planes waiting to land
int Ttop = 0;    //Indicates empty top space of Takeoffwait queue
int Tbottom = 0; //Indicates occupied bottom space of Takeoffwait queue

int Ltop = 0;    //Indicates empty top space of Landingwait queue
int Lbottom = 0; //Indicates occupied bottom space of Landingwait queue

void Tpush(char ele); //Function that adds element at the top of queue
char Tpop();  //Function that deletes element at the bottom of the queue
int Tempty();   //Function to check if the queue array is empty

void Lpush(char ele); //Function that adds element at the top of queue
char Lpop();  //Function that deletes element at the bottom of the queue
int Lempty();   //Function to check if the queue array is empty

void Tpush(char ele)
{
    TakeoffWait[Ttop] = ele;
    Ttop++;
}   //end of push()

char Tpop()
{
    char temp;
    temp = TakeoffWait[Tbottom];
    Tbottom++;
    return (temp);
}   //end of pop()

int Tempty()
{
    if (Ttop == Tbottom)
    {
        printf("\nThe Take-off waitlist is empty.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void Lpush(char ele)
{
    LandingWait[Ltop] = ele;
    Ltop++;
}   //end of push()

char Lpop()
{
    char temp;
    temp = LandingWait[Lbottom];
    Lbottom++;
    return (temp);
}   //end of pop()

int Lempty()
{
    if (Ltop == Lbottom)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    /*else
        printf("\nThe Take-off waitlist is not empty.\n");*/
}