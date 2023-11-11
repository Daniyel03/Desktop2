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

	temp1 = stack->bstack[stack->btop - 2];
	temp2 = stack->bstack[stack->btop - 3];
	stack->bstack[stack->btop - 2] = temp2;
	stack->bstack[stack->btop - 3] = temp1;
}

int sa(t_stack *stack)
{
	if (stack->atop < 2)
		return 0;
	ft_aswap(stack);
	return 1;
}

int sb(t_stack *stack)
{
	if (stack->btop < 2)
		return 0;
	ft_bswap(stack);
	return 1;
}

int ss(t_stack *stack)
{
	if (stack->atop < 2 || stack->btop < 2)
		return 0;
	ft_aswap(stack);
	ft_bswap(stack);
	return 1;
}

// int pb(t_stack *stack)
// {
// 	if(!stack->btop)
// 		return 0;
// 	int temp1;
// 	int temp2;
// 	temp1 = stack->astack[]
// }

int full(t_stack *stack, int top)
{
	if (stack->size == top)
		return 1;
	else
		return 0;
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
        int i = 0;
        while (stack->astack[i]) {
            printf("%d\n", stack->astack[i]);
            i++;
        }
    }

	sa(stack);

    if (stack) {
        int i = stack->atop;
        while (stack->astack[i]) {
            printf("%d\n", stack->astack[i]);
            i--;
        }
    }

	if(sorted(stack))
		printf("sorted\n");

    return 0;
}
