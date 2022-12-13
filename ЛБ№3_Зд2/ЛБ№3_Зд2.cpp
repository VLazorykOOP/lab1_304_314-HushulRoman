

#include <iostream>
#include <complex>

using namespace std;

class VectorOfUnsignedInt {
public:
	VectorOfUnsignedInt() : size(1), data(new unsigned int[size]()) {}
	VectorOfUnsignedInt(size_t size) : size(size), data(new unsigned int[size]) {
		for (size_t i = 0; i < size; i++) {
			data[i] = i;
		}
	}
	VectorOfUnsignedInt(int size, unsigned int initializer) : size(size),
		data(new unsigned int[size]) {
		setAllTo(initializer);
	}
	VectorOfUnsignedInt(const VectorOfUnsignedInt& other) {
		copyFrom(other);
	}
	virtual ~VectorOfUnsignedInt(){
		delete[] data;
	}
	unsigned int& get(size_t position) {
		if (position >= size) {
			throw out_of_range("Index out of range");
		}
		return data[position];
	}
	const unsigned int& get(size_t position) const {
		if (position >= size) {
			throw out_of_range("Index out of range");
		}
		return data[position];
	}
	void set(size_t position) {
		if (position >= size) {
			throw out_of_range("Index out of range");
		}
		data[position] = 0;
	}
	void set(size_t position, unsigned int value) {
		if (position >= size) {
			throw out_of_range("Index out of range");
		}
		data[position] = value;
	}
	size_t getSize() const { return size; }
	void setAllTo(unsigned int value) {
		for (size_t i = 0; i < size; i++) {
			data[i] = value;
		}
	}
	VectorOfUnsignedInt& copyFrom(const VectorOfUnsignedInt& other)
	{
		if (this != &other) {
			size = other.size;
			delete[] data;
			data = new unsigned int[size];
			for (size_t i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	static size_t getMaximumSize() { return static_cast<size_t>(-1); }
private: 
	size_t size;
	unsigned int* data;
};

ostream &operator<<(ostream &stream, const VectorOfUnsignedInt &v) {
	stream << "[";
	for (size_t i = 0; i < v.getSize(); i++) {
		stream << v.get(i);
		if (i < v.getSize() - 1) stream << ", ";
	}
	return stream << "]";
}

int main(int argc, char* argv[]) {
	VectorOfUnsignedInt v(30);
	v.set(25);
	v.set(5, 2);
	cout << v << endl;
	return 0;
}