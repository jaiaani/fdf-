NAME := libget_next_line.a

CC := cc

LIB := -L../libft -libft

CCFLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=1000

RM := rm -f

AR := ar rcs

SRCS =  get_next_line.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

