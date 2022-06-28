#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int userWins = 0, pcWins = 0;
void decider(int user, int pc);
int main() 
{
  int n, userChoice, pcChoice;
  printf("Welcome to the game of Stone, Paper, Scissors!!!");
  printf("\nEnter the number of rounds you want to play:");
  scanf("%d", &n);
  
  for (int i=1; i<=n;i++)
  {
    printf("\n\nROUND %d", i);
    //Displaying 3 choices
    printf("\n(1) Stone\n(2) Paper\n(3) Scissors");
    printf("\nEnter your choice number:");
    scanf("%d",&userChoice);

    //Generate random choice for PC
    srand(time(0));
    pcChoice = rand()%3 +1;  //Value of pcChoice can be either 1, 2 or 3.

    if (pcChoice==1)
    {
      printf("PC Choice: Stone");
    }
    else if (pcChoice ==2)
    {
      printf("PC Choice: Paper");
    }
    else
    {
      printf("PC Choice: Scissors");
    }


    //Deciding Round Winner
    decider(userChoice, pcChoice);
  }
  //Declaring The Overall Winner
  printf("\n\nTotal User Wins: %d", userWins);
  printf("\nTotal PC Wins: %d", pcWins);
  printf("\n\n\nTHE OVERALL WINNER");
  printf("\n******************");
  if (userWins > pcWins)
    printf("\nYOU are the Overall Winner!!!\nCongratualtions!!!");
  
  else if(pcWins > userWins)
    printf("\nPC is the Overall Winner!!!\nBetter Luck Next Time!");
  else if(pcWins == userWins)
  {
    printf("\nBoth Scored the same points!");
    printf("\nPlay again to decide the winner.");
  }
}

//Function to decide the round winner
void decider(int user, int pc)
{
  if (user == 1 && pc==3)   
  {
    printf("\nUser wins the round!");
    userWins+=1;
  }
  else if (user==3 && pc==1)
  {
    printf("\nPC wins the round!");
    pcWins+=1;
  }
  else if (user==3 && pc==2)
  {
    printf("\nUser wins the round!");
    userWins+=1;
  }
  else if(user==2 && pc==3)
  {
    printf("\nPC wins the round!");
    pcWins+=1;
  }
  else if(user==2 && pc==1)
  {
    printf("\nUser wins the round!");
    userWins+=1;
  }
  else if(user==1 && pc==2)
  {
    printf("\nPC wins the round!");
    pcWins+=1;
  }
  else if(user==pc)
  {
    printf("\nIts a draw!");
    printf("\n\tNo one gets the point.");
  }
}


