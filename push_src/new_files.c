#include "../push_swap.h"

int        **init_bucket(int size)
{
    int **bucket;
    int i;

    i = 0;
    bucket = NULL;
    bucket = (int**)malloc(sizeof(int*) * size);
    while (size != 0)
    {
        bucket[i] = malloc(sizeof(int) * 5);
        i++;
        size--;
    }
    return (bucket);
}

int        **get_buckets(int *num_arr, int size, int bucket_count)
{
    int **buckets;
    int count;
    int i;
    int j;
    int k;

    k = 0;
    j = 0;
    i = 0;
    buckets = init_bucket(size);
    count = bucket_count;
    while (count != 0 && k < size)
    {
        if (j == 5)
        {
            i++;
            count--;
            j = 0;
        }
        buckets[i][j] = num_arr[k];
        j++;
        k++;
    }
    return (buckets);
}

int        **set_buckets(int *num_arr, int size)
{
    int bucket_count;
    int **buckets;

    buckets = NULL;
    bucket_count = 0;
    bucket_count +=  SIZE(size);
    buckets = get_buckets(num_arr, size, bucket_count);
    return (buckets);
}

int         find_bucket(int value, int **buckets, struct s_stack **a)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (k < (*a)->capacity)
    {
        while (j < 5 && k < (*a)->capacity)
        {
            if (buckets[i][j] == value)
                return i;
            j++;
            k++;
        }
        i++;
        j = 0;
    }
    return i;
}

void        zero_out(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        arr[i] = 0;
        i++;
    }
}



void        get_occurance(int **occupied, int **buckets, struct s_stack **a, int side)
{
    int count;
    int i;
    struct s_node *tmp;

    i = 0;
    tmp = (*a)->stack;
    count = 5;
    if (side == 0)
        while (--count >= 0)
        {
            i = find_bucket(tmp->value, buckets, a);
            tmp = tmp->next;
            *(*occupied + i) += 1;
        }
    else
    {
        to_end(&tmp);
        while (--count >= 0)
        {
            i = find_bucket(tmp->value, buckets, a);
            tmp = tmp->prev;
            *(*occupied + i) += 1;
        }
    }
}

int         highest_occurance(int *occupied, int depth)
{
    //Find first bucket with highest occuring number count. If buckets contain same count,
    //the first high of the pair, will always be the first to be sorted
    int big;
    int i;

    i = 0;
    big = 0;
    while (i < depth)
    {
        
        if (occupied[i] > occupied[big])
            big = i;
        i++;
    }
    return (big);
}

int         first_occurance(int bucket, int **buckets, struct s_stack **a, int side)
{
    //Find first number occurance in particular bucket
    int             count;
    struct s_node   *tmp;

    tmp = (*a)->stack;
    count = 0;
    if (side == 0)
    {
        while (count < 5)
        {
            if (bucket == find_bucket(tmp->value, buckets, a))
                return (tmp->value);
            tmp = tmp->next;
            count++;
        }
    }
    else
    {
        to_end(&tmp);
        while (count < 5)
        {
            if (bucket == find_bucket(tmp->value, buckets, a))
                return (tmp->value);
            tmp = tmp->prev;
            count++;
        }
    }
    return (tmp->value);
}

int         find_pull_side(int bucket, int **buckets, struct s_stack **a, int left, int right)
{
    int count;
    struct s_node *tmp;

    count = 0;
    tmp = (*a)->stack;
    while (count < 5)
    {
        if (bucket == find_bucket(tmp->value, buckets, a))
            left++;
        count++;
        tmp = tmp->next;
    }
    count = 0;
    to_end(&tmp);
    while (count < 5)
    {
        if (bucket == find_bucket(tmp->value, buckets, a))
            right++;
        tmp = tmp->prev;
        count++;
    }
    return (left >= right ? 0 : 1);
}

/*struct s_node   *find_immediate(struct s_stack **b, int *num_arr)
{
    if ()
}

int         close_to_b(struct s_stack **b, int *num_arr, int **buckets, int *occupied)
{
    //Find closest to the first (up to 5) and the last (up to 5) in B.
    //Closest is when the number value is either directly
    //before or after value (within the 10 possible), or if
    //the value is in a bucket that is directly after or before
    //one of the 10 values corresponding bucket.
    //Highest priority is given to direct number value, versus direct bucket value
    int i;
    struct s_node *tmp;

    i = 0;
    tmp = NULL;
    if ((*b)->capacity < 10)
    {
        //Do not search bucket relation, just search stack entirely
        //for next/previous possible value
        tmp = find_immediate(b, num_arr);
        ft_printf("TMP->VALUE: %i\n", tmp->value);
        return (1);
    }
    else
    {
        tmp = find_immediate(b, num_arr);
        ft_printf("TMP->VALUE: %i\n", tmp->value);
        int i = 0;
        int test = SIZE((*b)->capacity);
        while (test > 0)
        {
            ft_printf("2OCCUPIED%i: %i\n", i, *(occupied + i));
            i++;
            test--;
        }
    }
    print_stack(a);
    print_stack(b);
    return (1);
}*/

int         find_good_grab(struct s_stack **a, int *num_arr)
{
    int     **buckets;
    int     *occupied;
    int     bucket_;

    bucket_ = 0;
    occupied = malloc(sizeof(int) * SIZE((*a)->capacity));
    buckets = NULL;
    buckets = set_buckets(num_arr, (*a)->capacity);
    zero_out(occupied, SIZE((*a)->capacity));
    if ((*a)->capacity > 9 /*&& not_sorted(a) > 9*/)
    {
        get_occurance(&occupied, buckets, a, 0);
        get_occurance(&occupied, buckets, a, 1);
    }
    bucket_ = highest_occurance(occupied, SIZE((*a)->capacity));

    //Prints the pull side, as well as the first number from the highest bucket, on the pull side
    ft_printf("BEST SIDE TO PULL FROM: %i\n", find_pull_side(bucket_, buckets, a, 0, 0));
    ft_printf("FIRST NUMBER OCCURED IN HIGHEST BUCKET ON BEST SIDE: %i\n",first_occurance(bucket_, buckets, a, find_pull_side(bucket_, buckets, a, 0, 0)));

    //Prints occupied array values
    int i = 0;
    int test = SIZE((*a)->capacity);
    while (test > 0)
    {
        ft_printf("OCCUPIED%i: %i\n", i, *(occupied + i));
        i++;
        test--;
    }

   /* pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pb(a, b);*/
    return (first_occurance(bucket_, buckets, a, find_pull_side(bucket_, buckets, a, 0, 0)));
}

void        pull_side(int num, struct s_stack **a)
{
    int side;

    side = find_side(a, num);
    ft_printf("SIDE: %i\n" , side);
    while ((*a)->stack->value != num)
    {
        if (side == 0)
            ra(a);
        else
            rra(a);
    }
}
int		find_small(struct s_stack **b)
{
	int				small;
	struct s_node	*tmp;

	tmp = (*b)->stack;
	small = 0;
	if ((*b)->stack != NULL)
	{
		small = (*b)->stack->value;
		if (tmp->next == NULL)
			return (small);
		while (tmp)
		{
			if (tmp->value < small)
				small = tmp->value;
			tmp = tmp->next;
		}
	}
	return (small);
}

void        move_around(struct s_stack **a, struct s_stack **b, int side, int moves)
{
    if (side == 1)
    {ft_printf("BEFORE: \n");
        print_stack_backwards(b);
        ft_printf("\n");
        rrb(a, b);
        ft_printf("AFTER:\n");
        print_stack_backwards(b);
        ft_printf("\n");
    }
    ft_printf("\n");
        print_stack_backwards(b);
        ft_printf("\n");
    while (moves > 0)
    {
        if (side == 0)
            rb(a, b);
        else
            rrb(a, b);
        moves--;
    }
    pb(a, b);
}

void        check_moves(struct s_stack **a, struct s_stack **b, int incoming, int side)
{
    int             moves;
    struct s_node   *tmp;

    tmp = (*b)->stack;
    moves = 0;
    if (side == 1)
        to_end(&tmp);
    print_stack(b);
    print_stack_backwards(b);
    while (tmp || moves < 5)
    {
        if (tmp->value == incoming)
            break ;
        ft_printf("tmp->PREV: %p\n", tmp->prev);
        if (side == 0)
            tmp = tmp->next;
        else
            tmp = tmp->prev;
        moves++;
    }
    ft_printf("MOVES: %i\n", moves);
    if (moves < 5)
        move_around(a, b, side, moves);
    else
        ra(a);
}

void        handle_move(struct s_stack **a, struct s_stack **b)
{
    int             ideal;

    ideal = 0;
    if ((*b)->capacity == 0 || (*b)->capacity == 1)
        pb(a,b);
    else
    {
        ideal = find_spot(b, (*a)->stack->value);
        ft_printf("IDEAL: %i\n", ideal);
        check_moves(a, b, ideal, find_side(b, ideal));
    //Once spot is known, you want to count moves to get to nearest number. Go with
    //lowest calculation. If moves are more than 5 for each side to get to number
    //throw (*a)->stack to the end of the stack and grab the nearest number again
    //via the bucket system.
    }
}