#include<iostream>
#include<windows.h>
using namespace std;

long long int fibonacci[1000];

long long int fibonacci_dinamico(int n){
	
	if(fibonacci[n] != -1)
		return fibonacci[n];
	
	if(n == 1 || n == 0)
		return n;
	
	fibonacci[n] = fibonacci_dinamico(n-1) + fibonacci_dinamico(n-2);
	Sleep(100);
	return fibonacci[n];
	
}

long long int fibonacci_rec(int n){
	
	if(n == 1 || n == 0)
		return n;
	
	return fibonacci_rec(n-1) + fibonacci_rec(n-2);
	
}

long long int fibonacci_iterativo(int n){	
		
	long long int numeroAntiAnterior, numeroAnterior = 0, numeroAtual = 1;

    for (int i = 1; i < n ; i++) {

        numeroAntiAnterior = numeroAnterior;

        numeroAnterior = numeroAtual;

        numeroAtual = numeroAntiAnterior + numeroAnterior;
        Sleep(100);
        

    }
	return numeroAtual;
}

int main(){
	for(int i=0;i<1000;i++){
		fibonacci[i] = -1;
	}
	
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
	cout<<fibonacci_iterativo(50)<<endl;
	
	cout<<fibonacci_rec(50)<<endl;
	
	cout<<fibonacci_dinamico(50)<<endl;
	
	return 0;
} 
