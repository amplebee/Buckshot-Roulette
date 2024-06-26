#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//eliminating magic numbers in the code
#define MIN_BLANKS 1
#define MAX_BLANKS 5
#define MIN_AMMO 1
#define MAX_AMMO 5
#define STARTING_LIVES 3
#define CHAMBER 6

//creates the chamber of rounds in the game 
int Turn(int chamber, int blanks, int liveRounds) {
    // Random chance
    int bulletChamber = rand() % (blanks + liveRounds) + 1;
    
    // Check if the bullet chamber matches the chamber being fired
    if (bulletChamber <= blanks) {
        // If the bullet chamber matches a blank, return 0
        return 0;
    } else {
        // If not, return 1 
        return 1;
    }
}

int main() {
    
    
    // Initialize and create variables
    int currentPlayer = 1; // Player 1 starts first
    int chamber;
    int choice;
    int player1Lives = STARTING_LIVES;
    int player2Lives = STARTING_LIVES;
    int blanks;
    int liveRounds;
    
    printf("Buckshot Roulette\n");
    
    // Generate a new amount of blanks and live rounds
        blanks = rand() % (MAX_BLANKS - MIN_BLANKS + 1) + MIN_BLANKS;
        liveRounds = CHAMBER - blanks;
        
    
     while (player1Lives > 0 && player2Lives > 0) {
         
         //resets round after all live rounds are fired
         if (liveRounds == 0 ){
        blanks = rand() % (MAX_BLANKS - MIN_BLANKS + 1) + MIN_BLANKS;
        liveRounds = CHAMBER - blanks;
        }
        

        printf("\nPlayer 1 lives: %d\n", player1Lives);
        printf("Player 2 lives: %d\n", player2Lives);
        printf("There are %d blanks and %d live rounds.\n", blanks, liveRounds);

        printf("\nPlayer %d's turn.\n", currentPlayer);
        printf("Enter 1 to try your luck or 2 to try your opponents luck: ");
        scanf("%d", &choice);

        

        if (choice == 1) {
            // Random chamber to fire
             chamber = rand() % CHAMBER + 1;
         
            if (Turn(chamber, blanks, liveRounds)) {
                // If the bullet chamber matches, the player loses a life
                printf("Player %d has lost a life!\n", currentPlayer);
                if (currentPlayer == 1) {
                    player1Lives--;
                    liveRounds --;
                    // Switches player
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
                } else {
                    player2Lives--;
                    liveRounds --;
                    // Switches player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                }
            } else {
                // If the bullet chamber doesn't match, player survives
                printf("You survived!\n");
                // Switches player
            currentPlayer = (currentPlayer);
                
                
                blanks --;
            }
        } else if (choice == 2) {
            // Random chamber to fire
                chamber = rand() % CHAMBER + 1;
            
            if (Turn(chamber, blanks, liveRounds)) {
                // If the chamber matches the opponent loses a life
                printf("Your opponent has lost a life!\n");
                liveRounds--;
                if (currentPlayer == 1) {
                    player2Lives--;
                    // Switches player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                } else {
                    player1Lives--;
                    // Switches player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                }
            } else {
                // If the chamber doesn't match the opponent survives
                printf("Your opponent survived!\n");
                blanks --;
                // Switches player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        
        } 
        else {
            printf("Invalid choice. Please enter 1 or 2.\n");
            continue;
        }

        
    }
    
    

    // Displays the winner
    if (player1Lives > 0) {
        printf("\nPlayer 1 wins!\n");
    } else {
        printf("\nPlayer 2 wins!\n");
    }
    
    return 0;
}
