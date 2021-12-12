#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int fs , f[20] , g[20] , gs , temp[20] , j , k ,crc[20] , tmf[20] , rem[20] ;

	//sender side
cout<<"\nEnter the frame size\n";
cin>>fs;

cout<<"\nEnter frame(0's and 1's only)\n";
for(int i=0;i<fs;i++)
{
	cin>>f[i];
}
cout<<endl;

cout<<"\nEnter the generator size(atleast 1 less than frame)\n";
cin>>gs;

cout<<"\nEnter generator(0's and 1's only)\n";
for(int i=0;i<gs;i++)
{
	cin>>g[i];
}
cout<<endl;

cout<<"\nSender side";
cout<<"\nFrame (message): ";
for(int i=0;i<fs;i++)
{
	cout<<f[i];
}
cout<<endl;

cout<<"\nGenerator: ";
for(int i=0;i<gs;i++)
{
	cout<<g[i];
}
cout<<endl;

int gss= gs-1;
cout<<"\n0's appended in frame: "<<gss;
for(int i=fs;i<fs+gss;i++)
f[i]=0;

for(int i=0;i<fs+gss;i++)
temp[i]=f[i];

cout<<"\nFrame after appending 0's: ";
for(int i=0;i<fs+gss;i++)
cout<<temp[i];


			//Division
for(int i=0;i<fs;i++)
	{
		k=i;
		j=0;
		if(temp[k]>g[j])
		{
		for(j=0,k=i;j<gs;j++,k++)
			{
				if(f[i]==1 && g[i]==1 || f[i]==0 && g[i]==0)
					temp[k]=0;
				else
					temp[k]=1;

			}
		}

	}


for(int i=0,j=fs;i<gss;i++,j++)
	crc[i]=temp[j];

cout<<"\nCRC bits: ";
for(int i=0;i<gss;i++)
	cout<<crc[i];

cout<<"\nTransmitted: ";
for(int i=0;i<fs;i++)
	tmf[i]=f[i];

for(int i=fs,j=0;i<fs+gss;i++,j++)
	tmf[i]=crc[j];

for(int i=0;i<fs+gss;i++)
	cout<<tmf[i];


cout<<"\n\nReciever side";
cout<<"\nReciever frame: ";
for(int i=0;i<fs+gss;i++)
	cout<<tmf[i];

for(int i=0;i<fs+gss;i++)
	temp[i]=tmf[i];

			//Division
for(int i=0;i<fs+gss;i++)
	{
		k=i;
		j=0;
		if(temp[k]>g[j])
		{
		for(j=0,k=i;j<gs;j++,k++)
			{
				if(f[i]==1 && g[i]==1 || f[i]==0 && g[i]==0)
					temp[k]=0;
				else
					temp[k]=1;

			}
		}

	}
	int flag=0;

	cout<<"\nRemainder: ";
	for(int i=fs,j=0;i<fs+gss;i++,j++)
			rem[j]=temp[i];


	for(int i=0;i<gss;i++)
			cout<<rem[i];

		for(int i=0;i<<gss;i++)
		{
			if(rem[i]!=0)
				flag=1;
		}

		if(flag==0)
			cout<<"\nSuccessful transmission of message\n";
		else
			cout<<"\nTransmission of message failed\n";






	return 0;
}