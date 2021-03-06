#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int main() {
	char studentID[15], fName[15], lName[15], uniName[40], password[20] = { 'p', 'a', 's', 's', 'w', 'o', 'r', 'd' }, passattempt[20];
	char destinationCode, success, confirmed;
	float travelDay, travelMonth, travelYear, contactNumber, numpeople, discountRate, discountAmt, cDay, cMonth, cYear, tcost, ocost, deposit, balance, discount;
	int flagDestCode, flagDate, flagCDate, flagDateAfter, flagContact, flagNumPeople, flagAllClear, totalNumPeople, totalJ, totalM, totalA, bookingNumber, totalConfirmed, passattempts = 0, successpass = 0, menuopt;

	//Flags and incramenting values are set
	totalJ = 0;
	totalM = 0;
	totalA = 0;
	totalNumPeople = 0;
	bookingNumber = 0;
	totalConfirmed = 0;

	while (passattempts < 3 && successpass == 0) {
		printf("Enter the password:\n");
		gets(passattempt);
		passattempts++;
		if (strcmp(passattempt, password) == 0) {
			successpass = 1;
		}
	}

	
	printf("=============================================================================\n");
	printf("\t\t\tMain menu\n");
	printf("Enter your option:\n1. Book Tour\n2. Display Scheduled Tours\n3. Confirm Booking\n4. Exit\n");
	printf("=============================================================================\n");
	scanf_s(" %i", &menuopt);
	while (menuopt > 4 || menuopt < 1) {
		printf("Please enter a valid option from the menu\n");
		scanf_s(" %i", &menuopt);
	}
	//Takes student ID
	printf("Enter the student ID (enter 'XXX' or 'xxx' to cancel booking)\n");
	gets(studentID);
	gets(studentID);

	while ((strcmp(studentID, "XXX") != 0) && (strcmp(studentID, "xxx") != 0)) {
		flagDestCode = 0;
		flagDate = 0;
		flagCDate = 0;
		flagDateAfter = 0;
		flagContact = 0;
		flagNumPeople = 0;
		tcost = 0;
		ocost = 0;
		flagAllClear = 0;
		success = 'N';
		confirmed = 'N';


		//The current date is taken to ensure that the date of travel is on or after it
		printf("The date is to be enteres as numeric values.\n");
		printf_s("Enter the current day:\n");
		scanf_s(" %f", &cDay);
		printf_s("Enter the current month:\n");
		scanf_s(" %f", &cMonth);
		printf_s("Enter the current year:\n");
		scanf_s(" %f", &cYear);


		//The data entered for the current date is validated here
		//The numbers entered must be positive whole numbers and the month must lay between 1 and 12

		if ((fmod(cYear, 1) == 0) && (cYear > 0) && (fmod(cDay, 1) == 0) && (cDay > 0)) {
			if ((fmod(cMonth, 1) == 0) && (cMonth > 0) && (cMonth < 13)) {
				//If the month is February, this code checks the criteria of a leap year
				//Criteria for a leap year � the year is divisible by 400 OR divisible by 4 and NOT 100
				if (cMonth == 2) {
					if (fmod(cYear, 400) == 0) {
						if (cDay < 30) {
							flagCDate = 1;
						}
					}
					else {
						if ((fmod(cYear, 100) == 0) && (cDay < 29)) {
							flagCDate = 1;
						}
						else {
							if ((fmod(cYear, 100) != 0) && (fmod(cYear, 4) == 0) && (cDay < 30)) {
								flagCDate = 1;
							}
							else {
								if (cDay < 29) {
									flagCDate = 1;
								}
							}
						}
					}
				}
				else {
					//If it is a month that contains 30 days, the day entered must be less than 31
					//Otherwise, the month must have less than 32 days
					if ((cMonth == 4) || (cMonth == 6) || (cMonth == 9) || (cMonth == 11)) {
						if (cDay < 31) {
							flagCDate = 1;
						}
					}
					else {
						if (cDay < 32) {
							flagCDate = 1;
						}
					}
				}
			}
		}


		//Personal information for the person making the booking is taken here
		if (flagCDate == 1) {
			printf_s("Enter your First Name: \n");
			//Buffer was overflowing with only one gets(). A second fixed the issue
			gets(fName);
			gets(fName);

			printf_s("Enter your Last Name: \n");
			gets(lName);

			printf_s("Enter the name of your University\n");
			gets(uniName);


			//Location to be visited is taken here
			printf_s("Which location would you like to visit?\n");
			printf_s("J - Jollygood Park\tM - Mum's River\tA - Adventurama\n");
			scanf_s(" %c", &destinationCode);


			//The date of the tour is taken here
			printf_s("Enter the date that the tour is to be booked\n");
			printf_s("Enter the year. (yyyy)\n");
			scanf_s(" %f", &travelYear);
			printf_s("Enter the month. (mm)\n");
			printf_s("01 - Jan\t02 - Feb\t03 - Mar\t04 - APR\tetc.\n");
			scanf_s(" %f", &travelMonth);
			printf_s("Enter the day. (dd)\n");
			scanf_s(" %f", &travelDay);



			//The contact number of the person is taken here
			printf_s("Enter a contact number. (eg. 8761234567)\n");
			scanf_s(" %f", &contactNumber);


			// The number of participants is taken here
			printf_s("Enter the number of people to be on the tour. (minimum - 5, maximum - 25)\n");
			scanf_s(" %f", &numpeople);
		}



		//The destination code is validated here
		if ((destinationCode == 'J') || (destinationCode == 'M') || (destinationCode == 'A')) {
			flagDestCode = 1;


			//The date of the tour is validated in the same way as the current date was
			if ((fmod(travelYear, 1) == 0) && (travelYear > 0) && (travelMonth > 0) && (fmod(travelDay, 1) == 0)) {
				if ((fmod(travelMonth, 1) == 0) && (travelMonth < 13) && (travelDay > 0)) {
					if (travelMonth == 2) {
						if (fmod(travelYear, 400) == 0) {
							if (travelDay < 30) {
								flagDate = 1;
							}
						}
						else {
							if (fmod(travelYear, 100) == 0) {
								if (travelDay < 29) {
									flagDate = 1;
								}
							}
							else {
								if (fmod(travelYear, 4) == 0) {
									if (travelDay < 30) {
										flagDate = 1;
									}
								}
								else {
									if (travelDay < 29) {
										flagDate = 1;
									}
								}
							}
						}
					}
					else {
						if ((travelMonth == 4) || (travelMonth == 6) || (travelMonth == 9) || (travelMonth == 11)) {
							if (travelDay < 31) {
								flagDate = 1;
							}
						}
						else {
							if (travelDay < 32) {
								flagDate = 1;
							}
						}
					}
				}
			}
		}




		//This section checks that the date of the tour has not passed yet and travel code is valid
		if ((destinationCode == 'J') || (destinationCode == 'M') || (destinationCode == 'A')) {
			flagDestCode = 1;
		}

		if ((travelYear > cYear) || (travelYear == cYear && travelMonth > cMonth) || (travelYear == cYear && travelMonth == cMonth && travelDay >= cDay)) {
			flagDateAfter = 1;
		}


		//This ensures that the contact number has ten digits
		if (((contactNumber / 1000000000) >= 1) && ((contactNumber / 10000000000) < 1)) {
			flagContact = 1;
		}



		//This ensures that the number of persons attending is between 5 and 25
		if ((numpeople >= 5) && (numpeople <= 25) && (fmod(numpeople, 1) == 0)) {
			flagNumPeople = 1;
		}


		//Initialize discount rate
		discountRate = 0;


		if ((numpeople >= 10) && (numpeople <= 15)) {
			discountRate = .05;
		}
		else {
			if ((numpeople > 15) && (numpeople <= 25)) {
				discountRate = .1;
			}
		}


		//Ensure input is valid then checks the initial cost of the tour
		//The discount to be received is calculated and excluded from the cost
		if ((flagDestCode == 1) && (flagNumPeople == 1)) {
			if (destinationCode == 'J') {
				tcost = (1500 * numpeople);
				ocost = (200 * numpeople) + 1000;
			}
			else {
				if (destinationCode == 'M') {
					tcost = (2700 * numpeople);
					ocost = (600 * numpeople) + 1200;
				}
				else {
					tcost = (3000 * numpeople);
					ocost = (4000 * numpeople);
				}
			}
			discount = tcost * discountRate;
			tcost = tcost + ocost - discount;
		}


		//Check all flags have a value of 1 and that the cost is greater than 0
		//Gives all clear to allow deposit to be collected

		if ((flagDestCode == 1) && (flagNumPeople == 1) && (flagDate == 1) && (flagCDate == 1)) {
			if ((flagDateAfter == 1) && (flagContact == 1) && (tcost > 0)) {
				flagAllClear = 1;
			}
		}



		//Deposit is collected here if all clear is given a value of 1
		if (flagAllClear == 1) {
			printf_s("The total cost of the trip is $%.2f\n", tcost);
			printf_s("Enter the deposit paid \n");
			scanf_s(" %f", &deposit);
			if (deposit >= 0) {
				balance = tcost - deposit;
				success = 'B';
			}
		}


		//Checks if tour is confirmed
		if (balance <= 0) {
			confirmed = 'Y';
		}
		else {
			confirmed = 'N';
		}



		//If the booking was sucessful, the invoice is generated. Otherwise, an error message is printed
		if (success == 'B') {
			if (destinationCode == 'J') {
				totalJ = totalJ + 1;
			}
			else {
				if (destinationCode == 'M') {
					totalM = totalM + 1;
				}
				else {
					totalA = totalA + 1;
				}
			}

			printf_s("\n\n\nINVOICE\n");
			printf_s("========================================\n");
			printf_s("Student ID - ");
			puts(studentID);
			printf_s("Name \n\t\t\t\t");
			puts(fName);
			printf_s("\t\t\t\t");
			puts(lName);
			printf_s("\nDestination Code - \t\t%c\n", destinationCode);
			printf_s("Number of attendees - \t\t%.0f\t\t\n", numpeople);
			printf_s("Cost of tour - \t\t\t$%.2f\t\t\n", tcost + discount);
			if (discount > 0) {
				printf_s("Discount - \t\t\t$%.2f\t\t\n", discount);
			}
			printf_s("Deposit - \t\t\t$%.2f\n", deposit);
			printf_s("Balance Remaining - \t\t$%.2f\t\n", balance);
			if (confirmed == 'Y') {
				printf_s("Booking confirmed\n");
				totalConfirmed++;
			}
			else {
				printf_s("Tour booked but not confirmed\n");
			}

			bookingNumber++;
			printf_s("Booking number - \t\t%d\n", bookingNumber);
			printf_s("========================================\n");

			totalNumPeople += numpeople;
		}
		else {
			printf_s("One or more fields contained invalid data. The tour was not booked\n");
		}
		printf_s("Enter the student ID (enter 'XXX' or 'xxx' to cancel the booking)\n");
		//Buffer was overflowing with one gets() function. A secong one was added to alleviate the problem
		gets(studentID);
		gets(studentID);

	}

	printf_s("\n\n\n========================================\n");
	printf_s("Total number of Confirmed Bookings - \t\t%d\n", totalConfirmed);
	printf_s("Total number of bookings for Jollygood Park - \t%d\n", totalJ);
	printf_s("Total number of bookings for Adventurama - \t%d\n", totalA);
	printf_s("Total number of bookings for Mum's River - \t%d\n", totalM);
	//Booking number has the same value as the total number of bookings made
	printf_s("Average number of persons per booking - \t%.2f\n", (float)totalNumPeople / (float)(bookingNumber));
	printf_s("========================================\n");




	system("pause");
	return 0;
}
