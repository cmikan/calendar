CC = gcc

CFLAGS = -Wall
ARFLAGS = rc

EXE = calendar

SRCDIR = src
BUILDDIR = build

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Super useful variables
GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
CYAN=\033[0;36m
RED=\033[0;31m
NC=\033[0m

all: $(EXE)

$(BUILDDIR):
	@echo "$(GREEN)Create $(BLUE)build$(GREEN) directory$(NC)"
	@mkdir -p $@

$(EXE): $(OBJ)
	@echo "$(YELLOW)Compiling $(CYAN)$(notdir $@)$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJ)

# .o files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	@echo "$(YELLOW)Compiling $(BLUE)$(notdir $@)$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Clean project$(NC)"
	@rm -fr $(BUILDDIR) calendar ||: