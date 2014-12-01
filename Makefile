CC=gcc
CFLAGS=-Wall -ggdb -DDEBUG
SOURCES=parser.c scanner.c
HEADERS=scanner.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=p2i
LDFLAGS=

all: $(EXECUTABLE)

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^>>./.depend;

include .depend

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) .depend
