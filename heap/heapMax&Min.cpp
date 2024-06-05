
int parent(int i) {
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int rigth(int i) {
	return 2 * i + 2;
}

void maxHeapify(int A[], int n, int i) {
	int l = left(i);
	int r = rigth(i);
	int largest(0);
	if (l <= (n - 1) && A[l] > A[i]) {
		largest = l;
	}else
		largest = i;
	if (r <= (n - 1) && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(A, n, largest);
	}
}
void minHeapify(int A[], int n, int i) {
	int l = left(i);
	int r = rigth(i);
	int smallest = i;
	if (l < n && A[l] < A[i]) {
		smallest = l;
	}
	if (r < n && A[r] < A[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		swap(A[i], A[smallest]);
		minHeapify(A, n, smallest);
	}
}
void buildMaxHeap(int A[], int n) {
	for (int i = n / 2 - 1;i >= 0;--i) {
		maxHeapify(A, n, i);
	}
}
void buildMinHeap(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		minHeapify(A, n, i);
	}
}
void print(int A[], int n) {
	for (int i = 0;i < n;++i) {
		cout << A[i] << " ";
		//cout << endl;
	}
}

//aplicación de ordenamiento
void heapsortMax(int A[], int n) {
	buildMaxHeap(A, n);
	for (int i = n - 1;i > 0;--i) {
		swap(A[0], A[i]);
		maxHeapify(A, --n, 0);
	}
}

void heapsortMin(int A[], int n) {
	buildMinHeap(A, n);
	for (int i = n - 1; i > 0; --i) {
		swap(A[0], A[i]);
		minHeapify(A, --n, 0);
	}
}

