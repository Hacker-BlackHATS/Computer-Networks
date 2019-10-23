// Program 6 :Simulate Classful Addressing by taking the IP address (Dotted-Decimal notation) as input and print the corresponding class.
#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
class Q6{
	public:
		string ip_v4;
	public:
		Q6(){
			ip_v4 = "000.000.000.000";
		}
		void input(){
			cout<<"Enter IP_v4 IP address : ";
			cin>>ip_v4;
		}
		char check_class(string str){
			stringstream geek(str);
			int nid = 0;
			geek>>nid;
			if(0<=nid&&nid<=127){
				return 'A';
			}
			else if(128<=nid&&nid<=191){
				return 'B';
			}
			else if(192<=nid&&nid<=223){
				return 'C';
			}
			else if(224<=nid&&nid<=239){
				return 'D';
			}
			else if(240<=nid&&nid<=255){
				return 'E';
			}
		}
		void check_main(){
			string ch = ip_v4.substr(0,3);
			cout<<"IP Address belong to Class "<<check_class(ch)<<endl;
		}
};
int main(){
	Q6 obj;
	obj.input();
	obj.check_main();
	getch();
	return 0;
}
