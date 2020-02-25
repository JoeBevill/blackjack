#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;
//Function that sets the cards for blackjack
int getCards()
{
   //Empty starting value
   int c;
   //Sets the random seed to the current time
   srand (time(NULL));
   //Actual random cards
   int card1=rand()%10+1;
   int card2=rand()%10+1;
   //Combines the two cards
   c=card1+card2;
   return c;

}
//Function for the dealer's cards
int dealerCards()
{
     //Empty starting value
   int d;
   //Sets the random seed to the current time
   srand (time(NULL));
   //Actual random cards
   int card1=rand()%10+1;
   int card2=rand()%10+1;
   //Combines the two cards
   d=card1+card2;
   return d;

}


//Main luwup(loop)
int main()
{
    game:
    //Sets the s varible to the getCards function
    int s=getCards();
    cout<<"Your number is, "<<s<<endl;
    //All the code for the userAction
    userAction:
    //Determines what the user wants to do
    cout<<"Would you like to hit or stay?"<<endl;
    string userChoice;
    cin>>userChoice;
    //hit will change the s varible to add another "card"
    if (userChoice=="hit")
    {
        s=s+rand()%10;
        if (s==21)
        {
            cout<<"You hit 21, BlackJack!"<<endl;
            goto retry;
        }
        else if (s>=21)
        {
           cout<<"Your number is, "<<s<<endl<<"You have busted"<<endl;
           goto retry;
        }
        else if (s<=21)
        {
            cout<<"Your number is, "<<s<<endl;
            goto userAction;
        }
    }
   //Staying will start the dealer code
    else if(userChoice== "stay")
    {
       cout<<"Let's see if i win"<<endl;
       goto dealerAi;
       dealerAi:
           int g=dealerCards();
           goto winner;
           winner:
          //chacks to see if the dealer is less than s and not 21 It goes back to winner if true
           if (g<=s and g!=21)
           {
               g=g+rand()%10+1;
               goto winner;
           }
           //checks to see if the dealer has 21
           else if (g>=21){
            cout<<"The dealer has busted with, "<<g<<endl;
            goto retry;
           }
           //Checks to see if the dealer has more than s
           else if (g>=s)
           {
               cout<<"Yay the dealer wins"<<endl<<"The dealer's number was, "<<g<<endl;
               goto retry;
           }
    }
    else
    {
     cout<<"Sorry, I don't understand"<<endl;
     goto userAction;
    }
    retry:
        cout<<"Would you like to try again?"<<endl;
        string userAnswer;
        cin>>userAnswer;
        if (userAnswer == "y" or userAnswer == "yes"){
            goto game;
            string userAnswer = " ";
        }
        else{
            return 0;
        }

}
