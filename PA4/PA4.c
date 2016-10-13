/*
Name: Tristan Underwood
Lab Section: 3
Assignment:PA4
Date: 2OCT16
*/

#include "PA4.h"

/* 
Function: Runs the program so that main doesn't have to.
Date Created:2OCT16
Date Last Modified:2OCT16
Description: Runs the program
Returns: Nothing
Preconditions: Start of the program.
Postconditions:none
*/

int run_app(void)
{
int run_again = 1; /// variable to loop whole game 1 = run again anything else = quit

while(run_again == 1)
{
double bank = 0.0 ;//orignal players bank 
double bank2 = 0.0;// total in bank
double wager = 0.0;// amount player wants to wager
int die_value1 = 0, die_value2 = 0;// dies to be assing a random 1-6 number
int total_die_value = 0;   //total die number
int win_loss  = -1;/// winloss value
int win_loss2 = 0; //next round 
int point_value = 0; 
int start = 0;/// boolean for menu function return to start game
int number_rolls = 0;

srand((unsigned int) time(NULL)); // seed the random number generator
//This is a loop for the start menu
while((start != 1) && (start !=2))
{
start = menu();
}
if(start == 2)/// A way to exit the program
{
return(0);
}

bank = get_bank_balance();// gets the orginal balance
//first run
wager = get_wager_amount();
die_value1 = roll_die(); //roll die 1
die_value2 = roll_die();//roll die 2
total_die_value = calculate_sum_dice(die_value1, die_value2);
point_value = total_die_value; 

win_loss =  is_win_loss_or_point(total_die_value);
bank2 = adjust_bank_balance (bank,wager,win_loss);
number_rolls = number_rolls  + 1;

printf("Roll# %d\nYou rolled a %d and %d for a total of %d.\n", number_rolls,die_value1, die_value2, total_die_value);

chatter_messages(number_rolls, win_loss, bank, bank2, wager);


//Loop that plays the game
while (win_loss == -1)
{
wager = get_wager_amount();
die_value1 = roll_die(); //roll die 1
die_value2 = roll_die();//roll die 2
total_die_value = calculate_sum_dice(die_value1, die_value2);
win_loss =  is_point_loss_or_neither(total_die_value, point_value);
bank2 = adjust_bank_balance (bank2,wager,win_loss);
number_rolls = number_rolls  + 1;
printf("Your point is %d\n", point_value);
printf("Roll# %d \nYou rolled a %d and %d for a total of %d.\n", number_rolls,die_value1, die_value2, total_die_value);

chatter_messages(number_rolls, win_loss, bank, bank2, wager);

}
	
printf(" Press 1 to go back to the Menue and 0 to Exit game");
scanf("%d", &run_again);
}

return (0);
}



/* 
Function:void print_game_rules(void)
Date Created:20OCT16
Date Last Modified:20OCT16
Description: Just prints the game rules 
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
void print_game_rules(void)
{

printf("A player rolls two dice. Each die has six faces.\nThese faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
printf("If the sum is 7 or 11 on the first throw, the player wins.\nIf the sum is 2, 3, or 12 on the first throw (called 'craps'),");
printf("the player loses (i.e. the house wins).\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
printf("To win, you must continue rolling the dice until you 'make your point'.\nThe player loses by rolling a 7 before making the point.\n");

}

/* 
Function: get_bank_balance(void)
Date Created:20OCT16
Date Last Modified:20OCT16
Description:  Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
double get_bank_balance(void)
{
double bank_balance = 0.0;

printf("Please give your initial bank balance (in dollars i.e.$100.00) from which wagering will be added or subtracted.\n");
scanf("%lf", &bank_balance);
return (bank_balance);
}

/* 
Function:get_wager_amount
Date Created:20OCT16
Date Last Modified:20OCT16
Description:  - Prompts the player for a wager on a particular roll. The wager is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
double get_wager_amount(void)
{
double wager = 0.0;
printf("Please enter your wager (in dollars i.e $100.00).\n");
scanf("%lf", &wager);
return (wager);

}

/* 
Function:roll_die
Date Created:20OCT16
Date Last Modified:20OCT16
Description:  - Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/

int roll_die(void)
{
	// generate a number 1 - 6
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}


/* 
Function:calculate_sum_dice(int die1_value, int die2_value)
Date Created:20OCT16
Date Last Modified:20OCT16
Description: - Sums together the values of the two dice and returns the result. Note: this result may become the player's point in future rolls.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
int calculate_sum_dice(int die1_value, int die2_value)
{
int total_die_value = 0;

total_die_value = die1_value + die2_value;

return (total_die_value);

}
/* 
Function:is_win_loss_or_point (int sum_dice))
Date Created:20OCT16
Date Last Modified:20OCT16
Description: - Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is returned. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/

 int is_win_loss_or_point (int sum_dice)
 
{
	if ((sum_dice == 7 ) || (sum_dice == 11))
{

	return (1);
}
	else if((sum_dice == 2) ||(sum_dice == 3) || (sum_dice == 12))
	{
	return (0);
	}
	
		else 
		{
		return (-1);
		}
	






}
 
 /* 
Function:is_point_loss_or_neither(int sum_dice, int point_value)
Date Created:20OCT16
Date Last Modified:20OCT16
Description:- Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/

 int is_point_loss_or_neither(int sum_dice, int point_value)
 
 {


 if(sum_dice == point_value)
 {
 return (1);
 }
 else if (sum_dice == 7)
 {
 return (0);
 }
 else 
 {
 return (-1);
 }
} 

  /* 
Function: adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
Date Created:20OCT16
Date Last Modified:20OCT16
Description:- If add_or_subtract is 1, then the wager amount is added to the bank_balance. If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance. Otherwise, the bank_balance remains the same. The bank_balance result is returned.
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
 
 double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
 {
 
 
 if(add_or_subtract == 1)
 {
 
 bank_balance =  bank_balance + wager_amount;
 return (bank_balance);
 }
  else if ((add_or_subtract == 0) || (add_or_subtract == -1) )
  {
  
   bank_balance =  bank_balance - wager_amount;
    return (bank_balance);
   }
   
   else
   {
   return (bank_balance);
   }
 

 
  }
 
    /* 
Function:menu(void)
Date Created:02OCT16
Date Last Modified:02OCT16
Description:- gives a  menu by cases
Input parameters
Returns: Nothing
Preconditions: none
Postconditions:none
*/
 int menu(void)
 {
 
int menu_num = 0;

printf("                       WELCOME TO A GAME OF CRAPS!!\n");
 printf("****************************************************************************\n");
 printf("*									   *\n");
 printf("*	Type 1  To Print the Game Rules!                                   *\n");
 printf("*	Type 2  To Play The Game!					   *\n");
 printf("*	Type 3  To Exit The Game!					   *\n");
 printf("*									   *\n");
 printf("****************************************************************************\n");
 scanf("%d", &menu_num);
 
 switch (menu_num)
 {
 case 1: print_game_rules();
 	break;
 case 2: return (1);
 	break;
 case 3: return (2);
 	break;
 default: printf("Invalid option try again");
 menu();
 
}
return (0);
 }
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
 
 void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager)
 
 {
 
 
 
 	// if Statements to print if you won lost  could make into a function
	if (win_loss_neither == 1) 
	{
	printf("You Won!!\n");
	printf("You wagered %.2lf, so your bank balance is now %.2lf", wager,current_bank_balance);
	}
	else if (win_loss_neither == -1)
	{
		printf("You wagered %.2lf, so your bank balance is now %.2lf\n", wager,current_bank_balance);
	 	printf("Your on roll %d Go on to another round!!\n", number_rolls );
	}
	else if (win_loss_neither == 0) 
	{
	printf("You wagered %.2lf, so your bank balance is now %.2lf", wager,current_bank_balance);
	printf("Craps!! You lost!!\n");
	}
  
 
 }
 
 
 
 



