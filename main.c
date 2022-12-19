#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

typedef struct
{
    char name[50];
    int train_num;
    char age[10];
    char gender[2];
    char destiny[20];
    char boarding[20];
    int fare;
} pd;

void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char reserved_seats[], int, int, float);
void specifictrain(int);
float charge(int, int);
void login();
void view_ticket(void);
void boad_dest(int, char boad[], char dest[]);

int main()

{
    system("cls");
    printf("\t\t=================================================\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|          TRAIN TICKET RESR. SYSTEM            |\n");
    printf("\t\t|                -by Sarthak Singh              |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t=================================================\n\n\n");

    printf(" \n Press any key to continue.....");

    getch();
    system("cls");
    login();
    int menu_choice, choice_return;
start:
    system("cls");
    printf("\n=================================\n");
    printf("    TRAIN RESERVATION SYSTEM");
    printf("\n=================================");
    printf("\n1>> Reserve A Ticket");
    printf("\n------------------------");
    printf("\n2>> View All Available Trains");
    printf("\n------------------------");
    printf("\n3>> Cancel Reservation");
    printf("\n------------------------");
    printf("\n4>> View Ticket");
    printf("\n------------------------");
    printf("\n5>> Exit");
    printf("\n------------------------");
    printf("\n\n-->");
    scanf("%d", &menu_choice);
    switch (menu_choice)
    {
    case 1:
        reservation();
        break;
    case 2:
        viewdetails();
        printf("\n\nPress any key to go to Main Menu..");
        getch();
        break;
    case 3:
        cancel();
        break;
    case 5:
        return (0);
    case 4:
        view_ticket();
        printf("\n\nPress any key to go to Main Menu..");
        getch();
        break;
    default:
        printf("\nInvalid choice");
    }
    goto start;
    return (0);
}

void view_ticket(void)
{

    FILE *file;
    char filename[FILENAME_SIZE] = "reserved_seats.txt";

    char buffer[MAX_LINE];
    int tickno = 0;
    printf("Enter your ticket number:> ");
    scanf("%d", &tickno);

    file = fopen(filename, "r");
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        fgets(buffer, MAX_LINE, file);
        if (feof(file))
        {
            keep_reading = false;
            printf("No ticket found for the entered details..!!");
        }
        else if (current_line == tickno)
        {
            keep_reading = false;
                printf("Name\t\tTrain no.\tGender\t\tAge\t\tClass\t\tFrom\t\tTo\n");
                printf("%s", buffer);
        }

        current_line++;
    } while (keep_reading);
    fclose(file);
}
 
void boad_dest(int train_num, char boad[], char dest[])
{
    if (train_num == 1001)
    {
        strcpy(boad, "Ambala");
        strcpy(dest, "Una");
    }
    if (train_num == 1002)
    {
        strcpy(boad, "Chandigarh");
        strcpy(dest, "Shimla");
    }
    if (train_num == 1003)
    {
        strcpy(boad, "Shimla");
        strcpy(dest, "Gorukhpur");
    }
    if (train_num == 1004)
    {
        strcpy(boad, "Ujjain");
        strcpy(dest, "Bhopal");
    }
    if (train_num == 1005)
    {
        strcpy(boad, "Rampur");
        strcpy(dest, "Kolkata");
    }
    if (train_num == 1006)
    {
        strcpy(boad, "Kanpur");
        strcpy(dest, "Jhansi");
    }
    if (train_num == 1007)
    {
        strcpy(boad, "Barelliey");
        strcpy(dest, "Lalkuan");
    }
    if (train_num == 1008)
    {
        strcpy(boad, "Pune");
        strcpy(dest, "Karnataka");
    }
    if (train_num == 1009)
    {
        strcpy(boad, "Kanpur");
        strcpy(dest, "Agra");
    }
    if (train_num == 1010)
    {
        strcpy(boad, "Dehradun");
        strcpy(dest, "Mussoorie");
    }
}

void viewdetails(void)
{
    system("cls");
    printf("-----------------------------------------------------------------------------");
    printf("\nTr.No\tName                            Destinations             Time\n");
    printf("-----------------------------------------------------------------------------");
    printf("\n1001\tUna Express                     Ambala to Una            09:00");
    printf("\n1002\tChandigarh Express              Chandigarh To Shimla     24:00");
    printf("\n1003\tShimla-Gorukhpur Express        Shimla to Gorukhpur      08:00");
    printf("\n1004\tUjjain Express                  Ujjain to Bhopal         11:00");
    printf("\n1005\tKolkata Express                 Rampur To Kolkata        07:00");
    printf("\n1006\tJhansi Express                  Kanpur To Jhansi         09:30");
    printf("\n1007\tLalkuan Express                 Barelliey To Lalkuan     13:00");
    printf("\n1008\tKarnataka Express               Pune To Karnataka        16:00");
    printf("\n1009\tAgra-Interstate Express         Kanpur To Agra           15:30");
    printf("\n1010\tUttarakhand-Interstate Express  Dehradun To Mussoorie    14:15");
}

void reservation(void)
{
    char confirm;
    int i = 0, t;
    float charges;
    pd passdetails;
    FILE *fp;
    FILE *fp5;
    int ticket_number;
    char s;
    char tcl[2];
    char dest[40], boad[40];

    fp = fopen("name.txt", "a");
    fp5 = fopen("reserved_seats.txt", "a");

    system("cls");

    printf("\nEnter Your Name:> ");
    fflush(stdin);
    gets(passdetails.name);

    printf("\nEnter age:> ");
    fflush(stdin);
    gets(passdetails.age);
    printf("\nEnter gender:> ");
    fflush(stdin);
    gets(passdetails.gender);

    printf("\n\n>>Press Enter To View Available Trains<< ");
    getch();
    system("cls");
    viewdetails();
    printf("\n\nEnter train number:> ");

start1:
    fflush(stdin);
    scanf("%d", &passdetails.train_num);

    boad_dest(passdetails.train_num, passdetails.boarding, passdetails.destiny);

    printf("Choose the class....");
    printf("Choose (1) for sleeper and (2) for ac:> ");
    fflush(stdin);
    scanf("%d", &passdetails.fare);
    if (passdetails.fare == 1)
    {
        tcl[0] = 'S';
    }
    else
    {
        tcl[0] = 'A';
    }
    if (passdetails.train_num >= 1001 && passdetails.train_num <= 1010)
    {
        charges = charge(passdetails.train_num, passdetails.fare);
        printticket(passdetails.name, passdetails.age, passdetails.train_num, charges);
    }
    else
    {
        printf("\nInvalid train Number! Enter again--> ");
        goto start1;
    }

    printf("\n\nConfirm Ticket (y/n):>");

start:
    scanf(" %c", &confirm);
    if (confirm == 'y')
    {

        fprintf(fp5, "%s\t\t%d\t\t%s\t\t%s\t\t%c\t\t%s\t\t%s\n", &passdetails.name, passdetails.train_num, passdetails.gender, passdetails.age, tcl[0], passdetails.boarding, passdetails.destiny);
        fprintf(fp, "%s\n", &passdetails.name);

        fclose(fp);
        FILE *fpp;
        fpp = fopen("name.txt", "r");
        int count = 0;
        while ((s = fgetc(fpp)) != EOF)
        {

            if (s == '\n')
            {
                count++;
            }
        }
        system("cls");

        printf("==================");
        printf("\n Reservation Done\n");
        printf("==================");
        printf("\nYour ticket :\n");
        printf("\t\t=================================================\n");
        printf("\t\t| Ticket no.: %d\n", count);
        printf("\t\t| Name: %s\n", passdetails.name);
        printf("\t\t| Train Number: %d\n", passdetails.train_num);
        printf("\t\t| Class: %c\n", tcl[0]);
        printf("\t\t| Boarding Station: %s\n", passdetails.boarding);
        printf("\t\t| Arrival Station: %s\n", passdetails.destiny);
        printf("\t\t| Cost: %.2f\n", charges);
        printf("\t\t=================================================\n\n\n");

        printf("Press any key to go back.......");
        fclose(fpp);
        fclose(fp5);
    }
    else
    {
        if (confirm == 'n')
        {
            printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
        }
        else
        {
            printf("\nInvalid choice entered! Enter again-----> ");
            goto start;
        }

        fclose(fp);

        fclose(fp5);
    }
    getch();
}

float charge(int train_num, int fare)
{
    if (train_num == 1001)
    {
        return (5000.0 * fare);
    }
    if (train_num == 1002)
    {
        return (5000.0 * fare);
    }
    if (train_num == 1003)
    {
        return (4500.0 * fare);
    }
    if (train_num == 1004)
    {
        return (4500.0 * fare);
    }
    if (train_num == 1005)
    {
        return (4000.0 * fare);
    }
    if (train_num == 1006)
    {
        return (4000.0 * fare);
    }
    if (train_num == 1007)
    {
        return (3500.0 * fare);
    }
    if (train_num == 1008)
    {
        return (3500.0 * fare);
    }
    if (train_num == 1009)
    {
        return (6000.0 * fare);
    }
    if (train_num == 1010)
    {
        return (6000.0 * fare);
    }
}

void printticket(char reserved_seats[], int age, int train_num, float charges)
{
    system("cls");
    printf("-------------------\n");
    printf("\tTICKET\n");
    printf("-------------------\n\n");
    printf("Name:\t\t\t%s", reserved_seats);
    printf("\nTrain Number:\t\t%d", train_num);
    specifictrain(train_num);
    printf("\nCharges:\t\t%.2f", charges);
}

void specifictrain(int train_num)
{

    if (train_num == 1001)
    {
        printf("\nTrain:\t\t\tUna Express");
        printf("\nDestination:\t\tAmbala to Una");
        printf("\nDeparture:\t\t09:00 ");
    }
    if (train_num == 1002)
    {
        printf("\nTrain:\t\t\tChandigarh Express");
        printf("\nDestination:\t\tChandigarh to Shimla");
        printf("\nDeparture:\t\t24:00");
    }
    if (train_num == 1003)
    {
        printf("\nTrain:\t\t\tShimla-Gorukhpur Express");
        printf("\nDestination:\t\tShimla to Gorukhpur");
        printf("\nDeparture:\t\t08:00");
    }
    if (train_num == 1004)
    {
        printf("\nTrain:\t\t\tUjjain Express");
        printf("\nDestination:\t\tUjjain to Bhopal");
        printf("\nDeparture:\t\t11:00 ");
    }
    if (train_num == 1005)
    {
        printf("\nTrain:\t\t\tKolkata Express");
        printf("\nDestination:\t\tRampur to Kolkata");
        printf("\nDeparture:\t\t07:00");
    }
    if (train_num == 1006)
    {
        printf("\ntrain:\t\t\tJhansi Express");
        printf("\nDestination:\t\tKanpur to Jhansi");
        printf("\nDeparture:\t\t09:30 ");
    }
    if (train_num == 1007)
    {
        printf("\ntrain:\t\t\tLalkuan Express");
        printf("\nDestination:\t\tBarelliey to Lalkuan");
        printf("\nDeparture:\t\t13:00 ");
    }
    if (train_num == 1008)
    {
        printf("\ntrain:\t\t\tKarnataka Express");
        printf("\n Destination:\t\tPune to karnataka");
        printf("\nDeparture:\t\t16:00 ");
    }
    if (train_num == 1009)
    {
        printf("\ntrain:\t\t\tAgra-Interstate Express");
        printf("\nDestination:\t\tKanpur to Agra");
        printf("\nDeparture:\t\t15:30 ");
    }
    if (train_num == 1010)
    {
        printf("\ntrain:\t\t\tUttarakhand-interstate Express");
        printf("\nDestination:\t\tDehradun to Mussoorie");
        printf("\nDeparture:\t\t14:15");
    }
}

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {

        printf("\n  =======================  LOGIN FORM  =======================\n  ");
        printf(" \n                       Enter your username:> ");
        scanf("%s", &uname);
        printf(" \n                       Enter your password:> ");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
        {
            printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch();
            system("cls");
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
    system("cls");
}

void cancel(void)
{

    FILE *file, *temp;
    char filename[FILENAME_SIZE] = "reserved_seats.txt";
    char temp_filename[FILENAME_SIZE];
    char buffer[MAX_LINE];
    char remoe[] = "   \n";
    int delete_line = 0;

    strcpy(temp_filename, "temp____");
    strcat(temp_filename, filename);
    system("cls");
    printf("-----Cancel Ticket-----\n\n");
    printf("Enter the ticket number: ");
    scanf("%d", &delete_line);
    file = fopen(filename, "r");
    temp = fopen(temp_filename, "w");
    if (file == NULL || temp == NULL)
    {
        printf("NO tickets booked");
        return 1;
    }
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        fgets(buffer, MAX_LINE, file);
        if (feof(file))
            keep_reading = false;
        else if (current_line == delete_line)
            fputs(remoe, temp);

        else
        {
            fputs(buffer, temp);
        }
        current_line++;

    } while (keep_reading);

    printf("Your ticket has been cancelled !!\n\n");
    printf("CLick any key to go to main menu....");
    getch();
    system("cls");

    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename, filename);

    FILE *file1, *temp1;
    char filename1[FILENAME_SIZE] = "name.txt";
    char temp_filename1[FILENAME_SIZE];
    char buffer1[MAX_LINE];
    char remoe1[] = "   \n";

    strcpy(temp_filename1, "temp1____");
    strcat(temp_filename1, filename1);
    file1 = fopen(filename1, "r");
    temp1 = fopen(temp_filename1, "w");

    bool keep_reading1 = true;
    int current_line1 = 1;
    do
    {
        fgets(buffer1, MAX_LINE, file1);
        if (feof(file1))
            keep_reading1 = false;
        else if (current_line1 == delete_line)
            fputs(remoe1, temp1);

        else
        {
            fputs(buffer1, temp1);
        }
        current_line1++;

    } while (keep_reading1);

    fclose(file1);
    fclose(temp1);

    remove(filename1);
    rename(temp_filename1, filename1);
}
