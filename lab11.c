#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s
{
    char name[128];
    int stars;
    char adres[128];
    int tel;
    int nomera;
    int luks;
    int svobod;
};

void dob(struct s hotel[], int m)
{
    for (int i = m; i < m + 1; i++)
    {
        printf("name -> ");
        scanf("%s", hotel[i].name);
        printf("stars -> ");
        scanf("%d", &hotel[i].stars);
        printf("adres -> ");
        scanf("%s", hotel[i].adres);
        printf("tel -> ");
        scanf("%d", &hotel[i].tel);
        printf("nomera -> ");
        scanf("%d", &hotel[i].nomera);
        printf("luksi -> ");
        scanf("%d", &hotel[i].luks);
        printf("svobodnie -> ");
        scanf("%d", &hotel[i].svobod);
    }
    printf("\n");
}

void del(struct s hotel[])
{
    int h;
    printf("kakoi otel udalit -> ");
    scanf("%d", &h);
    struct s e4 = {" ", 0, " ", 0, 0, 0, 0};
    hotel[h - 1] = e4;
}

void best(struct s hotel[], int m)
{
    int i, k = 0;
    char max;
    for (i = 1; i < m; i++)
        if (hotel[i].stars > hotel[i - 1].stars)
            max = hotel[i].stars;
    for (i = 0; i < m; i++)
        if (hotel[i].stars == max)
            if (hotel[i].svobod > k)
                k = hotel[i].svobod;
    for (i = 0; i < m; i++)
        if (hotel[i].stars == max && hotel[i].svobod == k)
            printf("%s %d %s %d %d %d %d\n", hotel[i].name, hotel[i].stars, hotel[i].adres, hotel[i].tel, hotel[i].nomera, hotel[i].luks, hotel[i].svobod);
}

void out(struct s hotel[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (hotel[i].stars != 0)
            printf("%s %d %s %d %d %d %d\n", hotel[i].name, hotel[i].stars, hotel[i].adres, hotel[i].tel, hotel[i].nomera, hotel[i].luks, hotel[i].svobod);
    }
}

void poisk(struct s hotel[], int n)
{
    printf("%s %d %s %d %d %d %d\n", hotel[n - 1].name, hotel[n - 1].stars, hotel[n - 1].adres, hotel[n - 1].tel, hotel[n - 1].nomera, hotel[n - 1].luks, hotel[n - 1].svobod);
}

int main()
{
    struct s hotel[50];
    struct s e0 = {"efj", 1, "hefeh", 612337, 115, 13, 35};
    hotel[0] = e0;
    struct s e1 = {"dujw", 3, "gjeju", 643728, 127, 20, 12};
    hotel[1] = e1;
    struct s e2 = {"jfh", 5, "suiieu", 874981, 100, 10, 3};
    hotel[2] = e2;
    struct s e3 = {"fhwf", 5, "uhiwf", 928428, 113, 5, 15};
    hotel[3] = e3;
    int m = 4, l, nom;
    for (;;)
    {
        printf("1. Dopolnitelnoe;\n2. Udalenie;\n3. Luchshiy otel;\n4. Poisk po nomeru;\n5. Spisok;\n6. End;\n");
        printf("Chto:\n");
        scanf("%d", &l);
        switch (l)
        {
            case 1:
                dob(hotel, m);
                m++;
                break;
            case 2:
                del(hotel);
                break;
            case 3:
                best(hotel, m);
                break;
            case 4:
                printf("nomer -> ");
                scanf("%d", &nom);
                poisk(hotel, nom);
                break;
            case 5:
                out(hotel, m);
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}
