/*ZJU 1535 Lucky Ticket
2004.04.20 By adai
00:00.00 432K*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char input[21],temp[21],num[21];
	long n,sum[2],i,j,dif;
	while(cin>>input){
		strcpy(temp,input);
		n=strlen(input)/2;
		sum[0]=sum[1]=0;
		for(i=0;i<n;i++) sum[0]+=input[i]-'0';
		j=2*n;
		for(;i<j;i++) sum[1]+=input[i]-'0';
		i=2*n-1;
		while(sum[1]>sum[0]){
			sum[1]-=temp[i]-'0';
			temp[i]='0';
			j=i-1;
			while(temp[j]=='9'&&j>=n){
				sum[1]-=9;
				temp[j]='0';
				j--;
			}
			if(j==n-1){
				while(temp[j]=='9'){
					sum[0]-=9;
					temp[j]='0';
					j--;
				}
				temp[j]+=1;
				sum[0]++;
			}
			else{
				temp[j]+=1;
				sum[1]++;
			}
			i--;
		}
		dif=sum[0]-sum[1];
		i=2*n-1;
		while(1){
			if('9'-temp[i]>=dif){
				temp[i]+=dif;
				break;
			}
			else{
				dif-='9'-temp[i];
				temp[i]='9';
			}
			i--;
		}
		for(i=0;i<20;i++) num[i]='0';
		long carry(0);
		for(i=2*n-1;i>=0;i--){
			j=temp[i]-carry-input[i];
			if(j<0){
				num[i]=10+j+'0';
				carry=1;
			}
			else{
				num[i]=j+'0';
				carry=0;
			}
		}
		//printf("%I64d\n",num);
		//cout<<num<<endl;
		j=2*n;
		for(i=0;i<j-1;i++){
			if(num[i]!='0') break;
		}
		for(;i<j;i++) cout<<num[i];
		cout<<endl;
	}
	return 0;
}

