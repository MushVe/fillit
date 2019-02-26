#include "fillit.h"

void	swap_x_y(int ***coord)
{
	int	temp;
	int	i_t;
	int	i_b;

	i_t = -1;
	while (coord[++i_t] != 0)
	{
		i_b = -1;
		while (++i_b < 4)
		{
			temp = coord[i_t][i_b][0];
			coord[i_t][i_b][0] = coord[i_t][i_b][1];
			coord[i_t][i_b][1] = temp;
		}
	}
}

/*
cette fonction transpose les tetriminos si les pieces sont toutes + allongees
de maniere horizontale que de maniere verticale
on transpose en faisant un swap de x et y
*/
int	is_big_x(int ***coord)
{
	int	i_tetri;
	int	max_y;
	int	ret_max;

	max_y = 0;
	i_tetri = -1;
	while (coord[++i_tetri] != 0)
	{
		if ((ret_max = max(coord[i_tetri], 1)) > max_y)
			max_y = ret_max;
		if (max_y > 1)
			return (0);
	}
	swap_x_y(coord);
	return (1);
}
