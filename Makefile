CC = g++
CFLAGS = -Wall -std=gnu++0x

SDIR = src
ODIR = obj

_OBJ = Date.o Country.o main.o USDateFormatter.o BGDateFormatter.o ISODateFormatter.o DateFormatterFactory.o Device.o Printer.o PC.o Laptop.o Shop.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BIN = Shop.exe

all: $(BIN)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

$(BIN): $(OBJ)
	@echo "** Building project"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f $(BIN) $(ODIR)/*.o

rebuild: clean all
	
run: all
	./$(BIN)