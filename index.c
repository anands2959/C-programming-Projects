#include <stdio.h>
#include <stdlib.h>
typedef struct hostel
{
    int rno;
    char name[30];
    char location[50];
    char gender[8];
    int roomno;
} hostel;
int lower = 1, upper = 40;
void create()
{

    // printf("%d", rnd);
    hostel h;
    FILE *fp = fopen("hostel.dat", "a+");
    printf("Enter Roll No. :\t");
    scanf("%d", &h.rno);
    printf("Enter Name :\t\t");
    scanf("%s", &h.name);
    printf("Enter Location :\t");
    scanf("%s", &h.location);
    printf("Enter Gender :\t\t");
    scanf("%s", &h.gender);
    h.roomno = getRoomNo(((rand() % (upper - lower + 1)) + lower));
    if (h.roomno != 0)
    {
        fwrite(&h, sizeof(hostel), 1, fp);
    }

    fclose(fp);
}
int getRoomNo(int roomno)
{
    int allocated = 0;
    FILE *fp = fopen("hostel.dat", "r");
    hostel h1;
    while (fread(&h1, sizeof(hostel), 1, fp))
    {
        if (h1.roomno == roomno)
        {
            allocated = 1;
        }
    }
    if (allocated == 0)
    {
        return roomno;
    }
    else
    {
        return getRoomNo(((rand() % (upper - lower + 1)) + lower));
    }
    fclose(fp);
}
void display()
{
    hostel h1;
    FILE *fp = fopen("hostel.dat", "r");
    printf("\n\n\n\n---------------------------------------------------------------");
    printf("\n\t\tHostel Students List");
    printf("\n---------------------------------------------------------------");
    printf("\n%-10s%-20s%-15s%-10s%-5s\n", "Roll No.", "Name","Location","Gender", "Room No.");
    printf("---------------------------------------------------------------\n");
    while (fread(&h1, sizeof(hostel), 1, fp))
    {
        printf("%-10d%-20s%-15s%-10s%-5d\n", h1.rno, h1.name, h1.location, h1.gender, h1.roomno);
    }
    fclose(fp);
    printf("---------------------------------------------------------------\n\n\n\n");
}

int main()
{
    int ch;
    do
    {
        // system("clear");
        printf("\n--------------------------------------------------------------\n");
        printf("\t\tWlcome to Anand's Hostel");
        printf("\n--------------------------------------------------------------\n");
        printf("\n\t1.ALLOCATE NEW ROOM");
        printf("\n\t2.DISPLAY");
        printf("\n\t3.EXIT");
        printf("\n\nEnter your choise:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\n\n\tThank You :)\n\n");
            exit(0);
            break;
        default:
            printf("\n\n\tSomthing went wrong  :(\n\n");
            break;
        }
    } while (ch != 0);
}