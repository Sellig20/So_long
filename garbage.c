int	handle_no_event(void *x)
{
	(void)x;
	//
	return (0);
}

int	handle_input(int keysym, t_data *x)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(x->mlx_ptr, x->win_ptr);
	return (0);
}

int	handle_keyrelease(int keysym, void *x)
{
	(void)x;
	printf("Keyrelease : %d\n", keysym);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
