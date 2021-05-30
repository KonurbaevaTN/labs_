#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct hot
{
    int status;
    char name[20];
    int stars;
    char addr[60];
    int number;
    int countRooms;
    int countLuxRooms;
    int freeRooms;
} hotel;

void init_hotel(int n, hotel *name)
{
  for (int i = 0; i < n; i++)
      name[i].status = 0;
}

void fill(int n, hotel *name)
{
    char v1[20];
    char v2[60];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k != n)
        {
            if (!name[i].status)
            {
                memset(v1, 0, sizeof(v1));
                memset(v2, 0, sizeof(v2));
                name[i].status = 1;
                printf("Enter name : ");
                scanf("%s", v1);
                for (int t = 0; t < 20; t++)
                    v1[t] = tolower(v1[t]);
                strcpy(name[i].name, v1);
                printf("Enter stars : ");
                scanf("%d", &name[i].stars);
                printf("Enter addres : ");
                scanf("%s", v2);
                for (int t = 0; t < 60; t++)
                    v2[t] = tolower(v2[t]);
                strcpy(name[i].addr, v2);
                printf("Enter number : ");
                scanf("%s", &name[i].number);
                printf("Enter count of rooms: ");
                scanf("%d", &name[i].countRooms);
                printf("Enter count of lux rooms : ");
                scanf("%d", &name[i].countLuxRooms);
                printf("Enter count of free rooms: ");
                scanf("%d", &name[i].freeRooms);
                break;
            }
            else
                k++;
        }
  }
}

void remove_hotel(int n, hotel *name)
{
    name[n].status = 0;
}

void printstr(int n, hotel *name)
{
    for (int i = 0; i < n; i++)
    {
        if (name[i].status)
        {
            printf("\n");
            printf("Name%d = %s\n", i, name[i].name);
            printf("Stars%d = %d\n", i, name[i].stars);
            printf("Addres%d = %s\n", i, name[i].addr);
            printf("Number%d = %d\n", i, name[i].number);
            printf("Count of rooms%d = %d\n", i, name[i].countRooms);
            printf("Count of lux rooms%d = %d\n", i, name[i].countLuxRooms);
            printf("Count of free rooms%d = %d\n", i, name[i].freeRooms);
        }
    }
}

void bestHotel(int n, hotel *name)
{
    int k = 0, i;
    char max = name[0].stars;
    for (i = 1; i < n; i++)
        if (name[i].stars > name[i - 1].stars)
            max = name[i].stars;
    for (i = 0; i < n; i++)
        if (name[i].stars == max)
            if (name[i].freeRooms > k)
                k = name[i].freeRooms;
    for (i = 0; i < n; i++)
        if (name[i].stars == max && name[i].freeRooms == k)
            printf("%s %d %s %d %d %d %d\n", name[i].name, name[i].stars, name[i].addr, name[i].number, name[i].countRooms, name[i].countLuxRooms, name[i].freeRooms);
}

void read_hotel(int n, hotel *name)
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
        printf("File doesn't exist\n");
    else
    {
        for(int i = 0; i < n; i++)
            fscanf(file, "%d %s %d %s %d %d %d %d\n", name[i].status, name[i].name, name[i].stars, name[i].addr, name[i].number, name[i].countRooms, name[i].countLuxRooms, name[i].freeRooms);
        fclose(file);
    }
}

void write_hotel(int n, hotel *name)
{
    FILE* file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (name[i].status)
        fprintf(file, "%d %s %d %s %d %d %d %d\n", name[i].status, name[i].name, name[i].stars, name[i].addr, name[i].number, name[i].countRooms, name[i].countLuxRooms, name[i].freeRooms);
    }
    fclose(file);
}

int main()
{
  int n = 10, l = 0;
  char c;
  hotel test[n];
  init_hotel(n, test);
  read_hotel(n, test);
      while (c != 'e')
      {
          printf("\n");
          printf("Choise? n - add hotel, ");
          printf("d - delete hotel, s - search best hotel with free rooms, ");
          printf("p - print hotels, e - exit ");
          printf("\n");
          scanf("%s", &c);
          switch(c)
          {
              case 'n':
                  fill(n, test);
                  break;
              case 'p':
                  printstr(n, test);
                  break;
              case 'd':
                  printstr(n, test);
                  printf("Choise number\n");
                  scanf("%d\n", &l);
                  remove_hotel(l, test);
                  break;
              case 's':
                  bestHotel(n, test);
                  break;
              case 'e':
                  break;
              default:
                  printf("Error\n");
                  break;
          }
      }
  write_hotel(n, test);
  return 0;
}
