/*
Programmer: Tristan Underwood                                            
Class: CptS 121; Lab Section 3                                                           
Programming Assignment: PA4     
Date: 2OCT16
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

/* 
Function:int run_app(void);
Date Created:02OCT16
Date Last Modified:02OCT16
Description: runs the program
Input parameters
Returns: Nothing
Preconditions: Start of the program.
Postconditions:none
*/

int run_app(void);


/* 
Function:void print_game_rules(void)
Date Created:02OCT16
Date Last Modified:02OCT16
Description: Just prints the game rules 
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
void print_game_rules(void);

/* 
Function: get_bank_balance(void)
Date Created:02OCT16
Date Last Modified:02OCT16
Description:  Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
double get_bank_balance(void);


/* 
Function:get_wager_amount
Date Created:02OCT16
Date Last Modified:02OCT16
Description:  - Prompts the player for a wager on a particular roll. The wager is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
double get_wager_amount(void); 

/* 
Function:roll_die()
Date Created:02OCT16
Date Last Modified:02OCT16
Description:  - Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
int roll_die(void); 
/* 
Function:calculate_sum_dice(int die1_value, int die2_value)
Date Created:02OCT16
Date Last Modified:02OCT16
Description: - Sums together the values of the two dice and returns the result. Note: this result may become the player's point in future rolls.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
int calculate_sum_dice(int die1_value, int die2_value); 

/* 
Function:is_win_loss_or_point (int sum_dice))
Date Created:02OCT16
Date Last Modified:02OCT16
Description: - Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is returned. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returne
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/

 int is_win_loss_or_point (int sum_dice); 
 
 /* 
Function:is_point_loss_or_neither(int sum_dice, int point_value)
Date Created:02OCT16
Date Last Modified:02OCT16
Description:- Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/

 int is_point_loss_or_neither(int sum_dice, int point_value); 
  /* 
Function:adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
Date Created:02OCT16
Date Last Modified:02OCT16
Description:- If add_or_subtract is 1, then the wager amount is added to the bank_balance. If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance. Otherwise, the bank_balance remains the same. The bank_balance result is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
 
 double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract); 
 
   /* 
Function menu(void)
Date Created:02OCT16
Date Last Modified:02OCT16
Description:- gives a  menu by cases
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
 int menu(void);
    /* 
Function: chatter_messages()
Date Created:02OCT16
Date Last Modified:02OCT16
Description:- - Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, and whether or not the player just won his roll. The parameter win_loss_neither indicates the result of 
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
 
 void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager); 

