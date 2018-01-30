#include <bits/stdc++.h>

using namespace std;

#include "../src/union-find-tree.h"

int main(void) {
	UnionFindTree tree(5);
	tree.unite(0, 2);
	tree.unite(3, 2);
	tree.unite(3, 4);
	assert(tree.same(0, 4));
	assert(!tree.same(2, 1));
	return 0;
}

