##
## EPITECH PROJECT, 2024
## HUB-Workshop-Criterion
## File description:
## Makefile
##

CC	:=	gcc

CFLAGS	=	-I./include/
CFLAGS	+=	-W -Wall -Wextra -Wpedantic

NAME	=	gameoflife

SRC	=	src/gameoflife.c
SRC	+=	src/parser.c
SRC	+=	src/my_strlen.c
SRC	+=	src/my_str_to_word_arr_s.c
SRC	+=	src/error_handling.c
SRC	+= 	src/life_or_death.c

TEST_SRC := $(SRC)
TEST_SRC += ./tests/my_test.c

SRC	+=	src/main.c

TEST_OBJ = $(TEST_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	@ rm -f $(OBJ)
	@ rm -f $(TEST_OBJ)
	@ find . -name "*.gcda" -delete -o -name "*.gcno" -delete
	@ find . -name "*~" -delete
	@ find . -name "*#" -delete

fclean: clean
	@ rm -f $(NAME)
	@ rm -f unit_tests

re: fclean all

unit_tests: CFLAGS += -lcriterion --coverage -g3
unit_tests: fclean $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(CFLAGS) -o unit_tests

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re unit_tests tests_run
