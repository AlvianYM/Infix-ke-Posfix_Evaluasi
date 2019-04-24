#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
};

class MyStack
{
	private:
		Node *head=NULL;

	public:
		bool kosong()
		{
			if(head==NULL)
				return true;
			return false;
		}

		void push(int a)
		{
			Node *baru=new Node;
			baru->val=a;
			baru->next=NULL;
			if(kosong())
			{
				head=baru;
			}
			else
			{
				baru->next=head;
				head=baru;
			}
		}

		int pop()
		{
			if(kosong())
			{
				cout<<"Stack kosong!"<<endl;
				return 0;
			}
			else
			{
				int a=head->val;
				Node *tmp=head->next;
				delete head;
				head=tmp;
				return a;
			}
		}

		int atas()
		{
			return head->val;
		}

		void tampil()
		{
			Node *bantu=head;
			while(bantu!=NULL)
			{
				cout<<endl<<bantu->val;
				bantu=bantu->next;
			}
		}

};
