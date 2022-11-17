#include "stdio.h"

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

    printf("Warmly welcome from Community Bank!\n");
    do {
        invalid_input_1 = 0;
        invalid_input_2 = 0;
        idFound = 0;
        passwordIncorrect = 0;
        repeat_bank_process = 0;

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
                            printf("\t\tPress 4 to check your balance: ");
                            scanf(" %c", &bank_process_option);

                            switch (bank_process_option)
                            {
                            case '1':
                                break;
                            case '2':
                                break;
                            case '3':
                                break;
                            case '4':
                                break;
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
                printf("\t\tYou are new. Plese register first.\n");
                invalid_input_2 = 1;
            }

            
        } else if (login_or_register_option == '2') {
            // register 
            printf("Successful register.\n");
        } else {
            printf("Invalid Option, Try again.\n");
            invalid_input_1 = 1;
        }

    } while (registerSuccess || invalid_input_1 || invalid_input_2);
    return 0;
}