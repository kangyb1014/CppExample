/*
�� ���α׷��� ����Ʈ�� ���� �Ǵ� ���� �Ǵ� ����Ʈ ��� �Ǵ� ���Ḧ �Է¹޾� �� ����� �����Ѵ�.
����Ʈ�� GraphicEditor Ŭ������ ��� ���� pStart, pLast�� ���� Linked List�� �����Ǿ� �ִ�.
UI Ŭ������ Static Ŭ������ UI::(�Լ��̸�) ������ �Լ��� ȣ���� �� �ִ�.
���α׷��� while���� �����ϸ� UI::selectMenu()�� �ൿ�� �Է¹޴´�.
������ �Է¹޾��� ���� UI::selectShape()�� ������ ������ �Է¹ް� graphicEditor�� inputShape�� ȣ���Ѵ�.
������ �Է¹޾��� ���� UI::selectDel()�� ������ �ּҸ� �Է¹ް� graphicEditor�� deleteShape�� ȣ���Ѵ�.
����� �Է¹޾��� ���� graphicEditor->printAll�� ȣ���Ѵ�.
���Ḧ �Է¹����� while���� ���������� ���α׷��� �����Ѵ�.
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