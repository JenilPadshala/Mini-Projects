/*
    Author: Jenil Padshala | AP21110010064
    Project Title: Simulation of Flights
*/
#include "FlightQueue.h"    //Header file containing all the operational functions for take-off and landing queues

int main()
{
    int currentTime = 0,    //Stores current unit of time
        endTime;            //Stores total units of time
    char id,                //Stores id of flight at request
        temp;               //Stores id of flight landing or taking-off for temporary purposes

    /*Enter total units of time for the simulation to run*/
    printf("\t\tWELCOME TO FLIGHT SIMULATION\n\n");
    printf("Enter Total Units of time:");
    scanf("%d", &endTime);

    while (currentTime < endTime)
    {
        /*Adding a plane to landing waitlist*/
        char choice1;
        printf("Do you want to add a plane Landing waitlist? Y or N\n");
        scanf(" %c", &choice1);
        if (choice1 == 'Y')
        {
            printf("\nEnter Flight Id:");
            scanf(" %c", &id);
            Lpush(id);
        }//end of if()

        /*Choose action to perform for a plane*/
        int choice2;
        printf("\nChoose an action to perform...");
        printf("\n1. Landing\n2. Take-off\n3. Stay Idle\n");
        printf("Enter your choice:");
        scanf("%d", &choice2);

        /*Landing a plane*/
        if (choice2 == 1)   
        {
            if (!Lempty())
            {
                temp = Lpop();
                Tpush(temp);
                printf("\nT= %d\tSTATUS: Flight %c is landing.\n", currentTime, temp);
                printf("----------------------------------------\n");
                currentTime++;
            }//end of if
            else
            {
                printf("No landing requests pending at the moment.");
                printf("----------------------------------------\n");
            }//end of else
        }//end of if

        /*Plane Take-off*/
        else if (choice2 == 2)
        {
            if (Lempty())
            {
                if (!Tempty())
                {
                    temp = Tpop();
                    printf("\nT= %d\tSTATUS: Flight %c is taking off.\n", currentTime,temp);
                    printf("----------------------------------------\n");
                    currentTime++;
                }//end of if
                else
                {
                    printf("No take-off requests pending at the moment.\n");
                    printf("----------------------------------------\n");
                }//end of else
            }
            else
            {
                printf("Few landing requests are pending. Take-off is not permitted till all flights have landed.\n");
                printf("----------------------------------------\n");
            }//end of else
        }// end of else if

        /*Idle Runway*/
        else
        {
            printf("\nT= %d\tSTATUS: The runway is IDLE.\n", currentTime);
            printf("----------------------------------------\n");
            currentTime++;
        }//end of else

        
    }
}