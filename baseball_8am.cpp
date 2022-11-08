#include <stdio.h>

int getNum(void);

int main(void)
{
	int inning = 1;
	int visitorScore = 0;
	int homeScore = 0;
	
	
	// loop for 9 innings
	while (inning <= 9)
	{
		
		printf("Inning % d:\n", inning);
		

		// get a visitors' score
		printf("Enter a visitors' score\n");
		int visitors = 0;
		visitors = getNum();

		// keep track of the total visitors' score
		visitorScore += visitors;

		printf("The visitors' score for this inning is %d\n", visitors);
		printf("The visitors' total score is %d\n", visitorScore);

		// get a home team score
		printf("\nEnter the home team's score\n");
		int home = 0;
		home = getNum();

		// keep track of the total home score
		homeScore += home;

		printf("The home team's score is %d\n", home);
		printf("The home total score is %d\n", homeScore);

		++inning;

		// space out the output with two blank lines after each inning
		printf("\n\n");
	}
	
	// determine who won the game
	if (homeScore > visitorScore)
	{
		// home team won
		printf("\n\nhome won %d-%d\n", homeScore, visitorScore);
	}
	else
	{
		// visiting team won
		printf("\n\nvisitor won %d-%d\n", visitorScore, homeScore);
	}

	return 0;
}

#pragma warning(disable: 4996)
int getNum(void)
{
	/* we will see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: indent and brace this function consistent with
	your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	 * corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}
