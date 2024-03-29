/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include <iostream>
#define MAX 10
using namespace std;

class Queue
{    
		private:
		int data[MAX];
       	int front,rear;
   public:
      Queue()
	  {
	  front=rear=-1;
	  }
      int isempty();
      int isfull();
      void enqueue(int);
      int delqueue();
      void display();
};
int Queue::isempty()
{
	if(front ==rear)
	return(1);
	else
	return(0);
}
int Queue::isfull()
{    
if(rear==MAX-1)
return(1);
else
return(0);
}
void Queue::enqueue(int x)
{
	rear++;
	data[rear]=x;
}
int Queue::delqueue()
{	 
	front++;
	return(data[front]);
}
void Queue::display()
{   int i;
    cout<<"\n";
    for(i=front+1;i<=rear;i++)
	     cout<<data[i]<<" ";
}
int main()
{      Queue Q;
	int ch,x;
	do{    cout<<"\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
	       cin>>ch;
	switch(ch)
	{  case 1: if (!Q.isfull())
		   {   cout<<"\n Enter Job number : \n";
			cin>>x;
			Q.enqueue(x);
			cout<<endl;
		   }
	          else
		      cout<< "Queue is overflow!!!\n\n";
	           break;
	   case 2: if(!Q.isempty())
			    cout<<"\n Deleted Job = "<<Q.delqueue()<<endl;
		    else
			{   cout<<"\n Queue is underflow!!!\n\n";  }
		    cout<<"\nRemaining Jobs : \n";
		    Q.display();
	           break;
	  case 3: if (!Q.isempty())
	        {  cout<<"\n Queue contains : \n";
		       Q.display();
	        }
	        else
		         cout<<"\n Queue is empty!!!\n\n";
	       break;
	  case 4: cout<<"\n Exiting Program.....";
        }
      }while(ch!=4);
return 0;
}

