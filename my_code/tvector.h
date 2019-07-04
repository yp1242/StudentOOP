#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>
class MyVec {
public:
	class Iterator {
		/*
		 * This class supports ranged for loops.
		 * It includes:
		 * Iterator(int*)
		 * operator++
		 * operator*
		 * operator!=
		 * */
	public:
		friend bool operator!=(Iterator& rhs, Iterator& lhs) {
			T* a = (rhs.iptr);
			T* b = (lhs.iptr);
			return a != b;
		}
		Iterator(T* ip) : iptr(ip) {}

		Iterator& operator++() {
			iptr++;
			return *this;
		}

		T operator*() {
			return *iptr;
		}

	private:
		T* iptr;
	};

	MyVec() :sz(0) {
		capacity = DEF_CAPACITY;
		data = new T[DEF_CAPACITY];
	}

	MyVec(int sz, T val = 0) : sz{ sz } {
		capacity = sz;
		data = new T[capacity];
		for (int i = 0;i < sz;i++) {
			data[i] = val;
		}
	}

	// copy control:
	MyVec(const MyVec& v2) {
		copy(v2);
	}
	~MyVec() {
		delete[] data;
	}
	MyVec& operator=(const MyVec& v2) {
		if (this != &v2) {
			delete[] data;
			copy(v2);
		}
		return *this;
	}
	/*
     * Puts an element at the back of a vector.
     * */
	void push_back(int val) {
		sz++;
		if (sz > capacity) {
			std::cout << "Increasing capacity\n";
			int* old_data = data;
			data = new int[capacity * CAPACITY_MULT];
			for (int i = 0; i < sz; i++) {
				data[i] = old_data[i];
			}
			capacity *= CAPACITY_MULT;
			delete[] old_data;
		}
		data[sz - 1] = val;
	}
	int size() const { return sz; }
	/*
     * this [] is for reading items from the MyVec:
     * It returns the i-th element.
     * */
	T operator[](int i) const {
		return data[i];
	}
	/*
     * this [] allows write access to items in the MyVec:
     * It returns a reference to the i-th element.
     * */
	T& operator[](int i) {
		return data[i];
	}

	//include left hand & not include right hand
	Iterator begin() const {
		return MyVec<T>::Iterator(data);
	}
	Iterator end() const {
		return MyVec<T>::Iterator(data + sz);
	}

private:
	void copy(const MyVec& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}
	T* data;
	int sz;
	int capacity;
};

//Note: Range for for a vectr needs 'operator++', 'operator*' and 'operator!='
template <typename T>
void print_vector(const MyVec<T>& v) {
	for (T i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
};

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	bool check = true;
	if (v1.size() == v2.size()) {
		for (int i = 0;i < v1.size();i++) {
			if (v1[i] != v2[i]) {
				check = false;
			}
		}
	}
	else {
		check = false;
	}
	return check;
}

#endif
