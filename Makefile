all:
	cd ft_printf && make
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a push_swap*.c -o push_swap

clean:
	@make clean -C ft_printf
	rm -f push_swap

fclean: clean
	@make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re bonus
