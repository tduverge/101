/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:40:14 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:04:56 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 546

typedef enum		e_shape
{
	e_shape_O = 0b110011,
	e_shape_I1 = 0b1111,
	e_shape_I2 = 0b1000100010001,
	e_shape_S1 = 0b11011,
	e_shape_S2 = 0b1000110001,
	e_shape_Z1 = 0b1100011,
	e_shape_Z2 = 0b10011001,
	e_shape_L1 = 0b10111,
	e_shape_L2 = 0b1100010001,
	e_shape_L3 = 0b11101,
	e_shape_L4 = 0b1000100011,
	e_shape_J1 = 0b1000111,
	e_shape_J2 = 0b100010011,
	e_shape_J3 = 0b1110001,
	e_shape_J4 = 0b110010001,
	e_shape_T1 = 0b100111,
	e_shape_T2 = 0b100110001,
	e_shape_T3 = 0b111001,
	e_shape_T4 = 0b100011001,
}					t_eshape;

typedef struct		s_tet
{
	t_eshape	shape;
	char		letter;
	int			x;
	int			y;
	int			size;
}					t_tet;

char				*recup_strfile(char *name_file);
int					verif_file(char *s);
int					count_tet(char *s);
void				ft_putusage(void);
t_tet				*ft_filltab(char *s);
int					ft_check_shape(t_tet *tab);
void				ft_resolve(t_tet *tab, int size, int *sol, int init_lentab);
void				ft_write2d(char **grid);
int					ft_next_sqrt(int n);
int					test(int index[2], int *sol, t_eshape shape, int size);
int					test_i1(int x, int y, int *sol, int size);
int					test_i2(int x, int y, int *sol, int size);
int					test_j1(int x, int y, int *sol, int size);
int					test_j2(int x, int y, int *sol, int size);
int					test_j3(int x, int y, int *sol, int size);
int					test_j4(int x, int y, int *sol, int size);
int					test_l1(int x, int y, int *sol, int size);
int					test_l2(int x, int y, int *sol, int size);
int					test_l3(int x, int y, int *sol, int size);
int					test_l4(int x, int y, int *sol, int size);
int					test_o(int x, int y, int *sol, int size);
int					test_s1(int x, int y, int *sol, int size);
int					test_s2(int x, int y, int *sol, int size);
int					test_t1(int x, int y, int *sol, int size);
int					test_t2(int x, int y, int *sol, int size);
int					test_t3(int x, int y, int *sol, int size);
int					test_t4(int x, int y, int *sol, int size);
int					test_z1(int x, int y, int *sol, int size);
int					test_z2(int x, int y, int *sol, int size);
void				print_i1(char **board, t_tet *tet);
void				print_i2(char **board, t_tet *tet);
void				print_j1(char **board, t_tet *tet);
void				print_j2(char **board, t_tet *tet);
void				print_j3(char **board, t_tet *tet);
void				print_j4(char **board, t_tet *tet);
void				print_l1(char **board, t_tet *tet);
void				print_l2(char **board, t_tet *tet);
void				print_l3(char **board, t_tet *tet);
void				print_l4(char **board, t_tet *tet);
void				print_o(char **board, t_tet *tet);
void				print_s1(char **board, t_tet *tet);
void				print_s2(char **board, t_tet *tet);
void				print_z1(char **board, t_tet *tet);
void				print_z2(char **board, t_tet *tet);
void				print_t1(char **board, t_tet *tet);
void				print_t2(char **board, t_tet *tet);
void				print_t3(char **board, t_tet *tet);
void				print_t4(char **board, t_tet *tet);
char				**print_soluce(t_tet *tets);
void				fill_board(char **board);
void				ft_delete(int index[2], int *sol, t_eshape shape);
void				delete_i1(int x, int y, int *sol);
void				delete_i2(int x, int y, int *sol);
void				delete_j1(int x, int y, int *sol);
void				delete_j2(int x, int y, int *sol);
void				delete_j3(int x, int y, int *sol);
void				delete_j4(int x, int y, int *sol);
void				delete_l1(int x, int y, int *sol);
void				delete_l2(int x, int y, int *sol);
void				delete_l3(int x, int y, int *sol);
void				delete_l4(int x, int y, int *sol);
void				delete_o(int x, int y, int *sol);
void				delete_s1(int x, int y, int *sol);
void				delete_s2(int x, int y, int *sol);
void				delete_t1(int x, int y, int *sol);
void				delete_t2(int x, int y, int *sol);
void				delete_t3(int x, int y, int *sol);
void				delete_t4(int x, int y, int *sol);
void				delete_z1(int x, int y, int *sol);
void				delete_z2(int x, int y, int *sol);

#endif
