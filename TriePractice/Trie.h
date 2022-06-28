#pragma once
#define ALPHABET_SIZE 25
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])  //formulas created for simplification
#define CHAR_TO_INDEX(x) ((int)x - (int)'a') 
typedef char TType;
typedef struct Trienode
{
	TType data;
	Trienode* Children[ALPHABET_SIZE];
	bool isEndofWord;

}Trienode;


Trienode* GetTrieNode(TType data)
{
	Trienode* root;

	root = (Trienode*)malloc(sizeof(Trienode));

	if (root)//exists
	{
		root->data = data;
		root->isEndofWord = false;


		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			root->Children[i] = NULL; //creating every null
		}

	}
	return root;

}
void Insert(Trienode* root, const char* key)
{
	Trienode* Crawl = root;
	int Index;
	int length = strlen(key);


	for (int level = 0; level < length; level++)
	{
		Index = CHAR_TO_INDEX(key[level]); 

		if (!Crawl->Children[Index])  //if that particular place is empty
		{
			Crawl->Children[Index] = GetTrieNode(key[level]); //create a node there!
		}
		Crawl = Crawl->Children[Index];

	}

	Crawl->isEndofWord = true; //the last letter

}
bool search(Trienode* root, const char* key)
{
	int index;
	int length = strlen(key);
	Trienode* crawl = root;


	for (int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!crawl->Children[index]) //if it's null return false;
			return false; 

		crawl = crawl->Children[index];
	}

	return crawl->isEndofWord; //if they code is able to not enter that if statement, it means that the word exists, so return true

}