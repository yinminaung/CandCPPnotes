#include "stdio.h"
#include "stdlib.h"

/* This miniBank project is just for fun.
   No built-in functions, rather than input & ouput functions and exit function,  are utilized in this program.
   User-defined functions are not also included.
 */
int main() {

    // preloaded database 
    int acceptedUsers = 100;
    int currentUsers = 5; // the current users in a bank
    long userIds[100];
    long userPasswords[100];
    long userBalances[100];
    for(int i = 0; i < acceptedUsers; i++) {  // prefill with some users
        userIds[i] = 0;
        userPasswords[i] = 0;
        userBalances[i] = 0;
    }

    userIds[0] = 111111;
    userIds[1] = 222222;
    userIds[2] = 333333;
    userIds[3] = 444444;
    userIds[4] = 555555;

    userPasswords[0] = 10000;
    userPasswords[1] = 20000;
    userPasswords[2] = 30000;
    userPasswords[3] = 40000;
    userPasswords[4] = 50000;

    userBalances[0] = 100000;
    userBalances[1] = 500000;
    userBalances[2] = 600000;
    userBalances[3] = 10000000;
    userBalances[4] = 1000000000000;

    // register or login loop 
    int registerSuccess = 0;
    int invalid_input_1 = 0;
    char login_or_register_option;

    // log in
    int invalid_input_2 = 0;
    int userIndex; // to connect user's id, password and balance
    long userId;
    long userPassword;
    long userBalance;
    int idFound = 0;

    // log in password loop
    int passwordIncorrect = 0;

    // bank processing after successful login
    char bank_process_option;
    int repeat_bank_process = 0;

    // money saving
    long savingAmount = 0;
    int passwordIncorrect2 = 0;

    //money withdraw
    long withdrawAmount = 0;
    int insufficientAmount = 0;
    int passwordIncorrect3 = 0;

    // money transfer 
    int wrongReceiver = 0;
    int passwordIncorrect4 = 0;
    long receiverId = 0;
    int receiverIndex = 0;
    int insufficientAmount2 = 0;
    long transferAmount = 0; 

    /* Registration */
    int invalidId = 0;
    int invalidPassword = 0;
    long newPassword  = 0;
    long confirmPassword = 0;
    int invalidConfirmPassword = 0;
    char newOrConfirmOption;

    printf("\n\n\t\t\tWarmly welcome from Community Bank!\n\n");
    do {
        registerSuccess = 0;
        invalid_input_1 = 0;
        invalid_input_2 = 0;
        idFound = 0;
        passwordIncorrect = 0;
        repeat_bank_process = 0;
        passwordIncorrect2 = 0;
        insufficientAmount = 0;
        passwordIncorrect3 = 0;
        wrongReceiver = 0;
        passwordIncorrect4 = 0;
        insufficientAmount2 = 0;
        transferAmount = 0;
        invalidId = 0;
        invalidPassword = 0;
        invalidConfirmPassword = 0;

        printf("Press 1 to log in your account.\n");
        printf("Press 2 to register a new account: ");
        scanf(" %c", &login_or_register_option);

        if (login_or_register_option == '1') {
            // log in
            printf("\tPlease enter your id : ");
            scanf("%d", &userId);

            // search the id in the database
            for(int i = 0; i < acceptedUsers; i++) {
                if(userId == userIds[i]) {
                    userIndex = i;
                    idFound = 1;
                }
            }

            if (idFound) {
                do {
                    // loop until password is correct
                    printf("\tPlease enter your password :");
                    scanf("%d", &userPassword);
                    
                    //check password
                    if (userPassword == userPasswords[userIndex]) {
                        passwordIncorrect = 0;
                        printf("\t\tLog in successfully.\n");
                        do {

                            repeat_bank_process = 0;

                            printf("\t\tPress 1 to save your money,\n");
                            printf("\t\tPress 2 to withdraw your money.\n");
                            printf("\t\tPress 3 to transfer to another account.\n");
                            printf("\t\tPress 4 to check your balance.\n");
                            printf("\t\tPress 5 to exit the program: ");
                            scanf(" %c", &bank_process_option);

                            switch (bank_process_option)
                            {
                            case '1':
                                printf("\t\t\tEnter the amount of money you want to save : ");
                                scanf("%d", &savingAmount);
                                do { 

                                    printf("\t\t\tPlease enter your password : ");
                                    scanf("%d", &userPassword);
                                    if (userPassword == userPasswords[userIndex]) {
                                        // updating the user's balance
                                        userBalances[userIndex] += savingAmount;
                                        printf("\t\t\t\tYour updated balance is %d kyats.\n", userBalances[userIndex]);
                                        passwordIncorrect2 = 0;
                                        // repeating bank process
                                        repeat_bank_process = 1;
                                    } else {
                                        printf("\t\t\t\tIncorrect Password! Try again.\n");
                                        passwordIncorrect2 = 1;
                                    }
                                } while (passwordIncorrect2);
                                break;
                            case '2':
                                do { 
                                    insufficientAmount = 0; 

                                    printf("\t\t\tEnter the amount of money you want to withdraw : ");
                                    scanf("%d", &withdrawAmount);

                                    if (withdrawAmount > userBalances[userIndex]) {
                                        printf("\t\t\t\tYou don't have enough money in your account. Please Try again.\n");
                                        insufficientAmount = 1;
                                    } else { 
                                        do { 
                                            passwordIncorrect3 = 0;

                                            printf("\t\t\tPlease Enter your password : ");
                                            scanf("%d", &userPassword);
                                            if (userPassword == userPasswords[userIndex]) {
                                                userBalances[userIndex] -= withdrawAmount;
                                                printf("\t\t\t\tYou successfully withdraw %d kyats.\n", withdrawAmount);
                                                printf("\t\t\t\tYour updated balance is %d kyats.\n", userBalances[userIndex]);
                                                insufficientAmount = 0;
                                                repeat_bank_process = 1;
                                            } else {
                                                printf("\t\t\t\tIncorrect Password, please try again.\n");
                                                passwordIncorrect3 = 1;
                                            }

                                        } while(passwordIncorrect3);
                                    }
                                } while (insufficientAmount);
                                break;
                            case '3':
                                do {
                                    wrongReceiver  = 0;
                                    idFound = 0;

                                    printf("\t\t\tPlease enter the id of the account you want to transfer : ");
                                    scanf("%d", &receiverId);
                                    
                                    // searching receivers'id in database
                                    for (int j = 0; j<acceptedUsers; j++) {
                                        if(receiverId == userIds[j]) {
                                            idFound = 1;
                                            receiverIndex = j;
                                        }
                                    } 
                                    if(idFound) {
                                        do {
                                            passwordIncorrect4 = 0;

                                            printf("\t\t\tPlease enter your password : ");
                                            scanf("%d", &userPassword);

                                            if (userPassword == userPasswords[userIndex]) {
                                                // ask the amount of money to transfer
                                                do {
                                                    insufficientAmount2 = 0;

                                                    printf("\t\t\tEnter the amount of money you want to transfer : ");
                                                    scanf("%d", &transferAmount);
                                                    if (transferAmount > userBalances[userIndex]) {
                                                        printf("\t\t\t\tYou don't have enough money in your account. Please try again.\n");

                                                        insufficientAmount2 = 1;
                                                    } else {
                                                        // subtract from user's balance and add that to the reciever's amount
                                                        userBalances[userIndex] -= transferAmount;
                                                        userBalances[receiverIndex] += transferAmount;

                                                        printf("\t\t\t\tTransfer process successful!\n");
                                                        printf("\t\t\t\tYour updated balance is %d kyats.\n", userBalances[userIndex]);
                                                        repeat_bank_process = 1;
                                                        insufficientAmount2 = 0;
                                                    }
                                                } while (insufficientAmount2);

                                                passwordIncorrect4 = 0;
                                            } else {
                                                printf("\t\t\t\tIncorrect password, please try again.\n");
                                                passwordIncorrect4 = 1;
                                            }

                                        } while (passwordIncorrect4);
                                    } else {
                                        printf("\t\t\t\tInvalid account id. Please try again.\n");
                                        wrongReceiver = 1;
                                    }

                                } while (wrongReceiver);
                                break;
                            case '4':
                                printf("\t\t\tYou have left %d kyats in your account.\n", userBalances[userIndex]);
                                repeat_bank_process = 1;
                                break;
                            case '5':
                                exit(0);
                            default:
                                printf("\t\t\tInvalid choose of option. Please try again.\n");
                                repeat_bank_process = 1;
                                break;
                            }
                        } while (repeat_bank_process);

                    } else {
                        passwordIncorrect = 1;
                        printf("\t\tIncorrect Password! Try again.\n");
                    }
                } while (passwordIncorrect);

            } else {
                printf("\t\tYou are new to our Bank. Plese register first.\n");
                invalid_input_2 = 1;
            }

            
        } else if (login_or_register_option == '2') {
            // register 
            do { 
                invalidId = 0;
                idFound = 0;

                printf("\tPlease create an id number with more than 5 digits : ");
                scanf("%d", &userId);
                // check repetition of id in the database
                for (int i = 0; i < currentUsers;i++) {
                    if (userId == userIds[i]) {
                        idFound = 1;
                        break;
                    }
                }

                if (userId - 9999 < 1) {
                    printf("\t\tYour id is less than 5 digits. Try again.\n");
                    invalidId = 1;
                } else if (idFound) {
                    printf("\t\tThis id has been taken by another user. Choose another one.\n");
                    invalidId = 1;
                } else {
                    do {
                        invalidPassword = 0;

                        printf("\tPlease create a new password (6 or more digits , leading 0 is invalid) : ");
                        scanf("%d", &newPassword);

                        if (newPassword - 99999 < 1 ) {
                            printf("\t\tYour password is less than 6 digits. Try again.\n");
                            invalidPassword = 1;
                        } else {
                            do { 
                                invalidConfirmPassword = 0;

                                printf("\tConfirm your password : ");
                                scanf("%d", &confirmPassword);

                                if (newPassword == confirmPassword) {

                                        userBalances[currentUsers] = 0;
                                        userIds[currentUsers] = userId;
                                        userPasswords[currentUsers] = newPassword;
                                        currentUsers++;

                                        printf("\t\tYour account has been created successfully with balance 0 kyats.\n");
                                        printf("\t\tPlease log in to activate your account.\n");

                                        invalidConfirmPassword = 0;
                                        registerSuccess = 1;
                                } else {
                                    printf("\t\tPasswords don't match. Please try again.\n");
                                    printf("\t\tPress 1 to create a new password again or press any other keys to confirm password again :");
                                    scanf("%c", &newOrConfirmOption);
                                    if (newOrConfirmOption != '1') {
                                        invalidConfirmPassword = 1;
                                    } 
                                }
                                invalidPassword = 0;
                            } while(invalidConfirmPassword);
                        }

                    } while (invalidPassword);
                    invalidId = 0;
                }
            } while (invalidId);
        } else {
            printf("Invalid Option, Try again.\n");
            invalid_input_1 = 1;
        }

    } while (registerSuccess || invalid_input_1 || invalid_input_2);
    return 0;
}