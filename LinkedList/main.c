#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

#include "linkedlist.h"

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Build a list with the above data, use add_back.
    /*
    void add_back(NeuList *list, int wins, int year) {
    Pair *newNode = new_node(wins, year, NULL);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Pair *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list->size++;
    }
    */

    // Step 1: Create a list
    NeuList *list = create_list();

    // Step 2: Add the data to the list using add_back
    for (size_t i = 0; i < 4; i++) {
        add_back(list, test_wins[i], test_years[i]);
    }
    
    
    // print the list out to make sure it's correct using your print list function you wrote in linkedlist.h

    printf("List contents:\n");
    print_list(list);

    return 0;
}