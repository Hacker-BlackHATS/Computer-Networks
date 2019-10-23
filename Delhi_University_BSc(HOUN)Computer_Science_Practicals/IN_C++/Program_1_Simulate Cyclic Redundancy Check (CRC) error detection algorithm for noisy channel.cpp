// Program 1: Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class CRC{
    public:
        string dividend,divisor,n_s;
    public:
        CRC(){
            dividend = "";
            divisor = "";
            n_s = "";
        }
        void input(){
            cout<<"Enter value of dividend : ";
            cin>>dividend;
            cout<<"Enter value of divisor : ";
            cin>>divisor;
        }
        string mul_Z(int ke){
        	string s = "";
        	for(int i = 0;i<ke;i++){
        		s += "0";
			}
			return s;
		}
        string div(string ns){
        	int counter = divisor.length();
        	string s= ns.substr(0,counter);
        	while(counter < ns.length()){
        		if(s[0] == '1'){
        			s = Xor(divisor,s) + ns[counter];
				}
				else{
					s = Xor(mul_Z(counter),s) + ns[counter];
				}
				counter++;
			}
			if(s[0] == '1'){
				s = Xor(divisor,s);
			}
			else{
				s = Xor(mul_Z(counter),s);
			}
			return s;
		}
        void sender(){
            int len_k = divisor.length();
            string new_d = dividend + mul_Z(len_k-1);
            string remainder = div(new_d);
            cout<<"Dividend : "<<dividend<<"\nDivisor : "<<divisor<<endl;
            int a = rand() % 2;
            if(a == 1){
            	n_s = dividend + remainder;
            	cout<<"Dataword sent from sender side : "<<n_s<<endl;
				cout<<"Lightning or thunder bolt occur!!!\n";
            	int i = rand() % n_s.length();
            	if(n_s[i] == '1'){
            		n_s[i] = '0';
				}
				else{
					n_s[i] = '1';
				}
			}
			else if(a == 0){
				n_s = dividend + remainder;
				cout<<"Dataword sent from sender side : "<<n_s<<endl;
			}
        }
        bool receiver(string n_d){
			string r = div(n_d);
			cout<<"Dataword received by reveiver : "<<n_d<<endl;
			string check = mul_Z(divisor.length() - 1);
			cout<<"Remainder at reveiver end : "<<r<<endl;
			if(r == check){
				return true;
			}
			return false;
        }
        string Xor(string s1, string s2){
        	string s3 = "";
			for(int i= 1; i<s2.length();i++){
        		if(s1[i] == s2[i]){
        			s3 += '0';
				}
				else{
					s3 +='1';
				}
			}
			return s3;
		}
        void menu(){
            int option;char op='y';
            while(op == 'y'||op=='Y'){
                cout<<"\n1.Enter value of dividend and divisor\n2.Check data\n";
                cin>>option;
                switch(option){
                    case 1:{
                        input();
                        break;
                    }
                    case 2:{
                    	sender();
                        if(receiver(n_s)){
                            cout<<"Data received correctly!!!\n";
                        }
                        else{
                            cout<<"Error in Data receiving!!!\n";
                        }
                        break;
                    }
                    default:{
                        cout<<"Invalid Input!!!\n";
                    }
                }
                cout<<"Do you want to continue?(y/n) : ";
                cin>>op;
            }
        }
};
int main(){
    CRC obj;
    obj.menu();
	getch();
    return 0;
}
