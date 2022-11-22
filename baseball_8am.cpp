#include <stdio.h>

int getNum(void);

int main(void)
{
	int inning = 1;
	int visitorScore = 0;
	int homeScore = 0;
	bool rainOccurred = false;
	
	
	// loop for 9 innings
	while (inning <= 9)
	{
		// display the inning
		printf("Inning % d:\n", inning);
		

		// top half of the inning
		// get a visitors' score
		printf("Enter a visitors' score\n");
		int visitors = 0;
		visitors = getNum();

		// check for rainout
		if (visitors < 0)
		{
			printf("Rain stopped the game\n");
			rainOccurred = true;
			break;
		}

		// keep track of the total visitors' score
		visitorScore += visitors;

		printf("The visitors' score for this inning is %d\n", visitors);
		printf("The visitors' total score is %d\n", visitorScore);


		// determine if the visitors have lost the game because
		//	they are losing after the top half of the 9th inning
		if ((inning == 9) && (homeScore > visitorScore))
		{
			break;
		}


		// bottom half of the inning
		// get a home team score
		printf("\nEnter the home team's score\n");
		int home = 0;
		home = getNum();

		// check for rainout
		if (home < 0)
		{
			printf("Rain stopped the game\n");
			rainOccurred = true;
			break;
		}

		// keep track of the total home score
		homeScore += home;

		printf("The home team's score for this inning is %d\n", home);
		printf("The home total score is %d\n", homeScore);


		// we are done the inning so increase the inning and space out the output
		++inning;

		// space out the output with two blank lines after each inning
		printf("\n\n");
	}
	
	// determine who won the game
	if (rainOccurred == false)
	{
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
