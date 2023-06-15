#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node*left;
        node*right;
    node()
    {
        left=right=NULL;
    }

};

node*insert(node*current_node,node*root)
{
    if(root==NULL)
        root=current_node;
    else{
        node*ptr=root;
        while(1)
        {
            if(current_node->data<ptr->data)
            {
                if(ptr->left!=NULL)
                {
                    ptr=ptr->left;
                }
                else{
                    ptr->left=current_node;
                    break;
                }
            }
            else
            {
                if(ptr->right!=NULL)
                {
                    ptr=ptr->right;
                }else{
                    ptr->right=current_node;
                    break;
                }

            }
        }
    }
    return root;
}

int longest_path(node*ptr)
{
    if(ptr==NULL)
    return 0;
    int lh,rh;
    lh=1+longest_path(ptr->left);
    rh=1+longest_path(ptr->right);
    return lh>rh ? lh : rh;
 }

 int min_value(node*ptr)
 {
    if(ptr->left==NULL)
        return ptr->data;
    min_value(ptr->left);
 }

  int max_value(node*ptr)
 {
    if(ptr->right==NULL)
        return ptr->data;
    max_value(ptr->right);
 }

 int mirror(node*ptr)
 {
    if(ptr==NULL)
        return 0;
    node*temp;
    temp=ptr->left;
    ptr->left=ptr->right;
    ptr->right=temp;
    mirror(ptr->left);
    mirror(ptr->right);
 }

bool search_element(int data, node*ptr)
{
    if(ptr==NULL)
        return 0;
    if(ptr->data==data)
        return 1;
    if(ptr->data>data)
        return search_element(data,ptr->left);
    if(ptr->data<data)
        return search_element(data,ptr->right);
}

int display(node*ptr)
{
    if(ptr==NULL)
        return 0;
    display(ptr->left);
    cout<<ptr->data<<endl;
    display(ptr->right);



}

int main()
{
    node* root=NULL;
    int ch,data;
    while (true)
    {
        cout<<"\n1. Insert\n2. Longest path\n3. minimum and maximum value\n4. search\n5. mirror\n6. Display\n7. Exit\n\nENTRE YOUR CHOICE : ";
        cin>>ch;
        switch(ch)
        {
            case 1:{cout<<"Enter value to insert : ";
                    cin>>data;
                    node*current_node=new node();
                    current_node->data=data;
                    root=insert(current_node,root);
                    cout<<data<<" inserted in Tree "<<endl;}
                    break;

            case 2: cout<<" The longest path in the Tree is : "<<longest_path(root)<<endl;
                    break;

            case 3: cout<<"Minimum value in Tree is "<<min_value(root)<<endl;
                    cout<<"Maimum value in Tree is "<<max_value(root)<<endl;
                    break;

            case 4: cout<<"Enter the value to be searched : ";
                    cin>>data;
                    if(!search_element)
                        cout<<"Value not found"<<endl;
                    else{
                        cout<<"Value found in Tree "<<endl;
                    }
                    break;

            case 5: mirror(root);
                    cout<<"THE Tree is mirror successfully"<<endl;
                    break;



            case 6: display(root);
                    break;

            case 7: return 0;

            default:
                    cout<<"invalid choice"<<"\n\n";
                    break;
        }
    }
    return 0;
}