/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:21:07 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 09:28:35 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *s);
int is_prime(int n);
void put_numb(int n);

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
	  int num = ft_atoi(argv[1]);
	  int sum = 0;

	  while (num >= 0)
	  {
	    if (is_prime(num) == 1)
	      sum += num;
	    num--;
	  }
	  put_numb(sum);
	  write(1, "\n",1);
	}
	if (argc != 2)
		write(1, "0\n", 2);
	return (0);
}

int ft_atoi(char *s)
{
  int res;

  res = 0;
  while (*s)
  {
    res = res *10 + *s -'0';
    s++;
  }
  return (res);
}

int is_prime(int n)
{
  int i = 2;

  if (n <= 1)
    return (1);
  while (i * i <= n)
  {
    if ((n % i) == 0)
      return (0);
  }
  return (1);
}

void put_numb(int n)
{
	if (n >= 10)
		put_numb(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}
