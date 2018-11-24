/*
이 프로그램은 리스트에 삽입 또는 삭제 또는 리스트 출력 또는 종료를 입력받아 그 기능을 수행한다.
리스트는 GraphicEditor 클래스의 멤버 변수 pStart, pLast에 의해 Linked List로 구현되어 있다.
UI 클래스는 Static 클래스로 UI::(함수이름) 등으로 함수를 호출할 수 있다.
프로그램은 while문을 수행하며 UI::selectMenu()로 행동을 입력받는다.
삽입을 입력받았을 때는 UI::selectShape()로 삽입할 도형을 입력받고 graphicEditor의 inputShape를 호출한다.
삭제를 입력받았을 때는 UI::selectDel()로 삭제할 주소를 입력받고 graphicEditor의 deleteShape를 호출한다.
출력을 입력받았을 때는 graphicEditor->printAll을 호출한다.
종료를 입력받으면 while문을 빠져나가고 프로그램을 종료한다.
*/

#include "GraphicEditor.h"

using namespace std;

int main() {
	GraphicEditor* graphicEditor = new GraphicEditor();
	int operation = 0;
	UI::printGraphic();
	while (operation != 4) {
		operation = UI::selectMenu();
		switch (operation){
		case 1:
			graphicEditor->inputShape(UI::selectShape());
			break;
		case 2:
			graphicEditor->deleteShape(UI::selectDel());
			break;
		case 3:
			graphicEditor->printAll();
			break;
		default:
			break;
		}
	}


	return 0;
}