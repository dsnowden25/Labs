#include "adj_converter.h"

AdjMatrix * convert_list_to_matrix(AdjList * list) {
    AdjMatrix * matrix = blank_matrix(list->size); // Create a blank adjacency matrix with the same size as the adjacency list
    
    // For each vertex in the adjacency list,
    // we will iterate through its edges and populate the corresponding cells in the adjacency matrix with the edge weights.
    for (int i = 0; i < list->size; i++) {
        edge_t *edge = list->adj_lists[i];
        while (edge != NULL) {
            matrix->data[i][edge->vertex] = edge->weight;
            edge = edge->next;
        }
    }

    // Return the populated adjacency matrix
    return matrix;
}



AdjList * convert_matrix_to_list(AdjMatrix * matrix) {
    AdjList * list = create_graph(matrix->size); // Create an empty adjacency list with the same size as the matrix
    
    // For each cell in the adjacency matrix that has a non-zero value,
    // indicating an edge exists between the vertices,
    // we will create an edge in the adjacency list.
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            if (matrix->data[i][j] > 0) {
                add_edge(list, i, j, matrix->data[i][j]);
            }
        }
    }

    // Return the populated adjacency list
    return list;
}

