#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count, i;
struct films
{
    char name[30];
    char country[30];
    char producer[30];
    char Actors[80];
    int year;
};

struct films newStruct(struct films a)
{
    printf("Enter name : ");
    scanf("%s", a.name);
    strcat(a.name, "\n");
    printf("Enter country : ");
    scanf("%s", a.country);
    strcat(a.country, "\n");
    printf("Enter producer : ");
    scanf("%s", a.producer);
    strcat(a.producer, "\n");
    printf("Enter Actors (1,2,3): ");
    scanf("%s", a.Actors);
    strcat(a.Actors, "\n");
    printf("Enter year: ");
    scanf("%d", &a.year);

    printf("Film %s added\n", a.name);
    printf("\n");
    return a;
}

struct films delStruct(struct films a[10], int n)
{
    n = n - 1;
    while (n < count)
    {
        strcpy(a[n].name, a[n + 1].name);
        strcpy(a[n].country, a[n + 1].country);
        strcpy(a[n].producer, a[n + 1].producer);
        strcpy(a[n].Actors, a[n + 1].Actors);
        a[n].year = a[n + 1].year;
        memset(&a[count], 0, sizeof(a[count]));
        n++;
    }
    return a[10];
}


void openFile(struct films a[])
{
    FILE *file;
    if ((file = fopen("file", "r")) == NULL)
    {
        printf("Eror");
    }
    for (int i = 0; i < 5; i++)
    {
        fgets(a[i].name, 30, file);
        printf("%s\n", a[i].name);
        if (strlen(a[i].name))
        {
            fgets(a[i].country, 30, file);
            fgets(a[i].producer, 30, file);
            fgets(a[i].Actors, 30, file);
            fscanf(file, "%d", &a[i].year);
            fseek(file, 1, SEEK_CUR);
            count++;
            printf("%d\n",count);
        }
        else
        {
            break;
        }
    }
}

void saveFile(struct films a[])
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
            fputs(a[i].country, file);
            //fprintf(file, "\n");
            fputs(a[i].producer, file);
            //fprintf(file, "\n");
            fputs(a[i].Actors, file);
            //fprintf(file, "\n");
            fprintf(file, "%d", a[i].year);
            fprintf(file, "\n");

        }
    }
    fclose(file);
}



void searchActors(struct films a[])
{
    char str[40];
    printf("Enter name Actors ");
    scanf("%s", str);
    char *s;
    for (i = 0; i < count; i++)
    {
        s = strstr(a[i].Actors, str);
        if (s != NULL)
        {
            printf("\n%s %s %s %s %d\n",
                   a[i].name,
                   a[i].country,
                   a[i].producer,
                   a[i].Actors,
                   a[i].year);
        }
        else
            printf("Not Found \n");
    }
}

void print(struct films a[])
{
    for (i = 0; i < count; i++)
    {
        if (strlen(a[i].country))
        {
            printf("\n%d : %s %s %s %s %d \n",
                   i + 1,
                   a[i].name,
                   a[i].country,
                   a[i].producer,
                   a[i].Actors,
                   a[i].year);
        }
    }
    printf("\n");
}

int main()
{
    char c;
    int n = 0;
    struct films films1[10];
    struct films *p = films1;
    openFile(films1);
    while (c != 'e')
    {
        printf("Choise? n - new film, ");
        printf("d - delate film, s - search film with Actors ");
        printf("o - save in file ");
        printf("p - print films e - exit ");
        printf("\n");
        scanf("%s", &c);
        switch (c)
        {
            case 'n':
                count++;
                for (i = 0; i < count; i++)
                {
                    if (strlen(films1[i].name) == 0)
                    {
                        films1[i] = newStruct(films1[i]);
                        break;
                    }
                }
                break;
            case 'p':
                print(films1);
                break;
            case 'o':
                saveFile(films1);
                break;
            case 'd':
                print(films1);
                printf("Choise number\n");
                scanf("%d\n", &n);
                delStruct(p, n);
                count--;
                break;
            case 's':
                searchActors(films1);
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

// Тут тоже самое что и в 11 + сохранение и открытие файла в самом начале программе(ты не контролируешь открытие)
// тебе надо создать текстовый файл под название "file" в той же папке где и лабораторная, когда добавишь новые фильмы, надо будет сохранить с помощью ключа 'o'
// Будут вопросы пиши, всё протестируй вначале
// команда для компилирования gcc lab12.c -Wall -o lab12
