#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_stack {
    int *astack;
	int *bstack;
	int atop;
	int btop;
    int size;
} t_stack;

int			asorted(t_stack *stack);
int			bsorted(t_stack *stack);
void		three(t_stack *stack);
void		four(t_stack *stack);
void		five(t_stack *stack);
int			doublechecker(int *num, t_stack *stack);
int			sorter(t_stack *stack);
int			main(int argc, char **argv);
int			sa(t_stack *stack);
int			sb(t_stack *stack);
int			ss(t_stack *stack);
int			pb(t_stack *stack);
int			pa(t_stack *stack);
int			ra(t_stack *stack);
int			rb(t_stack *stack);
int			rr(t_stack *stack);
int			rra(t_stack *stack);
int			rrb(t_stack *stack);
int			bits(int num);
void		radix(t_stack *stack);
int			subcounter(const char *s, char c);
void		free_split(char **res);
char		*extract_substring(const char *s, char c);
int			ft_split2(char const *s, char c, char **res);
char		**ft_split(char const *s, char c);
void		rid(t_stack *stack);
int			full(t_stack *stack, int top);
void		ft_aswap(t_stack *stack);
void		ft_bswap(t_stack *stack);
int			rrr(t_stack *stack);
void		norm(t_stack *stack, int *sorted);
void		normalizer(t_stack *stack);
int			ft_atoi(const char *str);
void		stabler(t_stack *stack, char **argv);
t_stack		*stopfer(char **argv);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
char		**notsplit(char **s, int argc);
int			ft_strcmp(int s1, int s2);
int			*cpyarr(int *arr, int *cpy, int count);

#endif