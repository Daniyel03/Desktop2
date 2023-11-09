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



    // write a struct to perfome actions with my stack
typedef struct s_stack {
    int *stack;
    int top;
    int size;
} t_stack;

void stabler(t_stack *astack, char **argv, int i) {
    int j = 0;
    int count = 0;

    while (count < i) {
        while (argv[count][j] != '\0') {
            astack->stack[count] *= 10;
			astack->stack[count] += (argv[count][j] - 48);
            j++;
        }
        count++;
        j = 0; // Reset j for the next string
    }
}

t_stack *stopfer(char **argv) {
    int i = 0;
    while (argv[i])
        i++;
    if (!i)
        return NULL;

    t_stack *astack = (t_stack *)malloc(sizeof(t_stack));
    if (!astack)
        return NULL;

    astack->stack = malloc(sizeof(int) * i);
    if (!astack->stack) {
        free(astack);
        return NULL;
    }

    astack->top = -1; // Initialize top
    astack->size = i;

    stabler(astack, argv, i);
    return astack;
}

int main(int argc, char **argv) {
    if (1 == argc || (2 == argc && !argv[1][0]))
        return 1;
    else if (2 == argc)
        argv = ft_split(argv[1], ' ');
	else
		argv = notsplit(argv, argc);

    t_stack *bstack = NULL;
    t_stack *astack = stopfer(argv);

    if (astack) {
        int i = 0;
        while (astack->stack[i]) {
            printf("%d\n", astack->stack[i]);
            i++;
        }
    }

    return 0;
}
