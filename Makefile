CC = gcc

CFLAGS = -Wall
ARFLAGS = rc

EXE=calendar

SRCDIR = src
BUILDDIR = build

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: $(EXE)

$(BUILDDIR):
	@echo "Create build directory"
	@mkdir -p $@

$(EXE): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)

# .o files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Clean project"
	@rm -fr $(BUILDDIR) calendar ||: