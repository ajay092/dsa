#include <iostream>
#include <cmath>
#include <vector>

#define INF (unsigned)!((int)0)

using namespace std;

double median_1(vector<int> &A, vector<int> &B);
double median_2(vector<int> &A, vector<int> &B);

int main(){
	vector<int> A = {23, 26, 33, 35};
	vector<int> B = {3, 5, 7, 9, 11, 16};
	
// 	double med = median_1(A, B);
	double med2 = median_2(A, B);
	cout<<med2<<endl;
	
	double med1 = median_1(A, B);
	cout<<med1<<endl;
	return 0;
}

double median_1(vector<int> &A, vector<int> &B){
	vector<int> AB;
	auto itrA = A.begin(), itrB = B.begin();
	
	while(itrA!=A.end()&&itrB!=B.end()){
		
		if(*itrA == *itrB){
			AB.push_back(*itrA);
			AB.push_back(*itrB);
			itrA++;
			itrB++;
		}else if(*itrA < *itrB){
			AB.push_back(*itrA);
// 			cout<<"pushing from A "<<*itrA<<endl;
			itrA++;
		}else if (*itrA > *itrB){
			AB.push_back(*itrB);
// 			cout<<"pushing from B "<<*itrB<<endl;
			itrB++;
		}
	}
	while(itrA < A.end()){
		AB.push_back(*itrA);
// 		cout<<"pushing from A "<<*itrA<<endl;
		itrA++;
	}
	
	while(itrB < B.end()){
		AB.push_back(*itrB);
// 		cout<<"pushing from B "<<*itrB<<endl;
		itrB++;
	}
	
	int n = AB.size();
// 	cout<<n<<endl;
	if(n != A.size() + B.size())
		cout<<"Error: Total no of elements in merged array is not equal to total elements\n";
	
	if(n%2==1)
		return AB[n/2];
	else return 0.5*(AB[n/2-1] + AB[n/2]);
}

double median_2(vector<int> &A, vector<int> &B){
	int lenA = A.size();
	int lenB = B.size();
	if(lenB < lenA)
		median_2(B, A);
	int left = 0, right = lenB;
	while(left <= right){
		int parX = (left+right)/2;
		int parY = (lenA + lenB + 1)/2 - parX;
		
		int LX = (parX == 0)? -INF : A[parX-1];
		int RX = (parX == lenA)? +INF :A[parX];
		
		int LY = (parY == 0)? -INF : B[parY-1];
		int RY = (parY == lenA)? +INF : B[parY];
		
// 		cout<<parX<<" "<<parY<<endl;
		
		if(LX <= RY && LY <= RX){
			if((lenA+lenB)%2 == 1)
				return (LX>=LY)? LX : LY;
			else{
				return 0.5*((LX>=LY)? LX : LY) + 0.5*((RX<=RY)? RX : RY);
			}
		}else if(LX > RY){
			right = parX-1;
		}else{
			left = parX+1;
		}
	}
	cout<<"Error in input\n";
}