#include <iostream>
using namespace std;
struct Node
{
	int key;
	Node* lptr;
	Node* rptr;
	Node* parent;
	static Node* srch;
};
class Tree
{
	Node* root;
	public:
		void creation();
		void insert(int);
		void traverse();
		void inOrder(Node*);
		void preOrder(Node*);
		void postOrder(Node*);
		bool Search(int);
		bool remove(int);
		int findLarger(int);
		int removeLarger(int);
};
void Tree :: creation()
{
	int val,chh;
	do
	{
		cout<<"Enter Data: ";
		cin>>val;
		insert(val);
		cout<<"Have Another Node?\n   1.Yes  2.No \n";
		cin>>chh;
	}while(chh==1);
}
void Tree :: insert(int v)
{
	Node* newnode= new Node;
	Node* temp= new Node;
	newnode->key=v;
	newnode->lptr=NULL;
	newnode->rptr=NULL;
	if(!root)
	{
		root=newnode;
		cout<<"ROOT NOOT IS INSERTED\n";
	}
	else
	{
		temp=new Node;
		temp=root;
		while(temp)
		{
			if(temp->key> newnode->key)
			{
				if(temp->lptr==NULL)
				{
				temp->lptr=newnode;
				temp->parent=newnode;
				break;
				}
				temp=temp->lptr;
				cout<<"VALUE SUCCESSFULLY INSERTED\n";//left
			}
			else if(temp->key<=newnode->key)
			{
				if(temp->rptr==NULL)
				{
					temp->rptr=newnode;
					temp->parent=newnode;
					break;
				}
				temp=temp->rptr;
				cout<<"VALUE SUCCESSFULLY INSERTED\n";
			}
		}
	}
}
void Tree :: traverse()
{
	Node* trv;
	trv=root;
	int ch;
	cout<<" 1.Inorder\n";
	cout<<" 2.Preorder\n";
	cout<<" 3.Postorder\n";
	cout<<" 4.Back to main\n";
	cout<<" Enter choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			inOrder(trv);
			cout<<endl;
			return;
		case 2:
			cout<<endl;
			preOrder(trv);
			return;
		case 3:
			cout<<endl;
			postOrder(trv);
			return;
		case 4:
			ch=4;
	}while(ch!=4);
}
void Tree :: inOrder(Node* rt)
{
	if(rt)
	{
		if(rt->key==-1)
		{
			cout<<"D ";
		}
		else
		{
			inOrder(rt->lptr);
			cout<<rt->key<<" ";
			inOrder(rt->rptr);
		}
	}
} 
void Tree::preOrder(Node* rt)
{
	if(rt)
	{
		if(rt->key==-1)
		{
			cout<<"D ";
		}
		else
		{
			cout<<rt->key<<"\t";
    		preOrder(rt->lptr);
    		preOrder(rt->rptr);
        }
	}
}
void Tree :: postOrder(Node* rt)
{
	if(rt)
	{
		if(rt->key==-1)
		{
			cout<<"D ";
		}
		else
		{
			postOrder(rt->lptr);
			postOrder(rt->rptr);
			cout<<rt->key;
		}
		
	}
}

bool Tree :: Search(int v)
{
	bool found=false;
	Node* temp=root;
	while(temp)
	{
		if(temp->key==v)
		{
			found=true;
			return true;
		}
		else if(temp->key>v)
		{
		
			temp=temp->lptr;
		}
		else
			temp=temp->rptr;
	}
	return false;
	
}
bool Tree :: remove(int v)
{
	Node* temp=root;
	while(temp)
	{
		if(temp->key==v)
		{
			temp->key=-1;
			return true;
		}
		else if(temp->key>v)
		{
		
			temp=temp->lptr;
		}
		else
			temp=temp->rptr;
	}
	return false;
	
}
int Tree :: findLarger(int v)
{
	if(Search(v))
	{
		return v;
	}
	//Now we have to find maximum value in tree
	int max;
	Node* rt;
	rt=root;
	if(!root)
	{
		cout<<"Tree is Empty\n";
		exit(-1);
	}
	while(rt!=NULL)
	{	
		max=rt->key;
		rt=rt->rptr;
	}
	//now checking for the greater
	for(int i=v;i<=max;i++)
	{
		if(Search(i))
		return i;
	}
	return -1;
}
int Tree::removeLarger(int v)
{
	if(Search(v))
	{
		remove(v);
		return v;
	}
	//Now we have to find maximum value in tree
	int max;
	Node* rt;
	rt=root;
	if(!root)
	{
		cout<<"Tree is Empty\n";
		exit(-1);
	}
	while(rt!=NULL)
	{	
		max=rt->key;
		rt=rt->rptr;
	}
	//now checking for the greater
	for(int i=v;i<=max;i++)
	{
		if(Search(i))
		{ 
		    remove(v);
			return i;	
		}
	}
	return -1;	
}
int main()
{
	int ch,v,val; bool found;
	Tree tree;
	do
	{
		cout<<"\n       Main Menu\n";
		cout<<"1. Insert Value\n";
		cout<<"2. Find Value\n";//search
		cout<<"3. Remove Value\n";
		cout<<"4. Traverse\n";
		cout<<"5. Find Larger\n";
		cout<<"6. Remove Larger\n";
		cout<<"7. Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			tree.creation();
			break;
		case 2:
			cout<<"Enter Value to find: ";
			cin>>v;
			if(tree.Search(v))
			{
				cout<<"VALUE FOUND.";
			}
			else
			{
				cout<<"NOT FOUND THE VALUE";
			}
			break;
		case 3:
			cout<<"Enter Value To Remove: ";
			cin>>v;
			if(tree.Search(v))
			{
			  	tree.remove(v);
			  	cout<<"Value Removed Sucessfully";
			}
			else
			{
				cout<<"NOT FOUND THE VALUE.\n";
			}
			break;
		case 4:
			tree.traverse();
			break;
		case 5:
			cout<<"Enter value to Find Larger: ";
			cin>>v;
			v=tree.findLarger(v);
			cout<<"Vale is ";
			cout<<v;
			break;
		case 6:
			cout<<"Enter value to Remove Larger: ";
			cin>>v;
			v=tree.removeLarger(v);
			cout<<v;
			cout<<"is removed";
			break;
		case 7: 
			exit(-1);
		}	
	}while(1);
	return 0;
}
