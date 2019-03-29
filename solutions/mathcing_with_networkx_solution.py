import networkx as nx
from networkx.algorithms import bipartite

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

    for i  in range(n2):
        add_edge(i,t,1)
    pass

def max_card_matching_and_min_node_cover_in_G(n1, n2, mG, u, v, put_in_matching, put_in_node_cover_on_side_U, put_in_node_cover_on_side_V, flow_val):


    H = nx.Graph()
    H.add_node(range(n1+n2+2))

    s = n1 + n2
    t =  n1 + n2 +1
    set_s(s)
    set_t(t)

    for i  in range(mG):
        H.add_edge(u[i],v[i])

    match = nx.max_weight_matching(H,maxcardinality=True)

    for nu,nv in match:
        put_in_matching(nu,nv)
                    
    pass

def min_node_cover_from_min_cut(n1, n2, put_in_node_cover_on_side_U, put_in_node_cover_on_side_V, min_cut_value, next_in_min_cut_left, next_in_min_cut_right):
    # TODO
    pass
