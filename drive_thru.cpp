#include<iostream>
using namespace std;

#define MAX 4
string plat[MAX];

int front = -1;
int rear = -1;

bool isEmpty(){
	return (front == -1 || front>rear);
}

bool isFull(){
	return (rear == MAX -1);
	
}

//tambahin mobil ke antrian
void enqueue(string platNomor){
	if (isFull()){
		cout<<"Jalur Drive-Thru Penuh! Mobil "<<platNomor<<" tidak bisa masuk.\n";
	}
	else {
		if(isEmpty()) front = 0;
		rear++;
		plat[rear]=platNomor;
		cout<<"Mobil dengan plat "<<platNomor<<" berhasil masuk antrian.";
	}
	cout<<endl;
}

//layanin mobil
void dequeue(){
	if (isEmpty()){
		cout<<"Jalur kosong! Tidak ada mobil yang bisa di layani.\n";
	}
	else{
		cout<<"Melayani pesanan mobil plat "<<plat[front]<<endl;
		front++;
	}
	cout<<endl;
}

void display(){
	if (isEmpty()){
		cout<<"Jalur antrian kosong!.\n";
	}
	else {
		cout<<"\n=== Daftar Antrian Mobil Saat ini ===\n";
		for (int i=front;i<=rear;i++){
			cout<<i+1<<". "<<plat[i]<<endl;
		}
		cout<<"====================\n";
	}
	cout<<endl;
}

int main(){
	cout<<"\n--- SIMULASI DRIVE-THRUE DIMULAI ---\n";
	enqueue("B 1234 ABC");
	enqueue("D 5678 EFG");
	enqueue("L 9012 HIJ");
	enqueue("N 3456 KLM");
	display();
	enqueue("A 7890 XYZ");
	dequeue();
	dequeue();
	display();
	dequeue();
	dequeue();
	
	cout<<"\n--- SIMULASI SELESAI ---\n";
	
}
