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



// int empty(t_stack *stack, int top)		stattdessen if(stack->a/btop == 0)
// {
// 	if (stack->top == 0)
// 		return 1;
// 	else
// 		return 0;
// }

// int doublechecker(int *num)
// {
// 	int i = 0;
// 	int j = 0;
// 	int count = 0;
// 	while(num[i])
// 	{
// 		j = 0;
// 		count = 0;
// 		while(num[j])
// 		{
// 			if (num[i] == num[j++])
// 				count++;
// 			if (count >= 2)
// 				return 1;
// 		}
// 		i++;
// 	}
// 	return 0;
// }

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

int *normalizer(t_stack *stack)
{
	int	i;
	int	count;
	int	sort;

	count = stack->size;
	sort = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (i < count)
		{
			if (ft_strcmp(stack->astack[i], stack->astack[i + 1]) > 0)
			{
				stack->astack[i] = (i + 1);
				sort = 0;
			}
			i++;
		}
		count--;
	}
	return (stack->astack);
}

void stabler(t_stack *stack, char **argv, int i) {
    int j = 0;
    int count = 0;

    while (count < i) {
        while (argv[count][j] != '\0') {
            stack->astack[count] *= 10;
			stack->astack[count] += (argv[count][j] - 48);
			if (!(argv[count][j] >= '0' && argv[count][j] <= '9'))
				rid(stack);
            j++;
        }
        count++;
        j = 0; 
    }
	if (doublechecker(stack->astack))
		rid(stack);
	stack->astack = normalizer(stack);
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
    stack->astack = malloc(sizeof(int) * i);
    if (!stack->astack || !stack->astack) {
        free(stack); // rid instead?
        return NULL;
    }
    stack->atop = 0; 
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

    return 0;
}
