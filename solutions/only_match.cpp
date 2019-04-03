#include <vector>
#include <algorithm>
#include <set>


void prepare_H_from_G(
        int n1, int n2, int mG, int *u, int *v,
        void size_of_H(int nH, int mH),
        void add_edge(int u, int v, int w),
        void set_s(int s),
        void set_t(int t)) {
    // the nodes has n1 + n2 edges (the first 0..n1-1 is U, n1..n2-1 is V
    // plus 2 extra nodes from s and t
    int total_nodes_H = 2 + n1 + n2;

    // H has all the original edges from U + V plus an edges from s to all the
    // nodes of U and an edges from all the nodes of V to t
    int total_edges_H = mG + n1 + n2;

    size_of_H(total_nodes_H, total_edges_H);

    // s and t are the last nodes
    int s = n1+n2;
    int t = n1+n2+1;
    set_s(s);
    set_t(t);

    // original edges
    for (int i = 0; i < mG; i++)
        add_edge(u[i], v[i], 1);
    // out edges from s
    for (int i = 0; i < n1; i++)
        add_edge(s, i, 1);
    // in edges to t
    for (int i = n1; i < n1 + n2; i++)
        add_edge(i, t, 1);
}

void max_card_matching_and_min_node_cover_in_G(
        int n1, int n2, int mG, int *u, int *v,
        void put_in_matching(int u, int v),
        void put_in_node_cover_on_side_U(int u),
        void put_in_node_cover_on_side_V(int v),
        int flow_val(int u, int v)) {

    // find unmatched nodes in U
    std::vector<bool> is_unmatched(n1,true);

    for (int i = 0; i < mG; i++) {
        int nu = u[i], nv = v[i];
        if (flow_val(nu,nv) == 1) {
            is_unmatched[nu] = false;
            put_in_matching(nu, nv);
        }
    }

    // // node in U and K
    // std::vector<int> to_analyze_in_U;
    // std::vector<int> to_analyze_in_V;
    //
    // std::vector<bool> add_in_cover(n1,true);
    // std::vector<bool> visited_in_cover_construction(n1+n2,false);
    //
    // for (int i = 0; i < n1; i++) {
    //     if (is_unmatched[i]) {
    //         add_in_cover[i] = false;
    //         to_analyze_in_U.push_back(i);
    //         visited_in_cover_construction[i] = true;
    //     }
    // }
    //
    // while (true) {
    //     // find nodes in V connected by an edges with flow 0
    //     while (!to_analyze_in_U.empty()) {
    //         int n = to_analyze_in_U.back(); to_analyze_in_U.pop_back();
    //         for (int it = 0; it != mG; ++it) {
    //             // find the node n
    //             if ( u[it] != n ) continue;
    //
    //             // collect all nodes connected, and and them to the cover
    //             while ( u[it] == n && it < mG ) {
    //
    //                 if ( visited_in_cover_construction[v[it]] == false &&
    //                         flow_val(u[it], v[it]) == 0) {
    //
    //                     visited_in_cover_construction[v[it]] = true;
    //                     put_in_node_cover_on_side_V(v[it]);
    //                     to_analyze_in_V.push_back(v[it]);
    //                 }
    //                 ++it;
    //             }
    //             // all nodes from n visited
    //             break;
    //         }
    //     }
    //
    //     // find the edges in U connected to the edges with flow 1
    //     while (!to_analyze_in_V.empty()) {
    //         int n = to_analyze_in_V.back(); to_analyze_in_V.pop_back();
    //         for (int it = 0; it != mG; ++it) {
    //             // find nodes n
    //             if ( v[it] != n ) continue;
    //
    //             if ( visited_in_cover_construction[u[it]] == false
    //                     && flow_val(u[it], v[it]) == 1) {
    //
    //                 visited_in_cover_construction[u[it]] = true;
    //                 add_in_cover[u[it]] = false;
    //                 to_analyze_in_U.push_back(u[it]);
    //
    //                 // only a single one has flow = 1
    //                 break;
    //             }
    //         }
    //     }
    //
    //     // finished?
    //     if (to_analyze_in_U.empty())
    //         break;
    // }
    //
    // for (int it = 0; it != n1; ++it) {
    //     if (add_in_cover[it])
    //         put_in_node_cover_on_side_U(it);
    // }
}

void min_node_cover_from_min_cut(
        int n1, int n2,
        void put_in_node_cover_on_side_U(int u),
        void put_in_node_cover_on_side_V(int v),
        int min_cut_value(),
        int next_in_min_cut_left(),
        int next_in_min_cut_right()) {

    int s = n1+n2;
    int t = n1+n2+1;

    for (int i = 0; i < min_cut_value(); i++) {
        int l = next_in_min_cut_left();
        int r = next_in_min_cut_right();

        if ( l == s )
            put_in_node_cover_on_side_U(r);
        else if ( r == t )
            put_in_node_cover_on_side_V(l);
    }
}
