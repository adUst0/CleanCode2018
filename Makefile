CC = g++
CFLAGS = -Wall -std=c++11

SDIR = src
ODIR = obj

_OBJ = Date.o main.o USDateFormatter.o BGDateFormatter.o ISODateFormatter.o DateFormatterFactory.o Device.o Printer.o
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