Nel calcolare un matching di massima cardinalità ed un minimo node cover in un grafo bipartito assegnato G=(U,V;E), è di grande aiuto avvalersi di un oracolo che, assegnatole un grafo orientato H con pesi sugli archi e con due nodi speciali s e t, restituisce un massimo flusso da s a t in H ed un s,t-taglio minimo nel grafo H. (Tale taglio sarà dello stesso valore del flusso, per il max-flow min-cut theorem.)
Dopo un'opportuna chiamata ad un tale oracolo entrambi gli oggettipotranno essere calcolati in O(|U|+|V|) invece che in O(|E| \sqrt{|U|+|V|}).
Inoltre, la produzione di H partendo da G costa solamente O(|U|+|V|+|E|).
In realtà, se sei disposto a pagare O(|U|+|V|+|E|) per il calcolo del node cover, allora non ti è nemmeno necessario farti rivelare il minimo taglio.

Goal 1: calcolare un massimo matching di G in O(|U|+|V|+|E|).

Goal 2: successivamente all'instanziazione di H, calcolare un minimo node cover di G senza avvalersi del secondo oracolo, in O(|U|+|V|+|E|).

Goal 3: successivamente all'instanziazione di H, calcolare un minimo node cover di G in O(|U|+|V|). (Questo dovrebbe consentirti di vedere il teorema di Konig come un corollario del max-flow min-cut theorem).
