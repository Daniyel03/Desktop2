/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:48:16 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/17 16:48:56 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	subcounter(const char *s, char c)
{
	int	subs;

	subs = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			subs++;
		while (*s && *s != c)
			s++;
	}
	return (subs);
}

void	free_split(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	*extract_substring(const char *s, char c)
{
	const char	*start;
	int			len;
	char		*substring;
	int			i;

	start = s;
	while (*s && *s != c)
		s++;
	len = s - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = start[i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}

static int	ft_split2(char const *s, char c, char **res)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = extract_substring(s, c);
			if (!res[i])
			{
				free_split(res);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		subs;
	char	**res;

	subs = subcounter(s, c);
	res = (char **)malloc((subs + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_split2(s, c, res))
		res[subs] = (NULL);
	else
		return (NULL);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char **notsplit(char **s, int argc)
{
	int i = (argc - 2);
	char **argv;

	argv = (char **)malloc(argc * sizeof(char *));
	if (!argv)
	{
		free(argv);
		return 0;
	}

	argc--;
	while (i >= 0)
	{
		argv[i] = ft_strdup(s[argc]);
		i--;
		argc--;
	}
	argv[argc - 1] = NULL;

	return argv;
	
}

typedef struct s_stack {
    int *astack;
	int *bstack;
	int atop;
	int btop;
    int size;
} t_stack;

void rid(t_stack *stack)
{
	free(stack->astack);
	free(stack->bstack);
	free(stack);
	printf("ne diggah\n");
	exit(EXIT_FAILURE);
}

int full(t_stack *stack, int top)
{
	if (stack->size == top)
		return 1;
	else
		return 0;
}

void	ft_aswap(t_stack *stack)
{
	int temp1;
	int temp2;

	temp1 = stack->astack[stack->atop];
	temp2 = stack->astack[stack->atop - 1];
	stack->astack[stack->atop] = temp2;
	stack->astack[stack->atop - 1] = temp1;
}

void	ft_bswap(t_stack *stack)
{
	int temp1;
	int temp2;

	temp1 = stack->bstack[stack->btop];
	temp2 = stack->bstack[stack->btop - 1];
	stack->bstack[stack->btop] = temp2;
	stack->bstack[stack->btop - 1] = temp1;
}

int sa(t_stack *stack)
{
	printf("sa\n");
	if (stack->atop < 1)
		return 0;
	ft_aswap(stack);
	return 1;
}

int sb(t_stack *stack)
{
	printf("sb\n");
	if (stack->btop < 1)
		return 0;
	ft_bswap(stack);
	return 1;
}

int ss(t_stack *stack)
{
	printf("ss\n");
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	ft_aswap(stack);
	ft_bswap(stack);
	return 1;
}

int pb(t_stack *stack)
{
	printf("pb\n");
	if(stack->atop == -1 || full(stack, stack->btop))
		return 0;
	int temp1;
	int one = (stack->btop + 1);
	stack->btop = one;
	temp1 = stack->astack[stack->atop];
	stack->bstack[stack->btop] = temp1;
	one = (stack->atop - 1);
	stack->atop = one;
	return 1;
}

int pa(t_stack *stack)
{
	printf("pa\n");
	if(stack->btop == -1 || full(stack, stack->atop))
		return 0;
	int temp1;
	int one = (stack->atop + 1);
	temp1 = stack->bstack[stack->btop];
	stack->astack[stack->atop + 1] = temp1;
	stack->atop = one;
	one = (stack->btop - 1);
	stack->btop = one;
	return 1;
}

int ra(t_stack *stack)
{
	printf("ra\n");
	int temp1;
	int temp2;
	int count = stack->atop;
	if (stack->atop < 1)
		return 0;
	while(count > 0)
	{
		temp1 = stack->astack[count];
		temp2 = stack->astack[count - 1];
		stack->astack[count] = temp2;
		stack->astack[count - 1] = temp1;
		count--;
	}
	return 1;
}

int rb(t_stack *stack)
{
	printf("rb\n");
	int temp1;
	int temp2;
	int count = stack->btop;
	if (stack->btop < 1)
		return 0;
	while(count > 0)
	{
		temp1 = stack->bstack[count];
		temp2 = stack->bstack[count - 1];
		stack->bstack[count] = temp2;
		stack->bstack[count - 1] = temp1;
		count--;
	}
	return 1;
}

int rr(t_stack *stack)
{
	printf("rr\n");
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	rb(stack);
	ra(stack);
	return 1;
}

int rra(t_stack *stack)
{
	printf("rra\n");
	int temp1;
	int temp2;
	int count = 0;
	if (stack->atop < 1)
		return 0;
	while(count < stack->atop)
	{
		temp1 = stack->astack[count];
		temp2 = stack->astack[count + 1];
		stack->astack[count] = temp2;
		stack->astack[count + 1] = temp1;
		count++;
	}
	return 1;
}

int rrb(t_stack *stack)
{
	printf("rrb\n");
	int temp1;
	int temp2;
	int count = 0;
	if (stack->btop < 1)
		return 0;
	while(count < stack->btop)
	{
		temp1 = stack->bstack[count];
		temp2 = stack->bstack[count + 1];
		stack->bstack[count] = temp2;
		stack->bstack[count + 1] = temp1;
		count++;
	}
	return 1;
}

int rrr(t_stack *stack)
{
	printf("rrr\n");
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	rrb(stack);
	rra(stack);
	return 1;
}

int	ft_strcmp(int s1, int s2)
{
	while (s1 == s2 && s1)
	{
		s1++;
		s2++;
	}
	return (s1 - s2);
}


int asorted(t_stack *stack)
{
	int i = 0;
	while (i < stack->atop)
	{
		if (!(ft_strcmp(stack->astack[i], stack->astack[i + 1]) == 1))
			return 0;
		i++;
	}
	return 1;
}

int bsorted(t_stack *stack)
{
	int i = 0;
	while (i < stack->btop)
	{
		if (!(ft_strcmp(stack->bstack[i], stack->bstack[i + 1]) == 1))
			return 0;
		i++;
	}
	return 1;
}

void three(t_stack *stack)
{
	if(stack->astack[2] == 2 && stack->astack[1] == 3 && stack->astack[0] == 1)
		rra(stack);
	else if(stack->astack[2] == 3 && stack->astack[1] == 1 && stack->astack[0] == 2)
		ra(stack);
	else if(stack->astack[2] == 1 && stack->astack[1] == 3 && stack->astack[0] == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if(stack->astack[2] == 2 && stack->astack[1] == 1 && stack->astack[0] == 3)
		sa(stack);
	else if(stack->astack[2] == 3 && stack->astack[1] == 2 && stack->astack[0] == 1)
	{
		ra(stack);
		sa(stack);
	}
}

void four(t_stack *stack)
{
	while (stack->astack[stack->atop] != 4)
		rra(stack);
	pb(stack);
	three(stack);
	pa(stack);
	ra(stack);
}

void five(t_stack *stack)
{
	int count = 0;

	while (count != 2)
	{
		if (stack->astack[stack->atop] == 4 || stack->astack[stack->atop] == 5)
		{
			pb(stack);
			count++;
		}
		if (count == 2)
			break ;
		rra(stack);
	}
	if (bsorted(stack))
		sb(stack);
	three(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	ra(stack);
}

int bits(int num) {
    int count = 0;

    while (num) {
        count++;
        num >>= 1;
    }

    return count;
}

void radix(t_stack *stack)
{
	int i = 0;
	int shift = 0;
	int count = bits(stack->size);
	int temp;
	while (shift < count)
	{
		i = 0;
		while (i < (stack->size))
		{
			temp = stack->astack[stack->atop];
			temp = temp >> shift;
			if((temp&1) == 0)
				pb(stack);
			else
				ra(stack);
			i++;
		}
	// 	    if (stack) {
    //     int i = stack->btop;
    //     while (stack->bstack[i]) {
    //         printf("%d\n", stack->bstack[i]);
    //         i--;
    //     }
    // }

		while(stack->btop != -1)
			pa(stack);
		shift++;
	}
	temp = 0;
}

// void radix(t_stack *stack)
// {
//     int shift = 0;

//     while (shift < bits(stack->size))
//     {
//         int i = 0;

//         while (i < stack->size)
//         {
//             int temp = stack->astack[0];
//             int bit = (temp >> shift) & 1;

//             if (bit == 0)
//                 pb(stack);
//             else
//                 ra(stack);

//             i++;
//         }

//         while (stack->btop != -1)
//             pa(stack);

//         shift++;
//     }
// }

int doublechecker(int *num, t_stack *stack)
{
	int i = 0;
	int j = 0;
	int count = stack->size;
	while(i < count)
	{
		j = (i + 1);
		while(j < count)
		{
			if (num[i] == num[j++])
				return 1;
		}
		i++;
	}
	return 0;
}


int	*cpyarr(int *arr, int *cpy, int count)
{
	int i = 0;
	while (i < count)
	{
		cpy[i] = arr[i];
		i++;
	}
	return cpy;
}


void norm(t_stack *stack, int *sorted)
{
	int i = 0;
	int j = 0;
	int *cpy = malloc(sizeof(int) * stack->size);
	if (!cpy)
	{
		free(cpy);
		rid(stack);
	}
	cpy = cpyarr(stack->astack, cpy, stack->size);

	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (sorted[i] == cpy[j])
			{
				stack->astack[j] = (i + 1);
				break;
			}
			j++;
		}
		i++;
	}
	free(cpy);
	cpy = NULL;
}

void normalizer(t_stack *stack)
{	
	int i = 0;
	int j = 0;
	int tmp = 0;
	int *cpy = malloc(sizeof(int) * stack->size);
	if (!cpy)
	{
		free(cpy);
		rid(stack);
	}
	cpy = cpyarr(stack->astack, cpy, stack->size);
	while (i < (stack->size - 1))		// bubble sort
	{
		j = (i + 1);
		while (j < stack->size)
		{
			if (cpy[i] > cpy[j])
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
			j++;
		}
		i++;
	}

	norm(stack, cpy);
	free(cpy);
	cpy = NULL;
}

// void stabler(t_stack *stack, char **argv, int i) {
//     int j = 0;
//     int count = 0;
// 	int stackk = (stack->size - 1);
// 	int mark = 0;

//     while (count < (stack->size)) {
//         while (argv[count][j] != '\0') {
// 			if (!(argv[count][j] >= '0' && argv[count][j] <= '9' || argv[count][j] == '-'))
// 				rid(stack);
// 			if (argv[count][j] == '-')
// 			{
// 				j++;
// 				mark = 1;
// 			}
// 			if (argv[count][j] == '0' && argv[count][j + 1] == '\0')
// 			{
// 				stack->astack[stackk] = 0;
// 				break ;
// 			}
// 			stack->astack[stackk] *= 10;
// 			stack->astack[stackk] += (argv[count][j] - 48);
// 			if(mark)
// 				stack->astack[stackk] *= -1;
//             j++;
//         	mark = 0;
// 		}
// 		count++;
// 		stackk--;
//         j = 0; 
//     }
// 	if (doublechecker(stack->astack, stack))
// 	{
// 		printf("erraten\n");
// 		    if (stack) {
//         int i = stack->atop;
//         while (stack->astack[i]) {
//             printf("%d\n", stack->astack[i]);
//             i--;
//         }
//     }
// 		rid(stack);
// 	}normalizer(stack);
// }

int	ft_atoi(const char *str)
{
	int	res;
	int	op;

	res = 0;
	op = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			op = op * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (*str - 48);
		str++;
	}
	return (op * res);
}

void stabler(t_stack *stack, char **argv, int i) {
    int j = 0;
    int count = 0;
	int stackk = (stack->size - 1);
	int mark = 0;

    while (count < (stack->size)) {
		stack->astack[stackk] = ft_atoi(argv[count]);
		count++;
		stackk--;
    }
	if (doublechecker(stack->astack, stack))
	{
		printf("erraten\n");
		    if (stack) {
        int i = stack->atop;
        while (stack->astack[i]) {
            printf("%d\n", stack->astack[i]);
            i--;
        }
    }
		rid(stack);
	}normalizer(stack);
}

t_stack *stopfer(char **argv) {
    int i = 0;

    while (argv[i])
        i++;
    if (!i)
        return NULL;
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL; 
    stack->astack = malloc(sizeof(int) * i);
    stack->bstack = malloc(sizeof(int) * i);
    if (!stack->astack || !stack->bstack) {
        free(stack); // rid instead?
        return NULL;
    }
    stack->atop = i - 1; 
    stack->btop = -1; 
    stack->size = i;
		if (stack) {
		int i = 0;
	}
    stabler(stack, argv, i);
    return stack;
}

	int sorter(t_stack *stack)
	{
		if (stack->atop == 1)
			sa(stack);
		else if (stack->atop == 2)
			three(stack);
		else if (stack->atop == 3)
			four(stack);
		else if (stack->atop == 4)
			five(stack);
		else
		{
			radix(stack);
		}
		return 1;	
	}
	
	int main(int argc, char **argv) {
    if (1 == argc || (2 == argc && !argv[1][0]))
        return 1;
    else if (2 == argc)
        argv = ft_split(argv[1], ' ');
	else
		argv = notsplit(argv, argc);
	if (!argv)
		return 0;

    t_stack *stack;
	stack = stopfer(argv);

    // if (stack) {
    //     int i = stack->atop;
    //     while (stack->astack[i]) {
    //         printf("%d\n", stack->astack[i]);
    //         i--;
    //     }
    // }

	// if(asorted(stack))
	// {
	// 	printf("already asorted\n");
	// 	return 0;
	// }
	// else
		sorter(stack);

	// printf("\n");

    // if (stack) {
    //     int i = stack->atop;
    //     while (stack->astack[i]) {
    //         printf("%d\n", stack->astack[i]);
    //         i--;
    //     }
    // }

	// if(asorted(stack))
	// 	printf("sorted\n");
	// else
	// 	printf("fail\n");

    return 0;
}
