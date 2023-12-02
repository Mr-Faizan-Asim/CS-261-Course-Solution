#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<chrono> // used to measure the time period
#include<fstream>
using namespace std;

// Priority Queue
void taskOne()
{
	priority_queue<int> PQ;
	PQ.push(12);
	PQ.push(14);
	PQ.push(11);
	PQ.push(24);
	PQ.push(89);
	PQ.push(11);

	while(!PQ.empty())
	{
		cout<<PQ.top()<<endl;
		PQ.pop();
	}
}
class Compare{
	public:
	bool operator()(int &a,int &b)
	{
		return a>=b;
	}
};
// heap sort
void heapSort()
{
	priority_queue<int,vector<int>,Compare> temp;
	for(int i = 0 ; i < 5 ; i ++)
	{
		// generate random number between 1 to 100
		temp.push(rand() % 100 +1);
	}
	while(!temp.empty())
	{
		cout<<temp.top()<<endl;
		temp.pop();
	}
}

// bubllbe sort 
void BubbleSort(vector<int>& V)
{
	int size = V.size();
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = 0 ; j < size - i ; j++)
		{
			if(V[j] > V[j + 1])
			{
				swap(V[j],V[j+1]);
			}
		}
	}
}
// Selection Sort
void selectionSort(std::vector<int>& V) {
    int size = V.size();
    for (int i = 0; i < size - 1; i++) {  
		  int index = i;
        for (int j = i + 1; j < size; j++) {  
            if (V[j] < V[index]) {
                index = j;
            }
        }
        std::swap(V[i], V[index]);
    }
}
// Partition
int Partition(vector<int>& V,int left,int right,int pi)
{
	int piviot = V[pi];
	int i = left - 1;

}
// Quick Sort (Kazim ka style sa kia ha)
void QuickSort(vector<int> &V,int si,int ei)
{
	if(si >= ei)
		return;

	int piviot = V[ei];
	int i = si - 1;
	for(int j = ei; j < ei ; j++)
	{
		if(V[j] < piviot)
		{
			i++;
			swap(V[i],V[j]);
		}
	}
	swap(V[i+1],V[ei]);

	QuickSort(V,si,i);
	QuickSort(V,i+2,ei);
}
// create file
void CreateFile(int size)
{
	fstream file("data.txt",ios::out);
	for(int i = 0 ; i < size; i++)
	{
		file << (rand() %100+1)<<" ";
	}
	file.close();
}
// read file 
void readData(vector<int> &temp)
{
	fstream file("data.txt",ios::in);
	int data;
	while(file>>data)
	{
		temp.push_back(data);
	}
	file.close();

}
int main()
{
	
	vector<int> temp;
	//CreateFile(1000);
	readData(temp);
	auto begin = chrono::high_resolution_clock::now();
	selectionSort(temp);
	auto end = chrono::high_resolution_clock::now();
	//auto set the data type automatically
	auto duration = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "Time taken: " << duration.count() << " microseconds" << std::endl;



	//taskOne();
	//heapSort();
	//BubbleSort(temp);
}