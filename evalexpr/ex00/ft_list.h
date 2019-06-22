typedef struct		s_list
{
	struct s_list	*next;
	char			*str;
	int				value;
}					t_list;

t_list				*ft_create_elem(char *data);

void print_ll(t_list *ll);
void	ft_list_push_back(t_list **begin_list, char *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_delete_next(t_list *node);
