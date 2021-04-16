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
	ar rc $(TARGET_LIB) $(OBJS)

clean:
	rm -f $(wildcard *.o)

fclean:	clean
	rm -f $(TARGET_LIB)

re:	fclean all
.PHONY:	all clean fclean re