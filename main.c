#include "fractol.h"

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 800, "Fractol - Test");
    mlx_loop(mlx);
}