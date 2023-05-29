NAME	=	fractol

SRCS	= main.c \
		  utils.c \
		  mandelbrot.c \
		  draw.c \
		  struct_in.c \
		  julia.c \
		  zoom.c \
		  handles.c \
		  burnship.c \
		  parse.c \
		  parse2.c \
		  

OBJS	=	$(SRCS:.c=.o)
LIB		=	./minilibx-linux/libmlx_Linux.a

COMPILE	=	cc -g -Wall -Wextra -Werror -O3 -march=native -ffast-math  #-fsanitize=address

REMOVE	=	@rm -f

.c.o:
		$(COMPILE)  -c $< -o $@

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)	

all:		$(NAME)

clean:
			$(REMOVE) $(OBJS)

fclean:		clean
			$(REMOVE) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re