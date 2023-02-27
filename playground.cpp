#include <bits/stdc++.h>
using namespace std;

struct MyStruct {
	int64_t a;
	int64_t b;
	
	bool operator < (const MyStruct &other) const {
		return a < other.a;
	}
	bool operator == (const MyStruct &other) const {
		return a == other.a;
	}
};

struct MyHasher  // for hashing `MyStruct`
{
    size_t operator()(const MyStruct& key) const {
		return hash<int64_t>() (key.a) ^ hash<int64_t>() (key.b);
	}
};



int main() {

	
	
}
