/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:51:05 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 16:05:31 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		test_isalpha(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isalpha(i) != isalpha(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isdigit(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isdigit(i) != isdigit(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isalnum(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isalnum(i) != isalnum(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isascii(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isascii(i) != isascii(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isprint(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isprint(i) != isprint(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_strncmp(void)
{
	char str[4][8] = {"", " ", "Ah", "Coucou"};

	int i=0;
	int j;
	int k;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if(ft_strncmp(str[i],str[j],k) != strncmp(str[i],str[j],k))
				{
					printf("    Params\n        s1 : '%s'\n        s2 : '%s'\n        k : %d\n    ft_strncmp : %d\n    strncmp : %d\n", str[i], str[j], k, ft_strncmp(str[i],str[j],k), strncmp(str[i],str[j],k));  
					return (0);
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
int		test_strcmp(void)
{
	char str[4][8] = {"", " ", "Ah", "Coucou"};

	int i=0;
	int j;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(ft_strcmp(str[i],str[j]) != strcmp(str[i],str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int		test_strlen(void)
{
	char *str="Coucou";
	char *str2="";
	if (ft_strlen(str) != strlen(str))
		return (0);
	if (ft_strlen(str2) != strlen(str2))
		return (0);
	return (1);
}

int		test_strdup(void)
{
	if (strcmp(ft_strdup("yo"),strdup("yo")) != 0)
		return (0);
	return (1);
}

int		test_strcpy(void)
{
	char dest[10];
	char *src="Coucou";
	if (strcmp(ft_strcpy(dest,src), strcpy(dest,src)) != 0)
		return (0);
	return (1);
}
int		test_strstr(void)
{
	char *s1="Coucou";
	char *s2="Cou";
	if(strcmp(ft_strstr(s1,s2), strstr(s1,s2)) != 0)
		return (0);
	return (1);

}

int		test_strnstr(void)
{
	char *s1="Coucou";
	char *s2="Cou";
	int i=0;
	while (i++ > 10)
		if(strcmp(ft_strnstr(s1,s2,i), strnstr(s1,s2,i)) != 0)
			return (0);
	return (1);
}

int		test_strncpy(void)
{
	char dest[10];
	char *src="Coucou";
	int i=0;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	i = 5;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	i = 10;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	return (1);
}

int		test_strcat(void)
{
	char *s = "c est ";
	char *s1 = "moi";
	char *target = malloc(strlen(s) + strlen(s1) + 1);
	strcpy(target, s);

	if (strcmp(ft_strcat(target,s1), strcat(target,s1)) != 0)
		return (0);
	free(target);
	return (1);
}

int		test_strchr(void)
{
	char *s = "Mercure Venus Terre";
	char c = ' ';
	char z = 'z';
	if (strcmp(ft_strchr(s,c), strchr(s,c)) != 0)
		return (0);
	if ((ft_strchr(s,z) != NULL && strchr(s,c) != NULL))
		return (0);
	return (1);
}
int		test_strrchr(void)
{
	char *s = "Mercure Venus Terre";
	char c = ' ';
	char z = 'z';
	if (strcmp(ft_strrchr(s,c), strrchr(s,c)) != 0)
		return (0);
	if ((ft_strrchr(s,z) != NULL && strrchr(s,c) != NULL))
		return (0);
	return (1);
}
int		test_strncat(void)
{
	char *s = "c est ";
	char *s1 = "moi";
	int i = 0;
	char *target = malloc(strlen(s) + strlen(s1) + 1);
	strcpy(target, s);
	while (i < 15)
	{
		if (strcmp(ft_strncat(target,s1,i), strncat(target,s1,i)) != 0)
			return (0);
		i++;
	}
	return (1);
}
int		test_strlcat(void)
{
	char *s = "c est ";
	char *s1 = "moi";
	char *s_ = "c est ";
	char *s1_ = "moi";
	int i = 0;
	size_t k;
	size_t j;
	char *target = malloc(strlen(s) + strlen(s1) + 1);
	char *target_ = malloc(strlen(s) + strlen(s1) + 1);
	strcpy(target, s);
	strcpy(target_, s_);
	while (i < 15)
	{
		k = ft_strlcat(target,s1,i);
		j = strlcat(target_,s1_,i);
		if (k != j)
			return (0);
		i++;
	}
	return (1);
}

int		test_atoi(void)
{
	char str[15][15] = 
	{
		{"000000110"},
		{"-153"},
		{"+132"},
		{"++876"},
		{"--132"},
		{"dwbk "},
		{"42jk "},
		{" 21"},
		{"      32 "},
		{"42 32 "},
		{"1-2"},
		{"4+2 "},
		{"	+442"},
		{"  -4232 "},
		{"4,5"},
	};

	int i=0;
	while (i < 15)
	{
		//	printf("%s = ", str[i]);
		//	printf("%d\n", atoi(str[i]));
		//	printf("%s = ", str[i]);
		//	printf("%d\n", ft_atoi(str[i]));
		if(atoi(str[i]) != ft_atoi(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		test_memset(void)
{
	char *str=strdup("C M B   D T C");
	int i = 0;
	while (i < 2)
	{
		if(strcmp(ft_memset(str, '$', i), memset(str, '$', i)))
			return (0);
		i++;
	}
	return (1);
}
int		test_bzero(void)
{
	char *str=strdup("C M B   D T C");
	char *str2=strdup("C M B   D T C");
	int i = 0;
	while (i < 15)
	{
		ft_bzero(str,i);
		bzero(str2,i);
		if(memcmp(str, str2, i) != 0)
			return (0);
		i++;
	}
	return (1);
}
int		test_memcmp(void)
{
	char str[4][8] = {"", " ", "Ah", "Coucou"};

	int i=0;
	int j;
	int k;
	while (i < 4)
	{
		j = 0;
		k = 0;
		while (j < 4)
		{
			while (k < 8)
			{
				if(ft_memcmp(str[i],str[j],k) != memcmp(str[i],str[j],k))
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
int		test_memcpy(void)
{
	char	*src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	dest[80];
	char	*ptr;
	char	*ptr2;
	char	*src2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	dest2[80];
	bzero(dest,80);
	bzero(dest2,80);
	ptr = (char *) memcpy(dest, src, 26);
	ptr2 = (char *) ft_memcpy(dest2, src2, 26);
	if (strcmp(ptr, ptr2) != 0)
		return (0);
	return (1);
}
int		test_memccpy(void)
{
	char *srce = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char dest[80];
	char *ptr;
	char *srce2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char dest2[80];
	char *ptr2;

	ptr = (char *) memccpy(dest, srce, 'I', strlen(srce));
	ptr2 = (char *) ft_memccpy(dest2, srce2, 'I', strlen(srce2));
	if (ptr && ptr2)
	{
		*ptr = '\0';
		*ptr2 = '\0';
	}
	if (strcmp(dest,dest2) != 0)
		return (0);
	return (1);
}

int		test_memchr(void)
{
	char ch[30];
	char *ptr;
	char ch2[30];
	char *ptr2;

	strcpy(ch, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	strcpy(ch2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ptr = (char *) memchr(ch, 'I', strlen(ch));
	ptr2 = (char *) ft_memchr(ch2, 'I', strlen(ch2));
	if (strcmp(ptr, ptr2) != 0)
		return (0);
	return 1;
}

int		test_memmove(void)
{
	char *dest = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char *str;
	char *str2;
	char *srce = "--------------------------";
	str = strdup(dest);
	str2 = strdup(dest);
	memmove(str, srce, 25);
	ft_memmove(str2, srce, 25);
	if (strcmp(str,str2) != 0)
		return (0);
	return (1);
}

int		test_tolower(void)
{
	int i;
	i = 0;
	while (i < 127)
	{
		if (tolower(i) != ft_tolower(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_toupper(void)
{
	int i;
	i = 0;
	while (i < 127)
	{
		if (toupper(i) != ft_toupper(i))
			return (0);
		i++;
	}
	return (1);
}
int main (void)
{
	printf("\nFONCTION DE LA PREMIERE PAGE\n\n");
	printf("test ft_memset\t= %d\n", test_memset());
	printf("test ft_bzero\t= %d\n", test_bzero());
	printf("test ft_memcpy\t= %d\n", test_memcpy());
	printf("test ft_memccpy\t= %d\n", test_memccpy());
	printf("test ft_memmove\t= %d\n", test_memmove());
	printf("test ft_memchr\t= %d\n", test_memchr());
	printf("test ft_memcmp\t= %d\n", test_memcmp());
	printf("        ---\n");
	printf("test ft_strlen\t= %d\n", test_strlen());
	printf("test ft_strdup\t= %d\n", test_strdup());
	printf("test ft_strcpy\t= %d\n", test_strcpy());
	printf("test ft_strncpy\t= %d\n", test_strncpy());
	printf("test ft_strcat\t= %d\n", test_strcat());
	printf("test ft_strncat\t= %d\n", test_strncat());
	printf("test ft_strlcat\t= %d\n", test_strlcat());
	printf("test ft_strchr\t= %d\n", test_strchr());
	printf("test ft_strrchr\t= %d\n", test_strrchr());
	printf("test ft_strstr\t= %d\n", test_strstr());
	printf("test ft_strnstr\t= %d\n", test_strnstr());
	printf("test ft_strcmp\t= %d\n", test_strcmp());
	printf("test ft_strncmp\t= %d\n", test_strncmp());
	printf("        ---\n");
	printf("test ft_atoi\t= %d\n", test_atoi());
	printf("test ft_isalpha\t= %d\n", test_isalpha());
	printf("test ft_isdigit\t= %d\n", test_isdigit());
	printf("test ft_isalnum\t= %d\n", test_isalnum());
	printf("test ft_isascii\t= %d\n", test_isascii());
	printf("test ft_isprint\t= %d\n", test_isprint());
	printf("test ft_toupper\t= %d\n", test_toupper());
	printf("test ft_tolower\t= %d\n", test_tolower());
	return (0);
}


