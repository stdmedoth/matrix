MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./includes
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/matrix.o
CFLAGS  := -I $(INCLUDE) -g -lm

.PHONY: all run clean

all: $(OBJS)
	$(info Joining files)
	$(MKDIR) -p $(BIN)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(info Making $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):	
	$(MKDIR) -p $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(OBJ) $(BIN) $(EXE) 