typedef struct seat_data
{
    char customer_name[10];
    float price;
    int payment_details;
    int expiration_date[3];
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

void init_seats(plane* _plane);

void set_values(plane* _plane);;

void print_values(plane* _plane);

void destruct_seats(plane* _plane);

void save_seats(FILE *fp, plane* _plane);

void load_seats(FILE* fp, plane* _plane);

void save_plane(plane* _plane, int N);

void load_plane(plane* _plane, int N);

void set_null(plane *_plane, int N);

void print_all(plane *_plane, int N);

void destruct_plane(plane* _plane, int N);
