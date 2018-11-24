#include <iostream>
#include <vector>
using namespace std;


/*모든 입력은 예외 처리를 고려하지 않았다.*/

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
	static void printGraphic() { cout << "그래픽 에디터입니다." << endl; }
	static int selectMenu() {
		int inputVal;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> inputVal;
		return inputVal;
	}
	static int selectShape() {
		int inputVal;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> inputVal;
		return inputVal;
	}
	static int selectDel() {
		int inputVal;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
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
		/*아무것도 삽입하지 않았으면 삭제할 것이 없다.*/
		if (!pStart)	return;

		Shape * prev;
		Shape *del;
		/*맨 앞 도형을 삭제하는 경우*/
		if (index == 0) {
			del = pStart;
			pStart = pStart->next;
			delete(del);
			return;
		}
		/*중간 도형을 삭제하는 경우, prev의 다음 도형을 삭제하게 조절*/
		prev = pStart;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->next;
			/*인덱스를 벗어난 값에 접근하면 그냥 리턴함*/
			if (prev == NULL)	return;
		}
		/*삭제할 노드*/
		del = prev->next;

		/*인덱스를 벗어난 값에 접근하면 그냥 리턴함*/
		if (del == NULL)	return;

		prev->next = prev->next->next;
		if (del == pLast)	pLast = prev;
		delete(del);
	}
	void printAll() {
		UI::printAll(pStart, pLast);
	}
};
