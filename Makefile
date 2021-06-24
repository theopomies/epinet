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
	@$(RM) $(OBJS)
	@$(RM) *.gcno
	@$(RM) *.gcda

fclean:	clean
	@$(RM) $(TARGET_LIB)
	@$(RM) $(TARGET_TESTS)

re:	fclean all

tests_run:	re $(TEST_OBJS)
	@$(CC) -o $(TARGET_TESTS) $(addprefix $(DIR_TESTS), $(TESTS_SRCS)) \
	$(TESTS_FLAGS) $(CPPFLAGS) $(CFLAGS)
	./unit_tests

.PHONY:	all clean fclean re tests_run
