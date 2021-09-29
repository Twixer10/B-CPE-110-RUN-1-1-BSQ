/*
** EPITECH PROJECT, 2020
** MY ATOI
** File description:
** NO DESCRIPTION FOUND
*/

int	my_atoi(char *str)
{
    int res = 0;
    int sign = 0;
    int i = 0;

    ((str[i] == '-') ? (sign = 1, i++) : (0));
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
	        res *= 10;
	        res += str[i] - '0';
	    } else
	        return (res);
        i++;
    }
    if (sign == 0)
        return (res);
    else
        return (-res);
}