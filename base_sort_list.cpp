#include <iostream>
#include <iterator>
#include <cstdlib>
#include <string>

using namespace std;

template<typename T>
struct node{
	T value;
	node *nextEl, *prvEl;
};

template<class T>
class doubList{
	public:
		doubList():Head(NULL),Tail(NULL){};
		~doubList(){
			while(Head){
				Tail = Head->nextEl;
				delete Head;
				Head = Tail;
			}
		}
		void Add(int value)
		{
			node<T> *temp = new node<T>;
			temp->nextEl = NULL;
			temp->value = value;
			if(Head){
				temp->prvEl = Tail;
				Tail->nextEl = temp;
				Tail = temp;
			}
			else{
				temp->prvEl = NULL;
				Head = Tail = temp;
			}
		}
		
		void Del(int num)
		{
			try{
				node<T> *iter;
				iter = Head;
				for(int i = 0; i < num; i++)
					if(iter->nextEl) 
						iter = iter->nextEl;
					else
						throw 5;
				if(iter->nextEl != NULL){
					(iter->nextEl)->prvEl = iter->prvEl;
					(iter->prvEl)->nextEl = iter->nextEl;	
				}
				if(iter == Tail) Tail = iter->prvEl;
				if(iter == Head) Head = iter->nextEl;
				delete iter;
			}
			catch(int x){
				cout << "No element at this number\n";
			}

		}
		
		void operator[](int x)
		{
			node<T> *iter;
			if(x < 0){
				iter = Tail;
				while(iter){
					cout << iter->value << ' ';
					iter = iter->prvEl;
				}
				cout << "\n";
			}
			else{
				iter = Head;
				while(iter){
					cout << iter->value << " ";
					iter = iter->nextEl;
				}
				cout << "\n";
			}
		}
	private:
		node<T> *Head, *Tail;
};
 
 


template<class In, class Out>
void my_copy(In first, In last, Out ch_first){
	while (first != last) {
		*ch_first++ = *first++;
	}
}

template<class In, class Out>
void my_merge(In A_beg, In A_end, In B_beg, In B_end, Out C){
	while(A_beg != A_end) {
		if(B_beg == B_end){
			my_copy(A_beg, A_end, C);
			return;
		}
		if(*B_beg < *A_beg){
			*C = *B_beg;
			++B_beg;
		}
		else{
			*C = *A_beg;
			++A_beg;
		}
		C++;
	}
	my_copy(B_beg, B_end, C);
}

template<typename Arr, typename Elem>
void merge_sort(Arr first, Arr last, Elem tmp){
	size_t n = last - first, x = n/2, k = n - x;
	if(n <= 1) return;
	Elem * A = new Elem[x];
	Elem * B = new Elem[k];
	for(int i = 0; i < x; i++)
		A[i] = *(first+i);
	for(int i = 0; i < k; i++)
		B[i] = *(first+x+i);
	merge_sort(A, A + x, A[0]);
	merge_sort(B, B + k, B[0]);
	my_merge(A, A + x, B, B + k, first);
}

template<typename T>
void arr_output(T beg, T end){
	my_copy(beg, end, ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<typename T>
void arr_init(T beg, int size, int mod = 1000){
	for(int i = 0; i < size; i++)
		*(beg+i) = rand()%mod;
}

void dList_init(doubList<int> & a, int size, int mod = 100){
	for(int i = 0; i < size; i++)
		a.Add(rand()%mod);
}

string another_system(int x, int base = 2){
	try{
		if(base < 2 or base > 10) throw 1;
		string s;
		while(x >= base){
			s = char('0'+x%base) + s;
			x /= base;
		}
		s = char('0'+x)+s;
		return s;
	}
	catch(int x){
		cout << "Uncorrect base " << x << '\n';
	}
}

int main(){
	doubList<int> A;
	dList_init(A, 20);
	cout << another_system(16, 3) << '\n';
	A[2];
	A.Del(10);
	A[-2];
	int arr_size = 20;
	int * a = new int[arr_size];
	arr_init(a, arr_size);
	arr_output(a, a+arr_size);
	merge_sort(a, a+arr_size, a[0]);
	arr_output(a, a+arr_size);
	return 0;
}