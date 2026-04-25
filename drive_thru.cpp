#include <iostream>
using namespace std;
#define MAX 4

//define si variable dan array
struct AntrianDriveThru {
    string plat[MAX];
    int front,rear;

//kosongin front dan rear
    AntrianDriveThru() {
        front=-1;
        rear =-1;
    }
// cek kosong
    bool isEmpty() {
        return(front==-1 ||front>rear);
    }
// cek penuh
    bool isFull() {
        return(rear==MAX-1);
    }

//tambah mobil
    void enqueue(string platNomor) {
        if (isFull()) {
            cout<<"Jalur Drive-Thru Penuh! Mobil "<<platNomor<<" tidak bisa masuk.\n";
        } else {
            if(front== -1)front = 0;
            rear++;
            plat[rear]=platNomor;
            cout<<"Mobil "<<platNomor<<" masuk antrian.\n";
        }
    }

//layanin mobil
    void dequeue() {
        if (isEmpty()) {
            cout<<"Jalur kosong, nggak ada mobil dilayani.\n";
        } else {
            cout<<"Melayani mobil plat "<<plat[front]<<endl;
            front++;
            if (front>rear){
                front=-1;
                rear=-1;
            }
        }
    }

//lihat antrian
    void display() {
        if (isEmpty()) {
            cout<<"Antrian kosong.\n";
        } else {
            cout<<"\n=== Daftar Mobil ===\n";
            for (int i =front;i<=rear;i++) {
                cout<<(i-front+1)<< ". "<< plat[i]<<endl;
            }
            cout<<"====================\n";
        }
    }
};

//program utama
int main() {
    cout<<"--- SIMULASI DRIVE THRU ---\n";

    AntrianDriveThru antri;
//tambahin 4 mobil
    antri.enqueue("B 1234 ABC");
    antri.enqueue("D 5678 EFG");
    antri.enqueue("L 9012 HIJ");
    antri.enqueue("N 3456 KLM");
//kasih lihat 4 mobil di atas
    antri.display();
//ngetes queue penuh
    antri.enqueue("A 7890 XYZ");
//layanin 2 mobil
    antri.dequeue();
    antri.dequeue();
//cek sisanya
    antri.display();
//layanin semua
    antri.dequeue();
    antri.dequeue();
//ngetes queue kosong
    antri.dequeue();

    cout << "\n--- SELESAI ---\n";
    return 0;
}
