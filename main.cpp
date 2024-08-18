#include<iostream>
#include<math.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 10
using namespace std;
int main(){
int i,j,k=0,m;
double oldu[n][n],newu[n][n],f[n][n];
double dt,dy,dx,a,eps,maxu;
int num;
dx=1.0/n; dy=1.0/n; dt=0.25*dx*dy/4; a=1.0; eps=0.05;
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		oldu[i][j]=20.0;
		newu[i][j]=20.0;
		f[i][j]=0.0;
		if (i==int(n/2) && j==int(n/2)) f[i][j]=1000.0;
	}
}
for(k=0;k<50000000;k++){
	for(i=0;i<n;i++){
		oldu[i][0]=oldu[i][1];
		newu[i][0]=newu[i][1];
		oldu[i][n-1]=oldu[i][n-2];
		newu[i][n-1]=newu[i][n-2];
	}
	for(j=0;j<n;j++){
		oldu[0][j]=oldu[1][j];
		newu[0][j]=newu[1][j];
		oldu[n-1][j]=oldu[n-2][j];
		newu[n-1][j]=newu[n-2][j];
	}
	for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			if(i<int(n/2)+1 && j<int(n/2)+1) a=0.0000687;
			else if(i>=int(n/2)+1 && j<int(n/2)+1) a=0.0000019;
			else if(i<int(n/2)+1 && j>=int(n/2)+1) a=0.0000019;
			else a=0.0000687;
				newu[i][j]=oldu[i][j] + dt * (a * a *((oldu[i+1][j]-2*oldu[i][j]+oldu[i-1][j])/dx/dx 
												   + (oldu[i][j+1]-2*oldu[i][j]+oldu[i][j-1])/dy/dy) + f[i][j]);
		}
	}
	for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			oldu[i][j]=newu[i][j];
		}
	}
	ofstream fout;
ofstream fout_txt("file.txt");
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		fout_txt<<newu[i][j]<<'\t';
	}
	fout_txt<<endl;
}
return 1;}
