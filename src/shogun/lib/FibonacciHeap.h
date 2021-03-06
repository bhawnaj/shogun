/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Evgeniy Andreev (gsomix)
 *
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <shogun/base/SGObject.h>
#include <shogun/lib/common.h>
#include <shogun/mathematics/Math.h>

namespace shogun
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct FibonacciHeapNode
{
	/** pointer to parent node */
	FibonacciHeapNode* parent;

	/** pointer to child node */
	FibonacciHeapNode* child;

	/** pointer to left sibling */
	FibonacciHeapNode* left;

	/** pointer to right sibling */
	FibonacciHeapNode* right;

	/** rank of node */
	int32_t rank;

	/** marked flag */
	bool marked;

	/** index in heap */
	int32_t index;

	/** key of node */
	float64_t key;
};

/** @brief the class FibonacciHeap, a fibonacci
 * heap. Generally used by Isomap for Dijkstra heap
 * algorithm
 *
 * w: http://en.wikipedia.org/wiki/Fibonacci_heap
 */
class CFibonacciHeap: public CSGObject
{
public:

	CFibonacciHeap();

	/** Constructor for heap with specified capacity */
	CFibonacciHeap(int32_t capacity);

	virtual const char* get_name() const
	{
		return "FibonacciHeap";
	}

	virtual ~CFibonacciHeap();


	int32_t get_num_nodes() const
	{
		return num_nodes;
	}

	int32_t get_num_trees()
	{
		return num_trees;
	}

	int32_t get_capacity()
	{
		return max_num_nodes;
	}

	/** Inserts nodes with certain key in array of nodes with index
	 * Have time of O(1)
	 */
	void insert(int32_t index, float64_t key);

	/** Deletes and returns item with minimal key
	 * Have amortized time of O(log n)
	 * @return item with minimal key
	 */
	int32_t extract_min(float64_t &ret_key);

	/** Clears all nodes in heap */
	void clear();

	/** Returns key by index
	 * @return -1 if not valid
	 */
	int32_t get_key(int32_t index, float64_t &ret_key);

	/** Decreases key by index
	 * Have amortized time of O(1)
	 */
	void decrease_key(int32_t index, float64_t key);

	void debug_print();

private:
	/** Adds node to roots list */
	void add_to_roots(FibonacciHeapNode *up_node);

	/** Consolidates heap */
	void consolidate();

	/** Links right node to childs of left node */
	void link_nodes(FibonacciHeapNode *right, FibonacciHeapNode *left);

	/** Clears node by index */
	void clear_node(int32_t index);

	/** Cuts child node from childs list of parent */
	void cut(FibonacciHeapNode *child, FibonacciHeapNode *parent);

	void cascading_cut(FibonacciHeapNode* tree);

protected:
	/** minimal root in heap */
	FibonacciHeapNode* min_root;

	/** array of nodes for fast search by index */
	FibonacciHeapNode** nodes;

	/** number of nodes */
	int32_t num_nodes;

	/** number of trees */
	int32_t num_trees;

	/** maximum number of nodes */
	int32_t max_num_nodes;

	/** supporting array */
	FibonacciHeapNode **A;

	/** size of supporting array */
	int32_t Dn;
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

}
#endif /* FIBONACCI_H_ */
