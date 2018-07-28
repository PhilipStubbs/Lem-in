
NAME = lem-in

SRC = src/connectlinks.c \
	src/deldouble.c \
	src/dellst.c \
	src/destroy.c \
	src/findpath.c \
	src/ft_doublesize.c \
	src/ft_strmerge.c \
	src/getinfo.c \
	src/isvalid.c \
	src/listsize.c \
	src/malloctime.c \
	src/moveants.c \
	src/rooms.c \
	src/setlinks.c \
	src/startandend.c \
	src/main_lem_in.c \

OBJ = *.o

all: $(NAME)

$(NAME) :
	make -C libft/
	gcc -c -Wall -Werror -Wextra $(SRC) -I./includes
	gcc -o $(NAME) $(OBJ) -I./includes -L. libft/libft.a
	rm -f $(OBJ)
	@echo "lem-in created" 

lib:
	make re -C libft/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all