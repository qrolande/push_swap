NAME 		=	push_swap

BONUSNAME	= 	checker

SRCS  		=	push_swap.c \
				srcs/end.c  					modif_libft/ft_atoi.c \
				srcs/push_to_a.c 				modif_libft/ft_split.c \
				srcs/commands_a.c 				modif_libft/ft_lstnew.c \
				srcs/commands_b.c 				modif_libft/ft_lstlast.c \
				srcs/indexation.c 				modif_libft/ft_lstsize.c \
				srcs/lets_begin.c 				modif_libft/ft_lstclear.c \
				srcs/count_steps.c 				modif_libft/ft_lstdelone.c \
				srcs/swap_stacks.c 				modif_libft/ft_lstadd_back.c \
				srcs/commands_both.c \
				srcs/main_algorithm.c \
				srcs/cleaning_company.c \
			 	srcs/algorithm_under_three.c \

BONUS_SRCS	=	checker.c						modif_libft/ft_atoi.c \
				bonus/cleaning_company.c		modif_libft/ft_split.c \
				bonus/commands_a.c 				modif_libft/ft_lstnew.c \
				bonus/commands_b.c 				modif_libft/ft_lstlast.c \
				bonus/commands_both.c			modif_libft/ft_lstsize.c \
				bonus/indexation.c				modif_libft/ft_lstclear.c \
				bonus/just_do_it.c 				modif_libft/ft_lstdelone.c \
				bonus/lets_begin.c 				modif_libft/ft_lstadd_back.c \
				bonus/ko_out.c					modif_libft/get_next_line.c  \
				bonus/search.c					modif_libft/ft_strnstr.c 
						
OBJS		=	${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CC			= 	gcc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	push_swap.h

INC_BONUS	=	checker.h

%.o : %.c	$(INCLUDES)
			${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o} 


all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus:		$(BONUS_OBJS) $(INC_BONUS)
			${CC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUSNAME}

clean:		
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME} ${BONUSNAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
