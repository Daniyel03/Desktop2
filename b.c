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
	if (stack->atop < 1)
		return 0;
	ft_aswap(stack);
	return 1;
}

int sb(t_stack *stack)
{
	if (stack->btop < 1)
		return 0;
	ft_bswap(stack);
	return 1;
}

int ss(t_stack *stack)
{
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	ft_aswap(stack);
	ft_bswap(stack);
	return 1;
}

int pb(t_stack *stack)
{
	if(!stack->astack || full(stack, stack->btop))
		return 0;
	int temp1;
	int one = (stack->btop + 1);
	temp1 = stack->astack[stack->atop];
	stack->bstack[stack->btop + 1] = temp1;
	stack->btop = one;
	one = (stack->atop - 1);
	stack->atop = one;
	return 1;
}

int pa(t_stack *stack)
{
	if(!stack->bstack || full(stack, stack->atop))
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
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	rb(stack);
	ra(stack);
	return 1;
}

int rra(t_stack *stack)
{
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
	if (stack->atop < 1 || stack->btop < 1)
		return 0;
	rrb(stack);
	rra(stack);
	return 1;
}

void three(t_stack *stack)
{
	if(stack->astack[0] == 2 && stack->astack[1] == 3 && stack->astack[2] == 1)
		ra(stack);
	if(stack->astack[0] == 3 && stack->astack[1] == 1 && stack->astack[2] == 2)
		rra(stack);
	if(stack->astack[0] == 1 && stack->astack[1] == 3 && stack->astack[2] == 2)
		sa(stack);
	if(stack->astack[0] == 2 && stack->astack[1] == 1 && stack->astack[2] == 3)
	{
		rra(stack);
		sa(stack);
	}
	if(stack->astack[0] == 3 && stack->astack[1] == 2 && stack->astack[2] == 1)
		ra;
		sa;
}

int doublechecker(int *num)
{
	int i = 0;
	int j = 0;
	while(num[i])
	{
		j = (i + 1);
		while(num[j])
		{
			if (num[i] == num[j++])
				return 1;
		}
		i++;
	}
	return 0;
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


int	*cpyarr(int *arr, int *cpy)
{
	int i = 0;
	while (arr[i])
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
	cpy = cpyarr(stack->astack, cpy);

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

int sorted(t_stack *stack)
{
	int i = 0;
	while (i < (stack->size - 1))
	{
		if (!(ft_strcmp(stack->astack[i], stack->astack[i + 1]) == -1))
			return 0;
		i++;
	}
	return 1;
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
	cpy = cpyarr(stack->astack, cpy);
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

void stabler(t_stack *stack, char **argv, int i) {
    int j = 0;
    int count = 0;
	int mark = 0;

    while (count < (stack->size)) {
        while (argv[count][j] != '\0') {
			if (!(argv[count][j] >= '0' && argv[count][j] <= '9' || argv[count][j] == '-'))
				rid(stack);
			if (argv[count][j] == '-')
			{
				j++;
				mark = 1;
			}
			stack->astack[count] *= 10;
			stack->astack[count] += (argv[count][j] - 48);
			if(mark)
				stack->astack[count] *= -1;
            j++;
        	mark = 0;
		}
		count++;
        j = 0; 
    }
	if (doublechecker(stack->astack))
		rid(stack);

	normalizer(stack);
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
    stack->btop = 0; 
    stack->size = i;
    stabler(stack, argv, i);
    return stack;
}

	int sorter(t_stack *stack)
	{
		if (stack->atop == 1)
			sa(stack);
		if (stack->atop == 2)
			three(stack);
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

    if (stack) {
        int i = stack->atop;
        while (stack->astack[i]) {
            printf("%d\n", stack->astack[i]);
            i--;
        }
    }

	if(sorted(stack))
	{
		printf("already sorted\n");
		return 0;
	}
	else
		sorter(stack);

    if (stack) {
        int i = stack->atop;
        while (stack->astack[i]) {
            printf("%d\n", stack->astack[i]);
            i--;
        }
    }

// 
	if(sorted(stack))
		printf("sorted\n");
	// else
	// 	printf("fail\n");

    return 0;
}

// all possible combinations for 3 digits plus one solution like 1 3 2 = sa
