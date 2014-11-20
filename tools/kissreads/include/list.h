/**
 * Copyright INRIA , contributors Peterlongo
 * pierre.peterlongo@inria.fr
 *
 *
 * This software is a computer program whose purpose is to detect the
 * presence of a sequence in a set of NGS reads, and to compute its average quality and coverage
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 */

/*
 * list.h
 *
 *  Created on: 16 sept. 2010
 *      Author: ppeterlo
 */

#ifndef LIST_H_
#define LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<couple.h>
#include<commons.h>
#include <string.h>


typedef struct CELL {
   void * val;
   struct CELL *prox;
} cell, * p_cell;

typedef struct {
	int size;
	p_cell first;
} list;

list *list_create(void);
void list_add(list *l, void* val);



void list_free(const void *list, void (*specific_free)(void *));
void list_of_generic_free(const void *v_list);
void list_of_generic_empty(const void * v_list);


int numberInList (list *l);

/////////////////////////////////////////////////////////////////////////////////
///////// For speed purpose, here is a list dedicated to int only ///////////////
/////////////////////////////////////////////////////////////////////////////////

typedef struct CELLINT {
    int val;
    struct CELLINT *prox;
} cellint, * p_cellint;

typedef struct {
	int size;
	p_cellint first;
} listint;

listint *listint_create(void);
void listint_add(listint *l, int val);


char listint_contains(listint *l, int val);

void listint_free(const void *v_list);
void listint_empty(const void * v_list);


int numberInListint (listint *l);


#endif /* LIST_H_ */