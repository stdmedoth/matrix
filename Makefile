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
CFLAGS  := -I $(INCLUDE) -g

.PHONY: all run clean

all: $(OBJS)
	$(info Joining files)
	$(MKDIR) -p $(BIN)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) -lm

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(info Making $@)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

$(BIN) $(OBJ):	
	$(MKDIR) -p $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(OBJ) $(BIN) $(EXE) 