#include "minheap.hpp"
#include <stdio.h>
#include <iostream>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

MinHeap::MinHeap(int size) {
	heap_size = 0;
	capacity = size;
	harr = new int[size];
}
MinHeap::~MinHeap() {
  delete[] harr;
}

int MinHeap::left(int parent) {
  int i = parent*2 +1;
  return (i < heap_size) ? i: -1;
}

int MinHeap::right(int parent) {
  int i= parent*2 + 2;
  return (i < heap_size) ? i:-1;
}

int MinHeap::parent(int child) {
  if (child != 0) {
    int i = (child - 1) >> 1;
    return i;
  }
  return -1;
}

int MinHeap::size() { return heap_size; }

void MinHeap::insert(int element) {
  //check the heap is full or not 
  if (heap_size == capacity){
    cout<< "Overflow: Could not insert "<<element<<std::endl;
    return;
  }

  //insert new key in at the end of the queue
  harr[heap_size++] = element;
  int i = heap_size - 1;
  //mantain min heap property 
  while (i != 0 && harr[parent(i)] > harr[i]){
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }

}

int MinHeap::extractMin() {
  if (heap_size <= 0){
    return INT_MAX;
  }
  if (heap_size == 1){
    heap_size --;
    return harr[0];
  }

  //store minimum and remove from the heap 
  int root = harr[0];
  harr[0] = harr[--heap_size];
  MinHeapify(0);

  return root;
}

void MinHeap::MinHeapify(int i){
  int l = left(i);
  int r = right(i);
  int least = i;
  if (l < heap_size && harr[l] < harr[i]){
    least = l;
  }
  if (r < heap_size && harr[r] < harr[least]){
    least = r;
  }
  if (least != i){
    swap (&harr[i], &harr[least]);
    MinHeapify(least);
  }

}

void MinHeap::display() {
  cout<<"MinHeap:- ";
  cout << heap_size << endl;
  for(int i = 0; i < heap_size; i++){
	cout << harr[i] << " ";
  }
  cout << endl;
}

/* non efficient one using insert to build the heap and extractmin to delete the root one by one 
void MinHeap::heapsort(vector<int>& A,int n) {
  //create a heap by inserting elements
  for (int i = 0; i < n; i++){
    insert(A[i]);
  }
  //delete elements from heap
  for  (int i = heap_size - 1; i >= 0; i--){
    A[i] = extractMin();
  }
  
}
*/

void MinHeap::heapsort(vector<int>& A, int n){
  heap_size = n;
  // Build the heap using MinHeapify
  for (int i = n / 2 - 1; i >= 0; i--) {
    MinHeapify(i);
  }
  // Extract the minimum element one by one and store in A in descending order
  for (int i = n - 1; i >= 0; i--) {
    A[i] = harr[0];
    swap(&harr[0], &harr[i]);
    heap_size--;
    MinHeapify(0);
  }
}