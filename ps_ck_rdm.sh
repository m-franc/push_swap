ARG="$(ruby -e "puts ($1..$2).to_a.shuffle.join(' ')")" ; make && ./srcs/srcs_ps/push_swap $ARG | ./srcs/srcs_ck/checker $ARG
