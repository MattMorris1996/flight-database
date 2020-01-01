#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flight_database.h"

void database_admin()
{
    plane my_plane[11];
    char airports[10][10];


    set_null(my_plane, 11);

    set_airports_null(10,airports,10);
    strcpy(airports[0], "hello");
    printf("%s", airports[0]);
    int p_id;
    int mode;
    while(mode != 5)
    {
        printf("0-New Plane\n");
        printf("1-Save Values\n");
        printf("2-Load Values\n");
        printf("3-print Values\n");
        printf("4-print all Values\n");
        printf("Enter a mode: ");
        scanf("%d", &mode);
        switch(mode)
        {
        case 0: // new plane
            new_airport(&airports,10);
            //new_flight(my_plane, 11);
            break;

        case 1: // save values
            save_plane(my_plane, 11);
            save_airports(10,airports, 10);
            break;

        case 2: // load values
            load_plane(my_plane, 11);
            load_airports(10, airports, 10);
            //print_all(my_plane, 10);
            break;
        case 3: // get flight data

            break;
        case 4:
            print_all(my_plane, 11);
            print_airports(&airports, 10);
            break;
        }
    }
    save_plane(my_plane, 11);
    destruct_plane(my_plane, 11);
}

void new_flight(plane * my_plane, int N)
{
    int plane_id;

    printf("Enter plane ID: ");
    scanf("%d", &plane_id);

    printf("Enter plane name:");
    scanf("%s", my_plane[plane_id].plane_name);

    printf("Enter plane size x: ");
    scanf("%d", &my_plane[plane_id].x);

    printf("Enter plane size y: ");
    scanf("%d", &my_plane[plane_id].y);

    printf("Enter flight starting port: ");
    scanf("%s", my_plane[plane_id].start);

    printf("Enter flight ending port: ");
    scanf("%s", my_plane[plane_id].end);

    init_seats(&my_plane[plane_id]);

    set_values(&my_plane[plane_id]);
}

void set_airports_null(int str_len, char *a[str_len], int N)
{
        for(int i = 0; i < N; i++)
        {
            a[i] = "";
        }
}
void new_airport(char *arr[], int N)
{
    int i = 0;

    while(arr[i] != "" && i < N)
    {
        i++;
    }
    if (i == N)
    {
        printf("database full\n");
    }
    printf("Enter Airport name: ");
    strcpy(arr[i], "hello");
    printf("%s", arr[i]);
}

void save_airports(int str_len, char *a[str_len], int N)
{
    FILE *fp;

    if((fp = fopen("airports.bin","wb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fwrite(a[i], sizeof(a[i]), 1, fp);
    }

    fclose(fp);

}

void load_airports(int str_len, char *a[str_len], int N)
{
    FILE *fp;

    if((fp = fopen("airports.bin", "rb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fread(a[i], sizeof(a[i]), 1, fp);
    }

    fclose(fp);
}

void print_airports(char *a[], int N)
{
    strlen(a[0]);
    for (int i = 0; i < N; i++)
    {
        printf("%d. %s\n", i, a[i]);
    }
}

void set_price_plane(plane * my_plane, int N) //sets whole plane price
{
    int plane_id;
    printf("Enter plane ID: ");
    scanf("%d", &plane_id);

    float price;
    printf("Enter price");
    scanf("%f", &price);

    for (int i = 0; i < my_plane[plane_id].x; i++)
        for (int j = 0; j < my_plane[plane_id].y; j++)
        {
            my_plane[plane_id].seats[i][j].price = price;
        }
}

void set_price_seat(plane * my_plane, int N) //sets price on individual seats
{
    int x;
    int y;
    int plane_id;

    printf("Enter plane ID: ");
    scanf("%d", &plane_id);

    printf("Enter isles:");
    scanf("%d", &x);
    printf("Enter seat number");
    scanf("%d", &y);

    float price;
    printf("Enter price");
    scanf("%f", &price);

    my_plane[plane_id].seats[x][y].price = price;
}

void get_flight_data(plane * my_plane, int N)
{
    int p_id;
    printf("Enter plane id: ");
    scanf("%d", &p_id);
    printf("%s\n",my_plane[p_id].plane_name);
    printf("%s\n",my_plane[p_id].start);
    printf("%s\n",my_plane[p_id].end);
    print_values(&my_plane[p_id]);
}
