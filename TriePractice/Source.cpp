#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Trie.h"
int main(void)
{
	char key[][8] = { "the","a","there", "answer","any","by",
		 "bye","their" };
	int N = sizeof(key) / sizeof(key[0]);
	Trienode* root=GetTrieNode(NULL); //creating the first root

	for (int i = 0; i < N; i++)
	{
		Insert(root, key[i]); //inserts each key into the tree
	}
	const char* searchitem = "geeks";
	int check = search(root, searchitem);

	return 0;
}