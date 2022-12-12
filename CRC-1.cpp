#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

// Returns XOR of 'a' and 'b'
// (both of same length)
string xor1(string a, string b)
{
	
	// Initialize result
	string result = "";
	
	int n = b.length();
	
	// Traverse all bits, if bits are
	// same, then XOR is 0, else 1
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

// Performs Modulo-2 division
string mod2div(string divident, string divisor)
{
	int pick = divisor.length();
	string tmp = divident.substr(0, pick);
	int n = divident.length();
	while (pick < n)
	{
		if (tmp[0] == '1')
			tmp = xor1(divisor, tmp) + divident[pick];
		else
			tmp = xor1(std::string(pick, '0'), tmp) +
				divident[pick];
		pick += 1;
	}
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);
	return tmp;
}
string* encodeData(string data, string key)
{
	int l_key = key.length();
	
	// Appends n-1 zeroes at end of data
	string appended_data = (data + std::string(l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
	
	// Append remainder in the original data
	string *codeword=new string[2];
    codeword[0]=data;
    codeword[1]=remainder; 
    return codeword;
}
// Perform receiver side operation
void receiver(string msg,string gnt)
{
    cout<<"Reciever Side................................................."<<endl;
    cout<<"Message recieved"<<endl;
    cout<<"Recieved message: "<<msg<<endl;
    cout<<"Checking the message.........................................."<<endl;
    cout<<".............................................................."<<endl;
    string remainder=mod2div(msg,gnt);
    int i=0;
	bool flag=true;
    while(i<remainder.length())
    {
        if(remainder[i]=='1')
        {
            flag=false;
			break;
        }
		i++;
    }
	if(flag){
		cout<<"Message is correct"<<endl;
		return;
	}
	cout<<"Message is incorrect"<<endl;
	return;

}
// Perform Sender side Operation
void sender(string msg,string gnt)
{
    cout<<"Sender Side..................................................."<<endl;
    int position=0;
    string *encodedmsg=encodeData(msg,gnt);
    string transmittingmsg=encodedmsg[0]+encodedmsg[1];
    cout<<"Encoded message after applying CRC: "<<transmittingmsg<<endl;
    do{
		if(position>=transmittingmsg.length())
		{
			cout<<"Enter a valid position................................"<<endl;
		}
		cout<<"Enter the bit you want to add error(Enter -1 if don't want to enter error)";
		cin>>position;
		if(position!=-1){
			if(transmittingmsg[position-1]=='1')
			{
				transmittingmsg[position-1]='0';
			}
			else{
				transmittingmsg[position-1]='1';
			}
		}
		else{
			break;
		}
    }while(position>=transmittingmsg.length());
    cout<<"Message to be transmitted"<<transmittingmsg<<endl;
    cout<<"Transmitting the message......................................"<<endl;
	receiver(transmittingmsg,gnt);
}
// Driver code
int main()
{
	string message;
    cout<<"Enter the message: ";cin>>message;
    string generator;
    do{
        cout<<"Enter the Generator: ";cin>>generator;
        if(generator[0]=='0' || generator[generator.length()-1]=='0' )
        {
            cout<<"Wrong generator input. Enter again......."<<endl;
        }
    }
    while(generator[0]=='0' || generator[generator.length()-1]=='0' );	
	sender(message,generator);
	getch();
	return 0;
	
}

