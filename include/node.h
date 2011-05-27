/*
 * node.h
 *
 *  Created on: Mar 7, 2011
 *      Author: posixninja
 */

#ifndef NODE_H_
#define NODE_H_

#include "object.h"

#define NODE_TYPE 1;

struct node_list_t;

// This class implements the abstract iterator class
typedef struct node_t {
	// Super class
	struct node_t* next;
	struct node_t* prev;
	unsigned int count;

	// Local Properties
	int isRoot;
	int isLeaf;

	// Local Members
	void *data;
	unsigned int depth;
	struct node_t* parent;
	struct node_list_t* children;

	// Virtual Functions
	int(*attach)(struct node_t* parent, struct node_t* child);
	int(*detach)(struct node_t* parent, struct node_t* child);

} node_t;

void node_destroy(struct node_t* node);
struct node_t* node_create(struct node_t* parent, void* data);

int node_attach(struct node_t* parent, struct node_t* child);
int node_detach(struct node_t* parent, struct node_t* child);
int node_insert(struct node_t* parent, unsigned int index, struct node_t* child);

unsigned int node_n_children(struct node_t* node);
node_t* node_nth_child(struct node_t* node, unsigned int n);
node_t* node_first_child(struct node_t* node);
node_t* node_prev_sibling(struct node_t* node);
node_t* node_next_sibling(struct node_t* node);
int node_child_position(struct node_t* parent, node_t* child);


void node_debug(struct node_t* node);

#endif /* NODE_H_ */
