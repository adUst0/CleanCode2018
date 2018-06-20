CC = g++
CFLAGS = -Wall -std=gnu++0x

ODIR = ../obj

_OBJ = Date.o Country.o USDateFormatter.o BGDateFormatter.o ISODateFormatter.o DateFormatterFactory.o Device.o Printer.o PC.o Laptop.o Shop.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: Tester.exe

Tester.o: Tester.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

Tester.exe: $(OBJ) Tester.o
	@echo "** Building tester"
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	@echo "** Removing Tester object file and executable..."
	rm -f Tester.exe Tester.o

rebuild: clean all

run: all
	./Tester.exe