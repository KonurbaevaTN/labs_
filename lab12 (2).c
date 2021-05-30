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