##
## EPITECH PROJECT, 2020
## OOP_nanotekspice_2019
## File description:
## Makefile
##

SRC	=	src/Chip4001.cpp		\
		src/Chip4008.cpp		\
		src/Chip4011.cpp		\
		src/Chip4030.cpp		\
		src/Chip4071.cpp		\
		src/Chip4081.cpp		\
		src/Chip4069.cpp		\
		src/Chip4013.cpp		\
		src/Chip4514.cpp		\
		src/NanoTekSpice.cpp	\
		src/Parse.cpp

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
