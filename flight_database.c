#include <stdio.h>
#include <stdlib.h>

#include "flight_database.h"

void init_seats(plane* _plane)
{

    _plane->seats = (seat**) calloc(_plane->x, sizeof(seat*));
    //printf("init seats ptr: %d\n", _plane->seats);
    for(int i = 0; i < _plane->x; i++)
        _plane->seats[i] = (seat*) calloc(_plane->y, sizeof(seat));

}

void set_values(plane* _plane)
{
    //printf("set values ptr: %d\n", _plane->seats);
    for (int i = 0; i < _plane->x; i++)
    {
        for (int j = 0; j<_plane->y; j++)
        {
            printf("Set Value x: %d y: %d : ", i, j);
            scanf("%d", &(_plane->seats[i][j].status));
        }
    }
};

void print_values(plane* _plane)
{
    //printf("print values ptr: %d\n", _plane->seats);
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
    //printf("destruct values ptr: %d\n", _plane->seats);
    for(int i = 0; i < _plane->x; i++)
    {
        free(_plane->seats[i]);
        _plane->seats[i] = NULL;
    }
}

void save_seats(FILE *fp, plane* _plane)
{
    //printf("save values ptr: %d\n", _plane->seats);
    //printf("file ptr: %d\n", fp);

    if(fp == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    //printf("Seat pointer: %d\n",_plane->seats);
    //printf("x: %d y: %d\n", _plane->x, _plane->y);

    for (int i = 0; i < _plane->x; i++)
    {
        fwrite(_plane->seats[i], sizeof(seat), _plane->y, fp);
    }

    //destruct_seats(_plane);
}

void load_seats(FILE* fp, plane* _plane)
{

    init_seats(_plane);
    //printf("load values ptr: %d\n", _plane->seats);

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
        //printf("%d\n", i);
        save_seats(fp_seats, &(_plane[i]));
        fwrite(&_plane[i], sizeof(plane), 1, fp);
    }

    fclose(fp_seats);
    fclose(fp);
}

void destruct_plane(plane* _plane, int N)
{
    for (int i = 0; i < N; i++)
    {
        destruct_seats(&_plane[i]);
    }
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

void print_all(plane *_plane, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (_plane[i].y && _plane[i].x)
        {
            printf("\nFlight: %d\n\n", i);
            printf("Flying from %s to %s\n\n", _plane[i].start, _plane[i].end);
            printf("Plane size: %d by %d\n\n", _plane[i].y, _plane[i].y);
            for (int jy = 0; jy < _plane[i].y; jy++)
            {
                for (int jx = 0; jx < _plane[i].x; jx++)
                {
                    printf("    customer name: %s\n", _plane[i].seats[jy][jx].customer_name);
                    printf("    seat: %d %d", jx, jy);
                    printf("    status: %d", _plane[i].seats[jy][jx].status);
                    printf("    price: %f", _plane[i].seats[jy][jx].price);
                    printf("    payment details: %d", _plane[i].seats[jy][jx].payment_details);
                    printf("    expiry date: %d/%d/%d\n", _plane[i].seats[jy][jx].expiration_date[0],_plane[i].seats[jy][jx].expiration_date[1],_plane[i].seats[jy][jx].expiration_date[2]);
                }
            }
            printf("\n");
        }
    }
}
