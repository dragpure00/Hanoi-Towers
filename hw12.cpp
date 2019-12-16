#include <iostream>
#include <vector>
using namespace std;
vector <int> t[3];//create 3 towers as vectors
	int n, candidate, to,from, move=0;//from is current tower, to is next tower,move counts number of moving
void odd(){//function for odd number of rings
	if(t[(to+1)%3].back()<t[(to+2)%3].back()){
		from=(to+1)%3;
	}
	else{
		from=(to+2)%3;
	}
	if(t[(from)].back()<t[(from+1)%3].back()){//getting the next to tower
		to=(from+1)%3;
		
	}
	else{
		to=(from+2)%3;
	}
}

void even(){//function for even number of rings
	if(t[(to+1)%3].back()<t[(to+2)%3].back()){
		from=(to+1)%3;
	}
	else{
		from=(to+2)%3;
	}
	if(t[(from)].back()<t[(from+2)%3].back()){//getting the next to tower
		to=(from+2)%3;
		
	}
	else{
		to=(from+1)%3;
	}	
	
}

int main(){

	
	cout <<"Enter  number of rings to move: ";
	cin >>n;
	cout <<endl;
	
	
	
	for(int i=n+1;i>=1;i--){//initialize the three towers (A,B,C)
		t[0].push_back(i);}
		t[1].push_back(n+1);
		t[2].push_back(n+1);
	
	from = 0;
	if(n%2==0){
		to=2;
	}
	else{
	
	to=1;
}
	candidate=1;
	while(t[1].size()<n+1){
		t[to].push_back(t[from].back());// adding the ring from the from tower to the to tower
		t[from].pop_back();//removing the rings from the from tower
		cout <<"move number "<<++move<<": Transfer ring " << candidate << " from tower " 
		<<char(from+65)<<" to tower "<<char(to+65)<<endl;
if(n%2==1){//if n is a odd number call the function odd
	odd();
candidate=t[from].back();//refering to the current top of the from tower
}		
else{
	even();
	 candidate=(t[from].back());//refering to the current top of the from tower
}

}
return 0;


}



