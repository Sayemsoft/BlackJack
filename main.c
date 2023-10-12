#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main ()
{
        int dealerSum , playerSum ;
        srand(time(0)) ;
        int dealer1 = (rand() % 10) + 1 ;
        int dealer2 = (rand() % 10) + 1 ;
        int player1 = (rand() % 10) + 1 ;
        int player2 = (rand() % 10) + 1 ;
        
        
        printf ("%d\t" , dealer1) ;
        printf ("%d\n" , dealer2) ;
        printf ("%d\t" , player1) ;
        printf ("%d\n" , player2) ;

        dealerSum = dealer1+dealer2 ;
        playerSum = player1+player2 ;
        
        printf ("Dealer = %d\n", dealerSum) ;
        printf ("Player = %d\n", playerSum) ;

        if (dealerSum == 21)
        {
                if (playerSum == 21) printf ("Draw") ;
                else printf ("Dealer Win") ;

                return 0 ;
        }
        else if (playerSum == 21) 
        {
                printf ("Player win") ;
                return 0 ;
        }

        // char call ;        
        // printf ("Hit - H \nStand - S\n") ;
        // scanf ("%c", &call) ;
        int call ;
        call: 
        printf ("Hit - 1 \nStand - 2\n- ") ;
        scanf ("%d", &call) ;       

        //if (call == 'H' || call == 'h')
        if (call == 1)
        {
                        int player3 = (rand() % 10) + 1 ;
                        playerSum = playerSum + player3 ;
                        printf ("New Card = %d\n", player3) ;
                        printf ("Player = %d\n", playerSum) ;

                        if (playerSum > 21)
                        {
                                printf ("Dealer Win") ;
                                return 0 ;
                        }
                        goto call ;
        }

        //if (call == 'S' || call == 's')
        if (call == 2)
        {
                if (dealerSum >= 17)
                {
                        goto compare ;
                }
                else
                {
                        int a = 3 ;
                        while (dealerSum < 17)
                        { 
                                
                                int dealer3 = (rand() % 10) + 1 ;
                                dealerSum = dealerSum + dealer3 ;
                                printf ("%drd Dealer Card = %d\n", a, dealer3) ;
                                printf ("Dealer = %d\n", dealerSum) ;
                                a++ ;
                        }
                        goto compare ;
                }
        }

        compare :
        printf ("\nResult - \n") ;
        printf ("Dealer = %d\nPlayer = %d\n\n", dealerSum, playerSum) ;

        if (dealerSum > 21 || playerSum > dealerSum) printf ("Player Win") ;
        else if (playerSum < dealerSum) printf ("Dealer Win") ;
        else printf ("Draw") ;

        return 0 ;
}