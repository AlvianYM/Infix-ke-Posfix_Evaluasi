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

class List
{
	public:
		Node *head=NULL;
		Node *last=NULL;

		void TB(int a)
		{
			Node *baru=new Node;
			baru->val=a;
			baru->next=NULL;
			if(head==NULL)
			{
				head=baru;
				last=baru;
			}
			else
			{
				last->next=baru;
				last=baru;
			}
		}

		int pop()
		{
			int a=head->val;
			Node *tmp=head->next;
			delete head;
			head=tmp;
			return a;
		}

		int depan()
		{
			return head->val;
		}

		void tampil()
		{
			Node *bantu=head;
			while(bantu!=NULL)
			{
				if(bantu->val=='*' || bantu->val=='/' || bantu->val=='+' || bantu->val=='-' || bantu->val=='(' || bantu->val==')')
					cout<<(char)bantu->val<<" ";
				else
					cout<<bantu->val<<" ";
				bantu=bantu->next;
			}
		}

};

int JadiInt(char a[5]);
int tingkat(int a);

int main()
{
	MyStack stack;
	List infix,postfix;
	char in[5];
	int i=0;
	
	cout<<"Gunakan Spasi Dalam Menginput! contoh : ( 3 * 4 ) + 2\n\n";
	cout<<"Input\n>>";
	
	while(in[i]!=10)
	{
		
		for(int j=0; j<5; j++)
			in[j]='\0';
		i=0;
		while(in[i-1]!=32 && in[i-1]!=10)
		{
			cin.get(in[i]);
			i++;
		}
		infix.TB(JadiInt(in));
		i--;
	}
	cout<<"Infix: ";
	infix.tampil();
	cout<<endl;

	while(infix.head!=NULL)
	{	
		if(infix.depan()=='*' || infix.depan()=='/' || infix.depan()=='+' || infix.depan()=='-')
		{
			if(stack.kosong() || stack.atas()=='(')
			{
				stack.push(infix.pop());
			}
			else
			{
				while(!stack.kosong() && stack.atas()!='(' && tingkat(infix.depan()) <= tingkat(stack.atas()))
				{
					postfix.TB(stack.pop());
				}
				stack.push(infix.pop());
			}
		}
		else if(infix.depan()=='(')
		{
			stack.push(infix.pop());
		}
		else if(infix.depan()==')')
		{
			while(!stack.kosong() && stack.atas()!='(')
			{
				postfix.TB(stack.pop());
			}
			infix.pop();
			stack.pop();
		}
		else
		{
			postfix.TB(infix.pop());
		}
	}
	while(!stack.kosong())
	{
		postfix.TB(stack.pop());
	}
	cout<<"Postfix: ";
	postfix.tampil();
	cout<<endl;
	
	int A,B,C;
	while(postfix.head!=NULL)
	{
		if(postfix.depan()=='*' || postfix.depan()=='/' || postfix.depan()=='+' || postfix.depan()=='-')
		{
			switch(postfix.pop())
			{
				case '*':
					A=stack.pop();
					B=stack.pop();
					C=B*A;
					stack.push(C);
					break;
				case '/':
					A=stack.pop();
					B=stack.pop();
					C=B/A;
					stack.push(C);
					break;
				case '-':
					A=stack.pop();
					B=stack.pop();
					C=B-A;
					stack.push(C);
					break;
				case '+':
					A=stack.pop();
					B=stack.pop();
					C=B+A;
					stack.push(C);
					break;
			}
		}
		else
		{
			stack.push(postfix.pop());
		}
		
	}
	cout<<"Hasil= "<<stack.pop();
	return 0;
}

int JadiInt(char a[5])
{
	if(a[0]=='*' || a[0]=='/' || a[0]=='+' || a[0]=='-' || a[0]=='(' || a[0]==')')
		return a[0];
	else
		return atoi(a);
}

int tingkat(int a)
{
	if (a=='*' || a=='/')
		return 2;
	else
		return 1;
}
