#include <stdio.h>

int getNum(void);

int main(void)
{
	printf("Enter a visitors' score\n");
	int visitors = 0;
	visitors = getNum();
	
	printf("The visitors' score is %d\n", visitors);

	printf("Enter the home team's score\n");
	int home = 0;
	home = getNum();

	printf("The home team's score is %d\n", home);

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
