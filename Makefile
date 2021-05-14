CHECKER		=	checker
PUSH_SWAP	=	push_swap

CC			=	clang #-g -Wall -Werror -Wextra

RM			=	rm -rf

LIBSH		=	libsh/libsh.a

INCS		=	-I./includes

SRCS_NAME	=	srcs/get_next_line.c					\
				srcs/ps_error.c							\
				srcs/ps_ok_ko.c							\
				srcs/sort_ref_stack.c					\
				push_swap_lib/pa.c						\
				push_swap_lib/pb.c						\
				push_swap_lib/sa.c						\
				push_swap_lib/sb.c						\
				push_swap_lib/ss.c						\
				push_swap_lib/ra.c						\
				push_swap_lib/rb.c						\
				push_swap_lib/rr.c						\
				push_swap_lib/rra.c						\
				push_swap_lib/rrb.c						\
				push_swap_lib/rrr.c						\
				stack_lib/sl_push_back.c				\
				stack_lib/sl_stackdup.c					\
				stack_lib/sl_get_min.c					\
				stack_lib/sl_get_max.c					\
				stack_lib/sl_get_size.c					\
				stack_lib/sl_check_sorted.c				\
				stack_lib/sl_push_front.c				\
				stack_lib/sl_create_elem.c				\
				stack_lib/sl_print_stack.c				\
				stack_lib/sl_free_stack.c				\
				stack_lib/sl_tab_to_stack.c				\
				stack_lib/sl_last_elem.c				\
				stack_lib/sl_rotate_up.c				\
				stack_lib/sl_rotate_down.c				\
				stack_lib/sl_swap_first_two.c			\
				stack_lib/sl_remove_first_elem.c		\
				stack_lib/sl_check_error_stack.c		\
				stack_lib/sl_push.c						\
				algo_lib/alg_simple_sa_ra.c				\
				algo_lib/alg_pivot.c					\
				algo_lib/alg_three_less.c				\

PS_SRCS_NAME	= srcs/push_swap.c						\

CH_SRCS_NAME	= srcs/checker.c						\
				

SRCS_PATH	= ./
OBJS_PATH	= ./objs/

SRCS	= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
CH_SRCS	= $(addprefix $(SRCS_PATH), $(CH_SRCS_NAME))
PS_SRCS	= $(addprefix $(SRCS_PATH), $(PS_SRCS_NAME))
OBJS	= $(SRCS:.c=.o)
CH_OBJS	= $(CH_SRCS:.c=.o)
PS_OBJS	= $(PS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJS) $(CH_OBJS) 
	make -C libsh/
	$(CC) $(OBJS) $(CH_OBJS) $(LIBSH) $(INCS) -o $(CHECKER)

$(PUSH_SWAP): $(OBJS) $(PS_OBJS) 
	make -C libsh/
	$(CC) $(OBJS) $(PS_OBJS) $(LIBSH) $(INCS) -o $(PUSH_SWAP)

clean:
	make clean -C libsh/
	$(RM) $(OBJS)
	$(RM) $(CH_OBJS)
	$(RM) $(PS_OBJS)
	$(RM) $(OBJS_PATH)

fclean: clean
	make fclean -C libsh/
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)

relib:
	make re -C libsh/

re: fclean relib all

norme: clean 
	norminette

