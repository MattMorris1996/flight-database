#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#include "flight_database.h"
#include "database_admin.h"
=======
typedef struct seat_data {
    char customer_name[10];
    float price;
    int status;
} seat;

typedef struct flight
{
    char plane_name[10];
    char start[10];
    char end[10];
    int x;
    int y;
    seat ** seats;
} plane;

void init_seats(plane* _plane)
{

    _plane->seats = (seat**) calloc(_plane->x, sizeof(seat*));
    printf("init seats ptr: %d\n", _plane->seats);
    for(int i = 0; i < _plane->x; i++)
        _plane->seats[i] = (seat*) calloc(_plane->y, sizeof(seat));

}

void set_values(plane* _plane)
{
    printf("set values ptr: %d\n", _plane->seats);
    for (int i = 0; i < _plane->x; i++)
    {
        for (int j = 0; j<_plane->y; j++)
        {
            printf("Set Value x: %d y: %d : ", i, j);
            scanf("%d", &(_plane->seats[i][j].status));
        }
    }
}

void print_values(plane* _plane)
{
    printf("print values ptr: %d\n", _plane->seats);
    for (int i = 0; i < _plane->x; i++)
    {
        for (int j = 0; j<_plane->y; j++)
        {
            printf("%d ", _plane->seats[i][j].status);
        }
        printf("\n");
    }
}

void destruct_seats(plane* _plane)
{
    printf("destruct values ptr: %d\n", _plane->seats);
    for(int i = 0; i < _plane->x; i++)
    {
        free(_plane->seats[i]);
        _plane->seats[i] = NULL;
    }
}

void save_seats(FILE *fp, plane* _plane)
{
    printf("save values ptr: %d\n", _plane->seats);
    printf("file ptr: %d\n", fp);

    if(fp == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    printf("Seat pointer: %d\n",_plane->seats);
    printf("x: %d y: %d\n", _plane->x, _plane->y);

    for (int i = 0; i < _plane->x; i++)
    {
        fwrite(_plane->seats[i], sizeof(seat), _plane->y, fp);
    }

    destruct_seats(_plane);
}

void load_seats(FILE* fp, plane* _plane)
{

    init_seats(_plane);
    printf("load values ptr: %d\n", _plane->seats);

    if(fp  == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < _plane->x; i++)
    {
        fread(_plane->seats[i], sizeof(seat), _plane->y, fp);
    }

}

void save_plane(plane* _plane, int N)
{
    FILE *fp;
    FILE *fp_seats;

    if((fp = fopen("plane.bin","wb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    if((fp_seats = fopen("seats.bin","wb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", i);
        save_seats(fp_seats, &(_plane[i]));
        fwrite(&_plane[i], sizeof(plane), 1, fp);
    }

    fclose(fp_seats);
    fclose(fp);
}

void load_plane(plane* _plane, int N)
{
    FILE *fp;
    FILE *fp_seats;

    if((fp = fopen("plane.bin","rb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    if((fp_seats = fopen("seats.bin","rb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fread(&_plane[i], sizeof(plane), 1, fp);
        load_seats(fp_seats, &_plane[i]);
    }

    fclose(fp_seats);
    fclose(fp);
}

void set_null(plane *_plane, int N)
{
    for (int i = 0; i < N; i++)
    {
        _plane[i].seats = NULL;
        _plane[i].x = 0;
        _plane[i].y = 0;
    }
}
>>>>>>> f3b13cb437e57a2d859e86ff67522ee0f937f172

int main()
{
    database_admin();
}
