#include <iostream>

 

using namespace std;

 

void bid(int);

 

int main(){

int num;

cout<<"Bidding is open now !!\n";

cout<<"Enter the number of tenders:";

cin>>num;

bid(num);

return 0;

}

 

void bid(int num){

int i,reg_no[50];

float quot[50];

 

for(i=0;i<num;i++){

cout<<"\nPlease mention your registration no: ";

cin>>reg_no[i];

cout<<"\nHow much is your quotation: ";

cin>>quot[i];

}

 

cout<<"\n The bidders are\n";

for(i=0;i<num;i++){

cout<<reg_no[i]<<"\n";

}

float min=quot[0];

int reg=reg_no[0];

int count=0;

 

for (i=0;i<num;i++){

if (quot[i] < min){

min = quot[i];

reg=reg_no[i];

}

else if (min==quot[i]){

count++;

}

}

if(count==1){

cout<<"\nCongratulations bidder no. "<<reg<<" Your quote of Rs."<<min<<" is the minimum.Your tender is selected.\n";

}

else{

cout<<"\n Rebidding required! There are "<<count<<" bidders with same quotations ";

cout<<"\nThe bidders having a quote of Rs "<<min<<" .Enter your quote again with the same registration number";

bid(count);

}

}
