#include <iostream>

using namespace std;

template<typename T>
T gcd(T a, T b){
	return a ? gcd(b%a, a): b;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}