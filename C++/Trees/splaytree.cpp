
#include <bits/stdc++.h>
using namespace std;
// node declaration
struct s
{
    int k;
    s *lch;
    s *rch;
};
// splaytree class which includes all the function
class SplayTree
{
public:
    //---------------------------------------------RIGHT ROTATION--------------------------------------
    s *RR_Rotate(s *k2)
    {
        s *k1 = k2->lch;
        k2->lch = k1->rch;
        k1->rch = k2;
        return k1;
    }
    //---------------------------------------------lEFT ROTATION--------------------------------------
    s *LL_Rotate(s *k2)
    {
        s *k1 = k2->rch;
        k2->rch = k1->lch;
        k1->lch = k2;
        return k1;
    }
    //---------------------------------------------SPLAY TREE--------------------------------------
    s *Splay(int key, s *root)
    {
        if (!root)
            return NULL;
        s header;
        header.lch = header.rch = NULL;
        s *LeftTreeMax = &header;
        s *RightTreeMin = &header;
        while (1)
        {
            if (key < root->k)
            {
                if (!root->lch)
                    break;
                if (key < root->lch->k)
                {
                    root = RR_Rotate(root);
                    if (!root->lch)
                        break;
                }
                RightTreeMin->lch = root;
                RightTreeMin = RightTreeMin->lch;
                root = root->lch;
                RightTreeMin->lch = NULL;
            }
            else if (key > root->k)
            {
                if (!root->rch)
                    break;
                if (key > root->rch->k)
                {
                    root = LL_Rotate(root);
                    if (!root->rch)
                        break;
                }
                LeftTreeMax->rch = root;
                LeftTreeMax = LeftTreeMax->rch;
                root = root->rch;
                LeftTreeMax->rch = NULL;
            }
            else
                break;
        }
        LeftTreeMax->rch = root->lch;
        RightTreeMin->lch = root->rch;
        root->lch = header.rch;
        root->rch = header.lch;
        return root;
    }
    //---------------------------------------------CREATE NEW NODE--------------------------------------
    s *New_Node(int key)
    {
        s *p_node = new s;
        if (!p_node)
        {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
        p_node->k = key;
        p_node->lch = p_node->rch = NULL;
        return p_node;
    }
    //---------------------------------------------INSERTION--------------------------------------
    s *Insert(int key, s *root)
    {
        static s *p_node = NULL;
        if (!p_node)
            p_node = New_Node(key);
        else
            p_node->k = key;
        if (!root)
        {
            root = p_node;
            p_node = NULL;
            return root;
        }
        root = Splay(key, root);
        if (key < root->k)
        {
            p_node->lch = root->lch;
            p_node->rch = root;
            root->lch = NULL;
            root = p_node;
        }
        else if (key > root->k)
        {
            p_node->rch = root->rch;
            p_node->lch = root;
            root->rch = NULL;
            root = p_node;
        }
        else
            return root;
        p_node = NULL;
        return root;
    }
    //--------------------------------------------DELETION--------------------------------------
    s *Delete(int key, s *root) // delete node
    {
        s *temp;
        if (!root) // if tree is empty
            return NULL;
        root = Splay(key, root);
        if (key != root->k) // if tree has one item
            return root;
        else
        {
            if (!root->lch)
            {
                temp = root;
                root = root->rch;
            }
            else
            {
                temp = root;
                root = Splay(key, root->lch);
                root->rch = temp->rch;
            }
            free(temp);
            return root;
        }
    }
    //---------------------------------------------SEARCH IN TREE--------------------------------------
    s *Search(int key, s *root) // seraching
    {
        return Splay(key, root);
    }
    //---------------------------------------------INORDER TRAVERSAL --------------------------------------
    void InOrder(s *root) // inorder traversal
    {
        if (root)
        {
            InOrder(root->lch);
            cout << "key: " << root->k;
            if (root->lch)
                cout << " | left child: " << root->lch->k;
            if (root->rch)
                cout << " | right child: " << root->rch->k;
            cout << "\n";
            InOrder(root->rch);
        }
    }
};
int main()
{
    SplayTree st;
    s *root;
    root = NULL;
    st.InOrder(root);
    int i, c;
    while (1)
    {
        cout << "1. Insert " << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        // perform switch operation
        switch (c)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            root = st.Insert(i, root);
            cout << "\nAfter Insert: " << i << endl;
            st.InOrder(root);
            break;
        case 2:
            cout << "Enter value to be deleted: ";
            cin >> i;
            root = st.Delete(i, root);
            cout << "\nAfter Delete: " << i << endl;
            st.InOrder(root);
            break;
        case 3:
            cout << "Enter value to be searched: ";
            cin >> i;
            root = st.Search(i, root);
            cout << "\nAfter Search " << i << endl;
            st.InOrder(root);
            break;
        case 4:
            exit(1);
        default:
            cout << "\nInvalid type! \n";
        }
    }
    cout << "\n";
    return 0;
}