
de	*a;
t_node	*b;
t_move	move;
int		hit;
int		hit_a;
int		hit_b;

hit = INT_MAX;
hit_a = 0;
hit_b = 0;
move.pad_a = 0;
move.pad_b = 0;
move.ra = 0;
move.rb = 0;
a = FIRST(a_ctl);
while (a)
{
	move.ra = DST_TOP(a) >= DST_BOTTOM(a) ? 1 : 0;
	hit_a = DST_TOP(a) >= DST_BOTTOM(a) ? DST_BOTTOM(a) : DST_TOP(a);
	b = FIRST(b_ctl);
	while (b && NEXT(b) && INDEX(a) > INDEX(b))
		b = NEXT(b);
	move.rb = DST_TOP(b) >= DST_BOTTOM(b) ? 1 : 0;
	hit_b = DST_TOP(b) >= DST_BOTTOM(b) ? DST_BOTTOM(b) : DST_TOP(b);
	if (((hit_a + hit_b) < hit))
	{
		move.pad_a = hit_a;
		move.pad_b = hit_b;
		hit = move.pad_a + move.pad_b;
		//		ft_printf("Coup dans A : {red}%d{eoc} - Coup dans B : {cyan}%d{eoc}\n", move.pad_a, move.pad_b);
		//				}
		//						a = NEXT(a);
		//							}
		//								return (move);
		//								}
		//								*/))"}}}}")})))))))))))))))))))))}))
		//
		//
		//								/*	ft_split_stack(a_ctl, b_ctl);
		//									ft_split_stack(a_ctl, b_ctl);
		//										ft_split_stack(a_ctl, b_ctl);
		//											ft_split_stack(a_ctl, b_ctl);
		//												ft_split_stack(a_ctl, b_ctl);*/
		//
		//												/*	while (SIZE(a_ctl) != 0)
		//													{
		//															move = ft_get_best_hit(a_ctl, b_ctl);
		//															//		sleep(1);
		//																	if (move.ra == 0)
		//																			{
		//																						if (move.rb == 1)
		//																										while (move.pad_b-- > 0)
		//																															ft_rb(&b_ctl, 1);
		//																																		else
		//																																						while (move.pad_b-- > 0)
		//																																											ft_rrb(&b_ctl, 1);
		//																																														while (move.pad_a-- > 0)
		//																																																		ft_rra(&a_ctl, 1);
		//																																																					ft_pb(&a_ctl, &b_ctl, 1);
		//																																																							}
		//																																																									else
		//																																																											{
		//																																																														if (move.rb == 1)
		//																																																																		while (move.pad_b-- > 0)
		//																																																																							ft_rb(&b_ctl, 1);
		//																																																																										else
		//																																																																														while (move.pad_b-- > 0)
		//																																																																																			ft_rrb(&b_ctl, 1);
		//																																																																																						while (move.pad_a-- > 0)
		//																																																																																										ft_ra(&a_ctl, 1);
		//																																																																																													ft_pb(&a_ctl, &b_ctl, 1);
		//																																																																																															}
		//																																																																																																//	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
		//																																																																																																	}
		//																																																																																																		while (INDEX(FIRST(b_ctl)) != ((int)SIZE(b_ctl) - 1))
		//																																																																																																				ft_rb(&b_ctl, 1);
		//																																																																																																					while (SIZE(b_ctl) != 0)
		//																																																																																																							ft_pa(&b_ctl, &a_ctl, 1);*/
		//																																																																																																							//	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
		//																																																																																																								return (1);
		//																																																																																																								})))))))))))))))))))))))))}))))))))})))})))))))
