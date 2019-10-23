// Program 2 : Simulate Hamming code for a given input message.
#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Q2{
    public:
        string data,result,check;int rb;
    public:
        Q2(){
            data = "";result ="";check = "";rb = 0;
        }
        void input(){
            cout<<"Enter the dataword : ";
            cin>>data;
        }
        void redundant_bits(){
        	while(pow(2,rb) < data.length() + rb + 1){
        		rb++;
			}
		}
        void redundant_position(){
        	redundant_bits();
            int j = 0;int l_d = data.length()-1;
            for(int  i = 1; i < data.length() + rb + 1; i++){
            	if(i == pow(2,j)){
            		result += "p";j++;
				}
				else{
					result += data[l_d--];
				}
			}
        }
        void reverse(){
        	int n = result.length();
			for(int i = 0; i <n/2; i++){
				char temp = result[i];
				result[i] = result[n-1-i];
				result[n-1-i] = temp;
			}
		}
        void sender(){
        	redundant_position();
        	int i = 0;
        	while(i < rb){
        		result[pow(2,i)-1] = parity_bit(pow(2,i));i++;
			}
		}
		char parity_bit(int i){
			int count= 0;
			int  j = i-1, k;
			while(j < data.length() + rb){
                for(k = 0; k< i; k++,j++){
                    if(j < data.length() + rb){
                        if(result[j] == '1'){
                            count++;
                        }
                    }
                }
                j = j + i;
            }
			if(count %2 == 0){
				return '0';
			}
			else if(count%2 != 0){
				return '1';
			}
		}
		string mul_Z(int ke){
        	string s = "";
        	for(int i = 0;i<ke;i++){
        		s += "0";
			}
			return s;
		}
		int Error_pos(){
			int ep = 0;
			for(int i = 0; i < rb; i++){
				ep += pow(2,i)*(check[i] - 48);
			}
			return (ep);
		}
		void receiver(){
			reverse();
			check = "";
			int i = 0;
        	while(i < rb){
        		check += parity_bit(pow(2,i));i++;
			}
			if(check == mul_Z(rb)){
				cout<<"No Error in received data..\n";
			}
			else{
				int pos = Error_pos();
				cout<<"Error is detected at position : "<<(result.length()+1)-pos<<endl;
				if(result[pos-1] == '1'){
					result[pos-1] = '0';
				}
				else if(result[pos-1] == '0'){
					result[pos-1] = '1';
				}
			}
		}
};
int main(){
	char ch = 'y';
	while(ch == 'y'||ch == 'Y'){
		Q2 obj;
		obj.input();
		cout<<"\nDataWord : "<<obj.data<<endl;
		obj.sender();
		cout<<"Number of redundant bits : "<<obj.rb<<endl;
		obj.reverse();
		cout<<"Data sent to receiver side : "<<obj.result<<endl;
		obj.receiver();
		int a = rand() % obj.result.length();
		cout<<">>>>>>><<<<<<<\n";
		cout<<"Changing the data of receiver side...\n";
		if(obj.result[a] == '1'){
			obj.result[a] = '0';
		}
		else if(obj.result[a] == '0'){
			obj.result[a] = '1';
		}
		obj.reverse();
		cout<<"New Data at receiver side : "<<obj.result<<endl;
		obj.receiver();
		obj.reverse();
		cout<<"After correcting Error bit : "<<obj.result<<endl;
		cout<<"Do you want to continue?(y/n) : ";
		cin>>ch;
	}
    getch();
	return 0;
}
