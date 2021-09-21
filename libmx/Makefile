NAME = libmx.a

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
СС = clang

OBJD = obj
SRCD = src
INCD = -I inc/

SRCC = $(foreach dir, $(SRCD), $(wildcard $(dir)/*.c))

OBJS = $(SRCC:src/%.c=$(OBJD)/%.o)

.PHONY: all LIBMX $(OBJD) uninstall clean reinstall

all: LIBMX

LIBMX: $(OBJD) $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "created libmx\n"

$(OBJD)/%.o: $(SRCD)/%.c
	@$(CC) $(CFLAGS) $(INCD) -c $< -o $@

$(OBJD):
	@mkdir -p obj

uninstall: clean
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJD)
	
reinstall: uninstall LIBMX

