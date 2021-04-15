##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile config
##

CC			=	gcc
CPPFLAGS	=	-Iinclude
CFLAGS		=	-fPIC -Wall -Wextra -O2
LDFLAGS		=	-shared
RM			=	rm -f
TARGET_LIB 	=	epinet.so
OBJS		=	$(SRCS:.c=.o)
