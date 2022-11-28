#include<iostream>
using namespace std;

static int ID = -1;
class linkedList;

class trieNode {

private:
    trieNode* root;
    linkedList* list;

public:
    int id;
    trieNode();
    void insert( char[], trieNode*);
    linkedList* getList();

};

struct listNode {

    trieNode* childNode;
    char chr;
    listNode* next;

    listNode()
    {
        childNode = nullptr;
        chr = '/0';
        next = nullptr;

    }
    listNode(char chr, trieNode* childNode, listNode* next)
    {
        this->chr = chr;
        this->childNode = childNode;
        this->next = next;
    }
};

class linkedList {

public:
    int length;
    
    listNode* list_node;
    linkedList()
    {
        length = 0;
        list_node = new listNode;
        //list_node = nullptr;
    }
    void insertChar(char c, trieNode* child)
    {

            listNode* node = new listNode(c, child, nullptr);

            if (this->list_node == nullptr)
            {
                list_node = node;

            }

            else
            {
                while (list_node->next != nullptr)
                    list_node = list_node->next;

                list_node->next = node;
                list_node->next->next = nullptr;
            }

            //delete node;
            length++;
        
    }
    bool searchForNode(char c)
    {

        if (list_node->chr == c)
            return true;

        if (list_node->next != nullptr)
        { 
            list_node = list_node->next;
            searchForNode(c);
        }
        else
            return false;
    }

    ~linkedList()
    {
        while(list_node != nullptr)
            delete list_node;

    }
 
};

trieNode::trieNode()
{
    linkedList* list = new linkedList;
    list = nullptr;
    
}

linkedList* trieNode::getList()
{
    return list;
}

void trieNode::insert(char c[], trieNode* r)
{
    root = r;
    linkedList* l = new linkedList();
    r->list = l;
    //delete l;

    int j = 0;
    int size = 0;
     
    while (c[size] != '\0') {
        size++;
    }

    while (j != size)
    {
        for (int l = j; l < size; l++)
        {
                trieNode* curr = root;

                for (int i = j; i < size; i++)
                {
                    curr = root;
                    if (c[i] != '$')
                    {
                            if (curr->list->searchForNode(c[i]))
                                if (!(curr->list->list_node->childNode == nullptr))
                                {
                                    curr = curr->list->list_node->childNode;
                                    break;
                                }
                                else
                                {
                                    trieNode* new_trie_node = new trieNode;
                                    linkedList* l = new linkedList();

                                    new_trie_node->list = l;
                                    new_trie_node->list->insertChar(c[i], nullptr);
                                    curr->list->list_node->childNode = new_trie_node;
                                    
                                    delete new_trie_node;
                                    //delete l;
                                }

                            else
                                curr->list->insertChar(c[i], curr->list->list_node->childNode);    
                    }
                    else
                    {
                        curr->list->insertChar('$', nullptr);
                        curr->id = ID++;
                    }

                }

        }
            j++;
    }

    cout << "DONE" << endl;
}

class Trie
{

private:
    trieNode* r;
    
public:
    Trie( char chars[])
    {
        r = new trieNode;

        r->insert(chars, r);
    }


    ~Trie()
    {

        delete r;
    }

    //trieNode* childSearch(char target, linkedList* list)
    //{
    //    trieNode* nodeList = list->list_node;
    //    while (nodeList->next != nullptr)
    //    {
    //        if (nodeList->chr == target)
    //            return nodeList;
    //        else
    //            nodeList = nodeList->next;
    //    }
    //    return nullptr;

    //}

    bool suffixSearchHelper(string suffix)
    {
        trieNode* root = r;

        if (!(root->getList() == nullptr))
        {
            trieNode* curr = root;

            for (int i = 0; i < suffix.size(); i++)
            {
                bool found = false;
                if (curr->getList()->searchForNode(suffix[i]))
                    if (!(curr->getList()->list_node->childNode == nullptr))
                        curr = curr->getList()->list_node->childNode;

                    else
                    {
                        if (i == (suffix.size() - 1))
                            return true;
                        else
                            return false;
                    }
                else
                    return false;
            }
            return true;

        }

        else
            return false;
      
        //trieNode* current = r;
        //linkedList* list = current->getList();
        //listNode* node = list->list_node;
       
        //while (list->list_node->next != nullptr)
        //{
        //    for (int i = 0; i < suffix.length(); i++)
        //    {
        //        if (list->list_node->chr == suffix[i])
        //             list = list->list_node->childNode->getList();    

        //        else
        //        {   
        //            if (list->list_node->next != nullptr)
        //                node = list->list_node->next;
        //            else
        //             return false;   
        //            
        //        }
        //        
        //    }
        //    return true;
        //}

    }

};



int main()
{
    char chars[] = "bananaasfdsbanaba$";

    Trie t(chars);

    cout << t.suffixSearchHelper("fdsb") << endl;;

    //char chars[] = "bananaasfdsbanaba$";
    cout << "Size: " << sizeof(chars) << endl;
    return 0;
}
