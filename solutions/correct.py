import math

def prepare_H_from_G(n1, n2, mG, u, v, size_of_H, add_edge, set_s, set_t):

    size_of_H(n1+n2+2, mG + n1 + n2)
    s = n1 + n2
    t =  n1 + n2 +1
    set_s(s)
    set_t(t)

    for i  in range(mG):
        add_edge(u[i],v[i],1)

    for i  in range(n1):
        add_edge(s,i,1)

    for i  in range(n1,n1+n2):
        add_edge(i,t,1)


def max_card_matching_and_min_node_cover_in_G(n1, n2, mG, u, v, put_in_matching, put_in_node_cover_on_side_U, put_in_node_cover_on_side_V, flow_val):

    is_unmatched = [True]*n1
    matching_v = [-1]*(n1+n2)
    neighbour_u = [[] for i in range(n1)]

    for i in range(mG):
        nu = u[i]
        nv = v[i]
        neighbour_u[nu].append(nv)
        if flow_val(nu,nv) == 1:
            is_unmatched[nu] = False
            put_in_matching(nu,nv)
            matching_v[nv] = nu

    in_cover_u = [True]*n1
    not_visit = [True]*(n1+n2)
    to_be_processed_in_U = []

    for i in range(n1):
        if is_unmatched[i]:
            in_cover_u[i] = False
            not_visit[i] = False
            to_be_processed_in_U.append(i)

    while len(to_be_processed_in_U) > 0:
        to_be_processed_in_V = []
        for nu in to_be_processed_in_U:
            for nv in neighbour_u[nu]:
                if not_visit[nv] and flow_val(nu,nv) == 0:
                    not_visit[nv] = False
                    put_in_node_cover_on_side_V(nv)
                    to_be_processed_in_V.append(nv)
        # for nu in to_be_processed_in_U:
        #     for i in range(mG):
        #         if u[i] != nu:
        #             continue
        #         nv = v[i]
        #         if not_visit[nv] and flow_val(nu,nv) == 0:
        #             not_visit[nv] = False
        #             put_in_node_cover_on_side_V(nv)
        #             to_be_processed_in_V.append(nv)

        to_be_processed_in_U = []
        for nv in to_be_processed_in_V:
            nu = matching_v[nv]
            if not_visit[nu] and flow_val(nu,nv) == 1:
                in_cover_u[nu] = False
                not_visit[nu] = False
                to_be_processed_in_U.append(nu)

    for i in range(n1):
        if in_cover_u[i]:
            put_in_node_cover_on_side_U(i)



def min_node_cover_from_min_cut(n1, n2, put_in_node_cover_on_side_U, put_in_node_cover_on_side_V, min_cut_value, next_in_min_cut_left, next_in_min_cut_right):

    s = n1 + n2
    t =  n1 + n2 +1

    for i in range(min_cut_value()):
        l = next_in_min_cut_left()
        r = next_in_min_cut_right()

        if l == s:
            put_in_node_cover_on_side_U(r)
        elif r == t:
            put_in_node_cover_on_side_V(l)
