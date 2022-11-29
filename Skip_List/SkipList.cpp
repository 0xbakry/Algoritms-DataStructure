#pragma once
#include<vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int key;
	Node** next;

	Node(int k, int level)
	{
		key = k;
		next = new Node * [level + 1];
		memset(next, 0, sizeof(Node*) * (level + 1));
	}
	~Node()
	{
		delete[] next;
	};

};

class SkipList
{
private:
	int layer, maxLevel;
	float fraction;
	Node* header;
	

public:
	SkipList(int maxLevel, float f)
	{
		this->maxLevel = maxLevel;
		fraction = f;
		layer = 0;
		header = new Node(-1, maxLevel);
	}
	~SkipList()
	{
		
		delete header;

		/*cout << "\n*****Skip List Destructor*****" << "\n";
		for (int i = layer; i >=0; i--)
		{
			Node* node = header->next[i];
			cout << "Level " << i << ": ";
			while (node != NULL)
			{
				Node temp = &node;
				delete node;
				cout << "Node lev " << i << " deleted" << endl;
				node = temp;
			}
			cout << "\n";
		}*/
	}

	Node* creatNode(int k, int l)
	{
		Node* n = new Node(k, l);
		return n;
	}

	int randomLevel()
	{
		float r = (float)rand() / RAND_MAX;
		int lvl = 0;
		while (r < fraction && lvl < maxLevel)
		{
			lvl++;
			r = (float)rand() / RAND_MAX;
		}
		return lvl;
	};
	int search(int num)
	{
		bool found = false;
		int count = 0;
		Node* current = header;

		for (int i = layer; i >= 0; i--)
		{
			while (current->next[i] != NULL &&
				current->next[i]->key <= num)
			{
				if (current->next[i]->key == num)
				{
					found = true;
					return count;
				}
				current = current->next[i];
			}
			count++;
		}
		if (!found)
			return -1;
	}
	int getLayers()
	{
		return (layer + 1);
	}

	void insert(int num)
	{
		Node* current = header;
		
		Node** update;
		update = new Node* [5];
		memset(update, 0, sizeof(update));


		for (int i = layer; i >= 0; i--)
		{
			while (current->next[i] != NULL &&
				current->next[i]->key < num)
				current = current->next[i];

			update[i] = current;
		}
		current = current->next[0];

		if (current == NULL || current->key != num)
		{
			int re_level = randomLevel();

			if (re_level > layer)
			{
				for (int i = layer + 1; i < re_level + 1; i++)
					update[i] = header;

				layer = re_level;
				
			}

			Node* n = creatNode(num, re_level);

			for (int i = 0; i <= re_level; i++)
			{
				n->next[i] = update[i]->next[i];
				update[i]->next[i] = n;
			}
			cout << "Successfully Inserted key " << num << "\n";

		}

		//delete update;
	}
	void printLayer(int layerNum)
	{
		Node* node = header->next[layerNum];
		while (node != NULL)
		{
			cout << node->key << " ";
			node = node->next[layerNum];
		}
		cout << "\n";
	}
	void print()
	{
		cout << "\n*****Skip List*****" << "\n";
		for (int i = 0; i <= layer; i++)
		{
			Node* node = header->next[i];
			cout << "Level " << i << ": ";
			while (node != NULL)
			{
				cout << node->key << " ";
				node = node->next[i];
			}
			cout << "\n";
		}
	}
};


