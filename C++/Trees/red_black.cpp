#include<iostream>
using namespace std;
struct node
{
       int key;
       node *parent;
       char color;
       node *left;
       node *right;
};
class RB_tree
{
      node *root;
      node *q;
   public :
      RB_tree()
      {
              q=NULL;
              root=NULL;
      }
      void insert();
      void insert_fix(node *);
      void left_rotate(node *);
      void right_rotate(node *);
      void del();
      node* successor(node *);
      void delfix(node *);
      void disp();
      void display( node *);
      void search();
};
void RB_tree::insert()
{
     int z,i=0;
     cout<<"\nENTER THE KEY OF THE NODE TO BE INSERTED: "; cin>>z;
     node *p,*q;
     node *t=new node;
     t->key=z;
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     insert_fix(t);
}
void RB_tree::insert_fix(node *t)
{
     node *u;
     if(root==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 left_rotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            right_rotate(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   right_rotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            left_rotate(g);
                        }
           }
           root->color='b';
     }
}
void RB_tree::del()
{
     if(root==NULL)
     {
           cout<<"\nEMPTY TREE." ;
           return ;
     }
     int x;
     cout<<"\nENTER THE KEY OF THE NODE TO BE DELETED: "; cin>>x;
     node *p;
     p=root;
     node *y=NULL;
     node *q=NULL;
     int found=0;
     while(p!=NULL&&found==0)
     {
           if(p->key==x)
               found=1;
           if(found==0)
           {
                 if(p->key<x) p=p->right;
                 else
                    p=p->left;
           }
     }
     if(found==0)
     {
            cout<<"\nELEMENT NOT FOUND.";
            return ;
     }
     else
     {
         cout<<"\nDELETED ELEMENT: "<<p->key;
         cout<<"\nCOLOUR: "; if(p->color=='b')
     cout<<"BLACK\n";
    else
     cout<<"RED\n"; if(p->parent!=NULL)
               cout<<"\nPARENT: "<<p->parent->key;
         else
               cout<<"\nTHERE IS NO PARENT OF THE NODE. "; if(p->right!=NULL)
               cout<<"\nRIGHT CHILD "<<p->right->key;
         else
               cout<<"\nTHERE IS NO RIGHT CHILD OF THE NODE. "; if(p->left!=NULL)
               cout<<"\nLEFT CHILD: "<<p->left->key;
         else
               cout<<"\nTHERE IS NO RIGHT CHILD OF THE NODE. ";
         cout<<"\nNODE DELETED."; if(p->left==NULL||p->right==NULL)
              y=p;
         else
              y=successor(p);
         if(y->left!=NULL)
              q=y->left;
         else
         {
              if(y->right!=NULL)
                   q=y->right;
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent=y->parent;
         if(y->parent==NULL)
              root=q;
         else
         {
             if(y==y->parent->left)
                y->parent->left=q;
             else
                y->parent->right=q;
         }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
         }
         if(y->color=='b')
             delfix(q);
     }
}
void RB_tree::delfix(node *p)
{
    node *s;
    while(p!=root&&p->color=='b')
    {
          if(p->parent->left==p)
          {
                  s=p->parent->right;
                  if(s->color=='r')
                  {
                         s->color='b';
                         p->parent->color='r';
                         left_rotate(p->parent);
                         s=p->parent->right;
                  }
                  if(s->right->color=='b'&&s->left->color=='b')
                  {
                         s->color='r';
                         p=p->parent;
                  }
                  else
                  {
                      if(s->right->color=='b')
                      {
                             s->left->color=='b';
                             s->color='r';
                             right_rotate(s);
                             s=p->parent->right;
                      }
                      s->color=p->parent->color;
                      p->parent->color='b';
                      s->right->color='b';
                      left_rotate(p->parent);
                      p=root;
                  }
          }
          else
          {
                  s=p->parent->left;
                  if(s->color=='r')
                  {
                        s->color='b';
                        p->parent->color='r';
                        right_rotate(p->parent);
                        s=p->parent->left;
                  }
                  if(s->left->color=='b'&&s->right->color=='b')
                  {
                        s->color='r';
                        p=p->parent;
                  }
                  else
                  {
                        if(s->left->color=='b')
                        {
                              s->right->color='b';
                              s->color='r';
                              left_rotate(s);
                              s=p->parent->left;
                        }
                        s->color=p->parent->color;
                        p->parent->color='b';
                        s->left->color='b';
                        right_rotate(p->parent);
                        p=root;
                  }
          }
       p->color='b';
       root->color='b';
    }
}
void RB_tree::left_rotate(node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
}
void RB_tree::right_rotate(node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
}
node* RB_tree::successor(node *p)
{
      node *y=NULL;
     if(p->left!=NULL)
     {
         y=p->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else
     {
         y=p->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
}
void RB_tree::disp()
{
     display(root);
}
void RB_tree::display(node *p)
{
     if(root==NULL)
     {
          cout<<"\nEMP.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n KEY: "<<p->key;
                cout<<"\n COLOR: "; if(p->color=='b')
     cout<<"BLACK";
    else
     cout<<"Red"; if(p->parent!=NULL)
                       cout<<"\n PARENT: "<<p->parent->key;
                else
                       cout<<"\n THERE IS NO PARENT OF THE NODE. "; if(p->right!=NULL)
                       cout<<"\n RIGHT CHILD: "<<p->right->key;
                else
                       cout<<"\n THERE IS NO RIGHT CHILD OF THE NODE.. "; if(p->left!=NULL)
                       cout<<"\n LEFT CHILD: "<<p->left->key;
                else
                       cout<<"\n THERE IS NO LEFT CHILD OF THE NODE.  ";
                cout<<endl; if(p->left)
    {
                 cout<<"\n\nLEFT:\n"; display(p->left);
    }

    if(p->right)
    {
         cout<<"\n\nRIGHT:\n"; display(p->right);
    }
     }
}
void RB_tree::search()
{
     if(root==NULL)
     {
           cout<<"\nEMPTY TREE\n" ;
           return  ;
     }
     int x;
     cout<<"\n ENTER THE KEY TO BE SEARCHED: "; cin>>x;
     node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x) p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"\nELEMENT NOT FOUND.";
     else
     {
                cout<<"\n\t FOUND NODE: ";
                cout<<"\n KEY: "<<p->key;
                cout<<"\n COLOUR: "; if(p->color=='b')
     cout<<"BLACK";
    else
     cout<<"RED"; if(p->parent!=NULL)
                       cout<<"\n PARENT: "<<p->parent->key;
                else
                       cout<<"\n THERE IS NO PARENT OF THE NODE. "; if(p->right!=NULL)
                       cout<<"\n RIGHT CHILD: "<<p->right->key;
                else
                       cout<<"\n THERE IS NO RIGHT CHILD OF THE NODE. "; if(p->left!=NULL)
                       cout<<"\n LEFT CHILD: "<<p->left->key;
                else
                       cout<<"\n THERE IS NO LEFT CHILD OF THE NODE.  ";
                cout<<endl;
     }
}
int main()
{
    int ch,y=0;
    RB_tree obj;
    cout<<"\n\t--------RED BLACK TREE---------" ;
    do
    {               
                cout<<"\n 1. INSERT NODE";
                cout<<"\n 2. DELETE NODE";
                cout<<"\n 3. SEARCH FOR ELEMENT";
                cout<<"\n 4. DISPLAY ";
                cout<<"\n 5. EXIT " ;
                cout<<"\nSelect the operation you want to perform : "; cin>>ch;
                switch(ch)
                {
                          case 1 : obj.insert();
                                   cout<<"\nNODE INSERTED.\n";
                                   break;
                          case 2 : obj.del();
                                   break;
                          case 3 : obj.search();
                                   break;
                          case 4 : obj.disp();
                                   break;
                          case 5 : y=1;
                                   break;
                          default : cout<<"\nENTER A VALID CHOICE!!.";
                }
                cout<<endl;
    }while(y!=1);
    return 1;
}