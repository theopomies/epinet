##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile config
##

CC			=	gcc
CPPFLAGS	=	-Iinclude
CFLAGS		=	-Wall -Wextra -O2
LDFLAGS		=
RM			=	rm -f
TARGET_LIB 	=	epinet.a
OBJS		=	$(SRCS:.c=.o)
