all:
	cd ft_printf && make
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a *.c -o checker

clean:
	@make clean -C ft_printf
	rm -f checker

fclean: clean
	@make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re bonus
