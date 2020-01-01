LINK_TARGET = airways-info-system
CFLAGS = -I.
OBJS = database_admin.o flight_database.o main.o
DEPS = database_admin.h flight_database.h

CC = gcc

REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean:
	rm -f $(REBUILDABLES)
	echo Clean complete

all: $(LINK_TARGET)
	echo All done

$(LINK_TARGET): $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
