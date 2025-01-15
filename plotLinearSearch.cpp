#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& array, int key) {
	int n = array.size(), i = 0;
	
	while (i < n) {
		if (array[i] == key) break;
		i++;
	}
	
	return i + 1;
}

vector<float> getComparisons(const vector<int>& array) {
	int n = array.size();
	vector<float> result(3, 0);	//low, avg, high
	result[0] = INT_MAX;
	
	for (int i = 0; i <= n; i++) {
		int comp = linearSearch(array, i);
		if (comp < result[0]) result[0] = comp;
		if (comp > result[2]) result[2] = comp;
		result[1] += comp;
	}
	
	result[1] /= n + 1;
	return result;
}

vector<int> makeVector(int size) {
	vector<int> array(size);
	for (int i = 0; i < size; i++) array[i] = i;
	return array;
}

void plot(vector<float> comp) {
	char shape[] = {'*', '#', '+'};
	int j = 1;
	for (int i = 0; i < 3; i++) {
		while (j < comp[i]) {
			cout << " ";
			j++;
		}
		cout<<shape[i];
		j++;
	}
}

void drawXAxis(int max, string label) {
	cout<<"\n   +";
	for(int i = 1; i <= max; i++) cout<<"-";
	cout<<"\n   0";
	for(int i = 0; i < max; i+=10) cout << "         |";
	cout<<"\n    ";
	for(int i = 10; i <= max; i+=10) cout << "        "<<i;
	cout<<endl;
	for (int i = 0; i < max/2; i++) cout << " ";
	cout<<label;
}

int main() {
	cout<<"Label->     * - Low,     # - Average,     + - High"<<endl;
	cout << "\nInput Size"<<endl;
	for (int size = 10; size < 100; size += 5) {
		cout << "\n"<<size << " |";
		vector<int> array = makeVector(size);
		vector<float> comp = getComparisons(array);
		plot(comp);
		cout<< "\n   |";
	}
	drawXAxis(100, "Number of comparisons");
	return 0;
}
