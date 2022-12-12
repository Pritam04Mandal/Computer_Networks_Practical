#include<bits/stdc++.h>
#include<ctime>
#define longint long long int
using namespace std;
void transmission(longint & i, longint & N, longint & tf, longint & tt) 
{
    while (i <= tf) 
    {
        int z = 0;
        for (int k = i; k < i + N && k <= tf; k++) 
        {
            cout << "\t\tSending Frame " << k << "..." << endl;
            tt++;
        }
        for (int k = i; k < i + N && k <= tf; k++) 
        {     
            int f = rand() % 2;
            if (!f) 
            {
                cout << "\t\tAcknowledgment for Frame " << k << "..." << endl;
                z++;
            } 
            else 
            {
                cout << "\t\tTimeout!! Frame Number : " << k << " Not Received" << endl;
                cout << "\t\tRetransmitting Window..." << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }
}
int main() {
    system("cls");
    cout<<"\t\t\tGo Back- N Sliding Window Protocol\t\t\t\n";
    longint tf, N, tt = 0;
    cout << "\tEnter the Total number of frames : ";
    cin >> tf;
    cout << "\tEnter the Window Size : ";
    cin >> N;
    longint i = 1;
    transmission(i, N, tf, tt);
    cout << "Total number of frames which were sent and resent are : " << tt <<
    endl;
    return 0;
}