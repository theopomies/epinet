##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile
##

include mk/sources.mk
include mk/config.mk

all:	${TARGET_LIB}

$(TARGET_LIB):	$(OBJS)
	@ar rc $(TARGET_LIB) $(OBJS)

clean:
	@rm -f $(wildcard *.o)
	@rm -f *.gcno
	@rm -f *.gcda

fclean:	clean
	@rm -f $(TARGET_LIB)
	@rm -f $(TARGET_TESTS)

re:	fclean all

tests_run:	re
	@$(CC) -o $(TARGET_TESTS) $(addprefix $(DIR_TESTS), $(TESTS_SRCS)) \
	$(TESTS_FLAGS) $(CPPFLAGS)
	./unit_tests

.PHONY:	all clean fclean re tests_run