##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile
##

include mk/sources.mk
include mk/config.mk

all:	${TARGET_LIB}

$(TARGET_LIB):	$(OBJ)
	ar rc $(TARGET_LIB) $(OBJ)

clean:
	rm -f $(wildcard *.o)

fclean:	clean
	rm -f $(TARGET_LIB)
	rm -f ../$(TARGET_LIB)

re:	fclean all
.PHONY:	all clean fclean re