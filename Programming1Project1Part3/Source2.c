#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

//The password is password

int main() {
	char studentID[15], studIDarr[15][10], destcodearr[10], password[20] = { 'p', 'a', 's', 's', 'w', 'o', 'r', 'd' }, passattempt[20];
	char destinationCode, success, confirmed, menuopt = '1', correctbooking;
	float tcost, deposit, balance, totaldeposit, depositarr[10], totaloutstanding = 0, balancearr[10];
	int flagDestCode, x, flagAllClear, totalJ, totalM, totalA, bookingNumber, times3 = 1, totalConfirmed, passattempts = 0, successpass = 0, flagdeposit = 0;

	//Flags and incramenting values are set
	totalJ = 0;
	totalM = 0;
	totalA = 0;
	bookingNumber = -1;
	totalConfirmed = 0;
	totaldeposit = 0;

	while (passattempts < 3 && successpass == 0) {
		printf("Enter the password:\n");
		gets(passattempt);
		passattempts++;
		if (strcmp(passattempt, password) == 0) {
			successpass = 1;
			system("cls");
		}
		else {
			system("cls");
			printf("Incorrect password!\n\n");
		}
		
	}


	if (successpass == 1) {
		system("cls");
		printf("=============================================================================\n");
		printf("\t\t\tMain menu\n");
		printf("Enter your option:\n1. Book Tour\n2. Display Scheduled Tours\n3. Confirm Booking\n4. Exit\n");
		printf("=============================================================================\n");
		menuopt = _getch();
		while (menuopt != '4') {


			switch (menuopt) {
			case '1':
				system("cls");
				if (bookingNumber < 9) {
					printf("\n\nEnter the student ID (enter 'XXX' or 'xxx' to cancel booking)\n");
					gets(studentID);
					if (strcmp(studentID, "") == 0) {
						gets(studentID);
					}

				}
				else {
					printf("\nThe limit of 10 bookings has been reached. N0 more bookings may be made.\n");
					system("pause");
				}
				while ((strcmp(studentID, "XXX") != 0) && (strcmp(studentID, "xxx") != 0) && bookingNumber < 9) {
					flagDestCode = 0;
					tcost = 0;
					flagAllClear = 0;
					printf_s("\n\nWhich location is to be booked?\n");
					printf_s("J - Jollygood Park\tM - Mum's River\tA - Adventurama\n");
					destinationCode = _getch();

					if ((destinationCode == 'J') || (destinationCode == 'M') || (destinationCode == 'A') || destinationCode == 'j' || destinationCode == 'm' || destinationCode == 'a') {
						flagDestCode = 1;
					}
					if (flagDestCode == 1) {
						if (destinationCode == 'J' || destinationCode == 'j') {
							tcost = 1700;
						}
						else {
							if (destinationCode == 'M' || destinationCode == 'm') {
								tcost = 3300;
							}
							else {
								tcost = 7000;
							}
						}
						printf("\nThe total fee is $%.2f\n", tcost);
						printf("\nEnter the deposit\n");
						scanf_s(" %f", &deposit);
						if (deposit >= 0) {
							flagdeposit = 1;

						}
					}

					if (flagdeposit == 1) {
						bookingNumber++;
						strcpy_s(studIDarr[bookingNumber], sizeof(studIDarr[bookingNumber]), studentID);
						balancearr[bookingNumber] = (tcost - deposit);
						if (balancearr[bookingNumber] < 0) {
							printf("\nThe deposit made was more than the total cost of the booking. The balance was set to 0.\n");
							balancearr[bookingNumber] = 0;
						}
						destinationCode = toupper(destinationCode);
						destcodearr[bookingNumber] = destinationCode;
						depositarr[bookingNumber] = deposit;
						totaldeposit += deposit;
						totaloutstanding += balancearr[bookingNumber];
						switch (destinationCode)
						{
						case 'J':
							totalJ++;
							break;
						case 'M':
							totalM++;
							break;
						case 'A':
							totalA++;
							break;
						default:
							break;
						}


					}
					else {
						printf("Invalid data was entered. Please ensure the information entered is valid.\n\n\n\n");
						system("pause");
					}
					flagdeposit = 0;
					flagDestCode = 0;
					
					system("cls");
					printf("\n\n\n\nEnter the student ID (enter 'XXX' or 'xxx' to cancel booking)\n");
					gets(studentID);
					if (strcmp(studentID, "") == 0) {
						gets(studentID);
					}


				}
				break;
			case '2':
				system("cls");
				printf("\n\nAll Current bookings\n");
				if (bookingNumber >= 0) {
					for (x = 0; x <= bookingNumber; x++) {
						printf("===================================================\n");
						printf("Booking Number: %i\n", x + 1);
						printf("Student ID: ");
						puts(studIDarr[x]);
						printf("Deposit made: $%.2f\n", depositarr[x]);
						printf("Balance remaining for confirmation $%.2f\n", balancearr[x]);


					}
					printf("===================================================\n");
					system("pause");
					printf("\n\n\n\n\n\n\n\nTotal bookings for\nJollygood Park - %i\nMum's River - %i\nAdventurama - %i\n", totalJ, totalM, totalA);
					printf("Total deposits: $%.2f\nTotal outstanding: $%.2f\n", totaldeposit, totaloutstanding);
					printf("===================================================\n");
					system("pause");
				}
				else {
					printf("No Current bookings made. Select Option 1 to create a booking.\n");
					system("pause");
				}
				break;
			case '3':
				system("cls");
				success = 0;
				correctbooking = 'n';
				printf("Enter the Student ID \n");

				gets(studentID);
				puts(studentID);
				if (strcmp(studentID, "") == 0) {
					gets(studentID);
				}
				//The buffer accepting studentID would overflow every second time this section is used. A counter is used to call the gets function every second time option 3 of the menu is selected. These bugs honestly get wierder for every line of code I have

				for (x = 0; x <= bookingNumber; x++) {
					if (strcmp(studIDarr[x], studentID) == 0) {
						success = 1;
						printf("\nBooking Number: %i\n", x + 1);
						printf("Student ID: ");
						puts(studIDarr[x]);
						printf("Deposit made: $%.2f\n", depositarr[x]);
						printf("Balance remaining for confirmation $%.2f\n", balancearr[x]);
						printf("\nIs this the correct record? (y/n)\n");
						correctbooking = _getch();
						if (correctbooking == 'y') {
							break;
						}

					}

				}
				if (correctbooking == 'y') {
					printf("\nEnter the amount to be deposited.\n");
					scanf_s(" %f", &deposit);
					depositarr[x] = deposit + depositarr[x];
					balancearr[x] = balancearr[x] - deposit;
					totaloutstanding -= deposit;
					totaldeposit += deposit;
					if (balancearr[x] <= 0) {
						printf("\nThe booking has been confirmed.\n");//
					}
					else {
						printf("\n$%0.2f is needed to confirm the booking.\n", balancearr[x]);
					}
					if (balancearr[x] < 0) {
						printf("\nThe total deposit made is more than the total cost of the tour. The balance will be set to 0.\n");
						depositarr[x] = depositarr[x] + balancearr[x];
						totaldeposit += balancearr[x];
						totaloutstanding -= balancearr[x];
						balancearr[x] = 0;
					}
				}
				else {
					printf("\nThe booking could not be found!\n");
				}

			}
			system("pause");
			system("cls");
			printf("=============================================================================\n");
			printf("\t\t\tMain menu\n");
			printf("Enter your option:\n1. Book Tour\n2. Display Scheduled Tours\n3. Confirm Booking\n4. Exit\n");
			printf("=============================================================================\n");
			menuopt = _getch();
		}
		printf("\n\n\nThe program will now exit.\n");
		system("pause");
	}
	else {
		printf("You have entered an incorrect password 3 times. The program will now exit.\n");
		system("pause");
	}
}


