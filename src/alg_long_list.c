
#include

void	ft_sort_long_list(t_param *p, int pos, int tmp)
{
	t_stack	*node;
	int	*t;

	node = p->a_head;
	while (node)
	{
		if (ft_islowest_expt(p->a_head, node->data, t))
				{
				t* = node->data;
				t++;
				}
		node = node->next;
	}
}
