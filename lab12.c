#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count, i;
struct hotel
{
    char name[30];
    int stars;
    char addres[30];
    char number[30];
    int countRooms;
    int countLuxRooms;
    int freeRooms;
};

struct hotel newStruct(struct hotel a)
{
    printf("Enter name : ");
    scanf("%s", a.name);
    printf("Enter stars : ");
    scanf("%d", &a.stars);
    printf("Enter addres : ");
    scanf("%s", a.addres);
    printf("Enter number : ");
    scanf("%s", a.number);
    printf("Enter count of rooms: ");
    scanf("%d", &a.countRooms);
    printf("Enter count of lux rooms : ");
    scanf("%d", &a.countLuxRooms);
    printf("Enter count of free rooms: ");
    scanf("%d", &a.freeRooms);

    printf("Hotel %s added\n", a.name);
    printf("\n");
    return a;
}

struct hotel delStruct(struct hotel a[10], int n)
{
    n = n - 1;
    while (n < count)
    {
        strcpy(a[n].name, a[n + 1].name);
        strcpy(a[n].addres, a[n + 1].addres);
        strcpy(a[n].number, a[n + 1].number);
        a[n].stars = a[n + 1].stars;
        a[n].countRooms = a[n + 1].countRooms;
        a[n].countLuxRooms = a[n + 1].countLuxRooms;
        a[n].freeRooms = a[n + 1].freeRooms;
        memset(&a[count], 0, sizeof(a[count]));
        n++;
    }
    return a[10];
}

void openFile(struct hotel a[])
{
    FILE *file;
    if ((file = fopen("file", "r")) == NULL)
    {
        printf("Error");
    }
    for (int i = 0; i < 5; i++)
    {
        fgets(a[i].name, 30, file);
        if (strlen(a[i].name))
        {
            fgets(a[i].addres, 30, file);
            fgets(a[i].number, 30, file);
            fscanf(file, "%d", &a[i].stars);
            fscanf(file, "%d", &a[i].countRooms);
            fscanf(file, "%d", &a[i].countLuxRooms);
            fscanf(file, "%d", &a[i].freeRooms);
            fseek(file, 1, SEEK_CUR);
            count++;
        }
        else
        {
            break;
        }
    }
}

void saveFile(struct hotel a[])
{
    FILE *file;
    if ((file = fopen("file", "w")) == NULL)
    {
        printf("Error \n");
    }
    for (int i = 0; i < count; i++)
    {
        if (strlen(a[i].name))
        {
            fputs(a[i].name, file);
            //fprintf(file, "\n");
            fputs(a[i].addres, file);
            //fprintf(file, "\n");
            fputs(a[i].number, file);
            //fprintf(file, "\n");
            fprintf(file, "%d", a[i].stars);
            fprintf(file, "%d", a[i].countRooms);
            fprintf(file, "%d", a[i].countLuxRooms);
            fprintf(file, "%d", a[i].freeRooms);
            fprintf(file, "\n");

        }
    }
    fclose(file);
}

void print(struct hotel a[])
{
    for (i = 0; i < count; i++)
    {
        printf("\n%d : Name of hotle=%s Stars=%d Addres=%s Number=%s Count of rooms=%d Count of Lux rooms=%d Count free rooms=%d\n",
               i + 1,
               a[i].name,
               a[i].stars,
               a[i].addres,
               a[i].number,
               a[i].countRooms,
               a[i].countLuxRooms,
               a[i].freeRooms);
    }
    printf("\n");
}


void searchHotel(struct hotel a[])
{
    struct hotel bestHotels[3];
    int bestStars = 5, countBest = 0, maxFreeRooms, indexOfMax;
    for (i = 0; i <= count; i++)
    {
        if(a[i].stars == bestStars)
        {
          bestHotels[countBest] = a[i];
          countBest++;
        }
        if(i == count && countBest == 0)
        {
          i = 0;
          bestStars--;
        }
    }
    maxFreeRooms = bestHotels[0].freeRooms;
    indexOfMax = 0;
    for (i = 0; i < countBest; i++)
    {
        printf("Do = %d\n", maxFreeRooms);
        if(maxFreeRooms < bestHotels[i].freeRooms)
        {
            maxFreeRooms = bestHotels[i].freeRooms;
            indexOfMax = i;
        }
        printf("Posle = %d\n", maxFreeRooms);
    }
    printf("\n%d : Name of hotle=%s Stars=%d Addres=%s Number=%s Count of rooms=%d Count of Lux rooms=%d Count free rooms=%d\n",
           indexOfMax + 1,
           bestHotels[indexOfMax].name,
           bestHotels[indexOfMax].stars,
           bestHotels[indexOfMax].addres,
           bestHotels[indexOfMax].number,
           bestHotels[indexOfMax].countRooms,
           bestHotels[indexOfMax].countLuxRooms,
           bestHotels[indexOfMax].freeRooms);
}

int main()
{
    char c;
    int n = 0;
    struct hotel hotels[10];
    struct hotel *p = hotels;
    while (c != 'e')
    {
        printf("Choise? n - add hotel, ");
        printf("d - delate hotel, s - search best hotel with free rooms ");
        printf("p - print hotels e - exit ");
        printf("\n");
        scanf("%s", &c);
        switch (c)
        {
            case 'n':
                hotels[count] = newStruct(hotels[count]);
                count++;
                break;
            case 'p':
                print(hotels);
                break;
            case 'd':
                print(hotels);
                printf("Choise number\n");
                scanf("%d\n", &n);
                delStruct(p, n);
                count--;
                break;
            case 's':
                searchHotel(hotels);
                break;
            case 'e':
                break;
            default:
                printf("Error\n");
                break;
        }
    }
    return 0;
}
