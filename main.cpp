#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int A[N];

// void mergeSort(int A[],int B[], int C[], int m, int n)  //CWH CODE
// {
// 	int i,j,k;
// 	i=j=k=0;

// 	while(i<m && j<n)
// 	{
// 		if(A[i]<B[j])
// 		{
// 			C[k] = A[i];
// 			i++;
// 			k++;
// 		}
// 		else
// 		{
// 			C[k] = B[j];
// 			j++;
// 			k++;
// 		}
// 	}

// 	while(i<m)
// 	{
// 		C[k] = A[i];
// 		i++;
// 		k++;
// 	}
// 	while(j<n)
// 	{
// 		C[k] = B[j];
// 		j++;
// 		k++;
// 	}
	
// 	for(int m=0; m<k; m++)
// 	{
// 		cout << C[m] <<endl;
// 	}
	
// }

void merge(int l, int r, int mid)		//LUV CODE
{
	int l_sz = mid - l + 1;
	int r_sz = r - mid;
	int L[l_sz+1];
	int R[r_sz];

	for(int i=0 ;i<l_sz;i++)
	{
		L[i] = A[i+l];
	}

	for(int i=0 ;i<r_sz;i++)
	{
		R[i] = A[i+mid +1];
	}

	L[l_sz] = R[r_sz] = INT_MAX;

	int l_i = 0;
	int r_i = 0;
	for(int i=l ; i<r; i++)
	{
		if(L[l_i]<R[r_i])
		{
			A[l] = L[l_i];
			l_i++;
		}
		else
		{
			A[l] = R[r_sz];
			r_i++;
		}
	}


}

void mergeSort(int l,int r)
{
	if(l==r) return;
	int mid = (l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	merge(l,r,mid);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    // int A[n];
    cin >> n;
    while(n--)
    {
    	cin >> A[n-1];
    }

     while(n--)
    {
    	cout << A[n] <<endl;
    }

    mergeSort(0,n-1);



}