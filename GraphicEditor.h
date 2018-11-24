#include <iostream>
#include <vector>
using namespace std;


/*��� �Է��� ���� ó���� ������� �ʾҴ�.*/

class Shape {
protected:
	int type;
public:
	Shape * next;
	int getType() {
		return type;
	}
};
class Line : public Shape {
public:
	Line() { type = 0; }
};
class Circle : public Shape {
public:
	Circle() { type = 1; }
};
class Rect : public Shape {
public:
	Rect() { type = 2; }
};


class UI {
public:
	static void printGraphic() { cout << "�׷��� �������Դϴ�." << endl; }
	static int selectMenu() {
		int inputVal;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> inputVal;
		return inputVal;
	}
	static int selectShape() {
		int inputVal;
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> inputVal;
		return inputVal;
	}
	static int selectDel() {
		int inputVal;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> inputVal;
		return inputVal;
	}
	static void printAll(Shape *Pstart, Shape *PLast) {
		Shape *cur = Pstart;
		for (int i = 0; cur != NULL; cur = cur->next, i++) {
			cout << i << ": ";
			switch (cur->getType()) {
			case 0:
				cout << "Line" << endl;
				break;
			case 1:
				cout << "Circle" << endl;
				break;
			case 2:
				cout << "Rect" << endl;
				break;
			default:
				break;
			}
		}
	}
};

class GraphicEditor {
private:
	Shape *pStart;
	Shape *pLast;
public:
	void inputShape(int type) {
		Shape *tempShape = NULL;
		switch (type){
		case 1:
			tempShape = new Line();		break;
		case 2:
			tempShape = new Circle();	break;
		case 3:
			tempShape = new Rect();	break;
		default:
			return;
		}
		
		if (!pStart) {
			pLast = pStart = tempShape;
		}
		else {
			pLast->next = tempShape;
			pLast = pLast->next;
		}
	}
	void deleteShape(int index) {
		/*�ƹ��͵� �������� �ʾ����� ������ ���� ����.*/
		if (!pStart)	return;

		Shape * prev;
		Shape *del;
		/*�� �� ������ �����ϴ� ���*/
		if (index == 0) {
			del = pStart;
			pStart = pStart->next;
			delete(del);
			return;
		}
		/*�߰� ������ �����ϴ� ���, prev�� ���� ������ �����ϰ� ����*/
		prev = pStart;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->next;
			/*�ε����� ��� ���� �����ϸ� �׳� ������*/
			if (prev == NULL)	return;
		}
		/*������ ���*/
		del = prev->next;

		/*�ε����� ��� ���� �����ϸ� �׳� ������*/
		if (del == NULL)	return;

		prev->next = prev->next->next;
		if (del == pLast)	pLast = prev;
		delete(del);
	}
	void printAll() {
		UI::printAll(pStart, pLast);
	}
};
