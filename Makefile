##
## EPITECH PROJECT, 2020
## OOP_nanotekspice_2019
## File description:
## Makefile
##

SRC	=	Chip4001.cpp		\
		Chip4071.cpp		\
		NanoTekSpice.cpp	\
		Parse.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

CPPFLAGS	=	-I./include

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean	all

.PHONY:	all	clean	fclean	re
