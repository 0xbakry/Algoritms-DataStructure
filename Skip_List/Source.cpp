#include "SkipList.cpp"
using namespace std;

int main()
{
	int layer=0;
	int key;
	SkipList s(4, 0.5);
	s.insert(3);
	s.insert(54);
	s.insert(144);
	s.insert(0);
	s.insert(1);
	s.insert(13);
	s.insert(11);
	s.insert(47);
	s.insert(15);
	s.insert(100);
	s.insert(154);
	s.insert(10);
	s.insert(10);

	s.print();

	cout << "Number of layers is: " << s.getLayers() << endl;

	cout << "Enter the key you're searching for" << endl;
	cin >> key;
	cout << "Jumps: " << s.search(key) << endl;

	cout << "Enter level number" << endl;
	cin >> layer;
	cout << "Elements of layer "<<layer <<" :  "; s.printLayer(layer); cout<<'n/';
	system("pause");
}