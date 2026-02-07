#include <iostream>
using namespace std;
struct node{
	int ID;
	string title;
	string artist;
	float duration;
	node *n;
	node *p;
};
class playlist{
	private:
		node *start,*temp,*cur;
	public:
		playlist(){
			start=NULL;
		}
		
		void insert(){
			if(start==NULL){
				start=new node;
				cout<<"PLease enter song's details:"<<endl;
				cout<<"ID: ";
				cin>>start->ID;
				cout<<"Title: ";
				cin>>start->title;
				cout<<"Artist Name: ";
				cin>>start->artist;
				cout<<"Duration: ";
				cin>>start->duration;
				start->n=NULL;
				start->p=NULL;
			}
			else{
				cur=start;
				while(cur->n!=NULL){
					cur=cur->n;
				}
				temp=new node;
				cout<<"PLease enter song's details:"<<endl;
				cout<<"ID: ";
				cin>>temp->ID;
				cout<<"Title: ";
				cin>>temp->title;
				cout<<"Artist Name: ";
				cin>>temp->artist;
				cout<<"Duration: ";
				cin>>temp->duration;
				
				cur->n=temp;
				temp->p=cur;
				temp->n=NULL;
			}
		}
		
		void search(){
			cur=start;
			int choice;
			string t,in;
			cout<<"How do you want to find the song? using..."<<endl;
			cout<<"1. Artist Name"<<endl<<"2. Title"<<endl<<"Enter your choice: ";
			cin>>choice;
			if(choice==1){
				cout<<"PLease enter Artist Name: ";
				cin>>in;
				while(cur->artist!=in){
					cur=cur->n;
				}
				if(cur==NULL){
					cout<<"Song not found"<<endl;
				}
				else{
					cout<<"Song is found"<<endl;
				}
			}
			else if(choice==2){
			cout<<"PLease enter Title: ";
				cin>>t;
				while(cur->title!=t){
					cur=cur->n;
				}
				if(cur==NULL){
					cout<<"Song not found"<<endl;
				}
				else{
					cout<<"Song is found"<<endl;
				}
					}
				else{
					cout<<"Invalid Choice"<<endl;
				}	
		}
		
		void modify(){
			int choice;
			cur=start;
			cout<<"Please enter the ID of song to modify its details: ";
			cin>>choice;
			while(cur->ID!=choice){
				cur=cur->n;
			}
			if(cur==NULL){
				cout<<"Record not found"<<endl;
			}
			else{
				cout<<"Enter new details "<<endl;
				cout<<"ID: ";
				cin>>cur->ID;
				cout<<"Title: ";
				cin>>cur->title;
				cout<<"Artist Name: ";
				cin>>cur->artist;
				cout<<"Duration: ";
				cin>>cur->duration;
			}
		}
		
		void display(){
			int i=0;
			cur=start;
			while(cur!=NULL){
				cout<<"Details of song "<<++i<<endl;
				cout<<"ID: "<<cur->ID<<endl<<"Title: "<<cur->title<<endl<<"Artist Name: "<<cur->artist<<endl<<"Duration: "<<cur->duration<<endl;
				cur=cur->n;
			}
		}
		void traversal(){
			cur=start;
			int choice;
			cout<<"Tap the button to change the song"<<endl;
			cout<<"1. Next"<<endl<<"2. Previous"<<endl<<"3. Invalid"<<endl<<endl;
			cin>>choice;
			if(choice==1){
				if(cur->n!=NULL){
					cur=cur->n;
					cout<<"Next song is played"<<endl;
				}
				else{
					cout<<"You are already on last song"<<endl;
				}
			}
			else if(choice==2){
				if(cur->p!=NULL){
					cur=cur->p;
					cout<<"Previous song is played"<<endl;
				}
				else{
					cout<<"You are already on 1st song"<<endl;
				}
			}
			else{
				cout<<"Invalid choice"<<endl;
			}
		}
};

int main(){
	int choice;
	playlist it;
	do{
		cout<<"=========Music Playlist========="<<endl;
		cout<<"1. Add Song"<<endl;
		cout<<"2. Search Song"<<endl;
		cout<<"3. Modify Song"<<endl;
		cout<<"4. Full playlist"<<endl;
		cout<<"5. Change Song"<<endl;
		cout<<"6. Exit"<<endl<<endl;
		cout<<"Please enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				it.insert();
				break;
			case 2:
				it.search();
				break;
			case 3:
				it.modify();
				break;
			case 4:
				it.display();
				break;
			case 5:
				it.traversal();
				break;
			case 6:
				cout<<"Exiting...."<<endl;
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(choice!=6);
	return 0;
}
