//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW5_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TMemo *memo1,*memo2,*memo3;

struct Node1 {
	int data;
	Node1* next;

	Node1(int value, Node1* nextNode = nullptr)
		: data(value), next(nextNode) {}
};
struct Node2 {
	int data;
	Node2* next;
	Node2* prev;

	Node2(int value, Node2* nextNode = nullptr, Node2* prevNode = nullptr)
		: data(value), next(nextNode), prev(prevNode) {}
};

Node1 *top1, *top3;
Node2 *top2;

// 新增在前面
void InsertAsFirst1(int value) {
	Node1* newNode = new Node1(value, top1);
	top1 = newNode;
	memo1->Lines->Add("已將 " + IntToStr(value) + " 加入單向串列前方");
}
void InsertAsFirst2(int value) {
	Node2* newNode = new Node2(value,top2);
	top2->prev = newNode;
	top2 = newNode;
	memo2->Lines->Add("已將 " + IntToStr(value) + " 加入雙向串列前方");
}
// 新增在後面
void InsertAsLast1(int value) {
	Node1* newNode = new Node1(value);
	if (top1 == nullptr) top1 = newNode;
	else {
		Node1* last = top1;
		while (last->next != nullptr) last = last->next;
		last->next = newNode;
	}
	memo1->Lines->Add("已將 " + IntToStr(value) + " 加入單向串列後方");
}
void InsertAsLast2(int value) {
	Node2* newNode = new Node2(value);
	if (top2 == nullptr) top2 = newNode;
	else {
		Node2* last = top2;
		while (last->next != nullptr) last = last->next;
		last->next = newNode;
		newNode->prev = last;
    }
	memo2->Lines->Add("已將 " + IntToStr(value) + " 加入雙向串列後方");
}
// 查找節點
void search1(int value) {
	bool hasValue = false;
	for (Node1* c = top1; c != nullptr; c = c->next)
		if (c->data == value){hasValue = true; break;}
	if(hasValue) memo1->Lines->Add("已在單向串列中找到 " + IntToStr(value));
	else         memo1->Lines->Add("未在單向串列中找到 " + IntToStr(value));
}
void search2(int value) {
    bool hasValue = false;
	for (Node2* c = top2; c != nullptr; c = c->next)
		if (c->data == value) {hasValue = true;break;}
	if (hasValue) memo2->Lines->Add("已在雙向串列中找到 " + IntToStr(value));
	else          memo2->Lines->Add("未在雙向串列中找到 " + IntToStr(value));
}
// 删除節點
void DeleteNode1(int value) {
	if (top1 != nullptr && top1->data == value) {
		Node1* temp = top1;
		top1 = top1->next;
		delete temp;
		memo1->Lines->Add("已移除一個含有 " + IntToStr(value) + " 的節點");
		return;
	}
	for (Node1* c = top1; c != nullptr && c->next != nullptr; c = c->next){
		if (c->next->data == value) {
			Node1* temp = c->next;
			c->next = c->next->next;
			delete temp;
			memo1->Lines->Add("已移除一個含有 " + IntToStr(value) + " 的節點");
			return;
		}
	}
	memo1->Lines->Add("未找到值為" + IntToStr(value) + "的節點");
}
void DeleteNode2(int value) {
    if (top2 != nullptr && top2->data == value) {
		Node2* temp = top2;
        top2 = top2->next;
		if (top2 != nullptr) top2->prev = nullptr;
		delete temp;
		memo2->Lines->Add("已移除一個含有 " + IntToStr(value) + " 的節點");
        return;
    }
	for (Node2* c = top2; c != nullptr ; c = c->next) {
		if (c->data == value) {
			Node2* temp = c;
			c->prev->next = c->next;
            if (c->next != nullptr) c->next->prev = c->prev;
            delete temp;
			memo2->Lines->Add("已移除一個含有 " + IntToStr(value) + " 的節點");
            return;
        }
    }
	memo2->Lines->Add("未找到值為" + IntToStr(value) + "的節點");
}
// 插入節點後面
void InsertAfterValue1(int value, int target) {
	Node1* newNode = new Node1(value);
	for (Node1* c = top1; c != nullptr; c = c->next) {
		if (c->data == target) {
			newNode->next = c->next;
			c->next = newNode;
			memo1->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 後面");
			return;
		}
	}
	memo1->Lines->Add("未找到值為 " + IntToStr(target) + " 的節點");
}
void InsertAfterValue2(int value, int target) {
	Node2* newNode = new Node2(value);
    for (Node2* c = top2; c != nullptr; c = c->next) {
		if (c->data == target) {
			newNode->next = c->next;
            if (c->next != nullptr) c->next->prev = newNode;
			newNode->prev = c;
			c->next = newNode;
			memo2->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 後面");
			return;
        }
	}
	memo2->Lines->Add("未找到值為 " + IntToStr(target) + " 的節點");
}
// 插入節點前面
void InsertBeforeValue1(int value, int target) {
	Node1* newNode = new Node1(value);
	if (top1 != nullptr && top1->data == target) {
		newNode->next = top1;
		top1 = newNode;
		memo1->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 前方");
		return;
	}
	for (Node1* c = top1; c != nullptr && c->next != nullptr; c = c->next) {
		if (c->next->data == target) {
			newNode->next = c->next;
			c->next = newNode;
			memo1->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 前方");
			return;
        }
	}
	memo1->Lines->Add("未找到值為 " + IntToStr(target) + " 的節點");
}
void InsertBeforeValue2(int value, int target) {
    Node2* newNode = new Node2(value);
    if (top2 != nullptr && top2->data == target) {
		newNode->next = top2;
		top2->prev = newNode;
		top2 = newNode;
		memo2->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 前方");
		return;
    }
	for (Node2* c = top2; c != nullptr ; c = c->next) {
		if (c->data == target) {
			newNode->next = c;
			newNode->prev = c->prev;
			c->prev->next = newNode;
			c->prev = newNode;
			memo2->Lines->Add("已將 " + IntToStr(value) + " 插入到 " + IntToStr(target) + " 前方");
			return;
        }
    }
	memo2->Lines->Add("未找到值為 " + IntToStr(target) + " 的節點");
}
// 列印串列
void PrintList1() {
	String s="";
	for (Node1 *c = top1; c != nullptr; c = c->next)
		s+=IntToStr(c->data) + "->";
	memo1->Lines->Add("列印單向串列: " + s + "|");
}
void PrintList2() {
	String s="";
	for (Node2 *c = top2; c != nullptr; c = c->next)
		s+=IntToStr(c->data) + "<->";
	memo2->Lines->Add("列印雙向串列: " + s + "|");
}
void PrintList3() {
	String s="";
	for (Node1 *c = top3; c != nullptr; c = c->next)
		s+=IntToStr(c->data) + "->";
	memo3->Lines->Add("列印堆疊內容: " + s + "|");
}
// 反轉串列
void ReverseList1(){
	Node1 *prev = nullptr, *next = nullptr, *c = top1;
	while (c != nullptr) {
		next = c->next;
		c->next = prev;
		prev = c;
		c = next;
	}
	top1 = prev;
	memo1->Lines->Add("已反轉單向串列");
	PrintList1();
}
void ReverseList2() {
	Node2* current = top2, *temp = nullptr;
	while (current != nullptr) {
		temp = current->prev;
        current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != nullptr) top2 = temp->prev;
	memo2->Lines->Add("已反轉雙向串列");
	PrintList2();
}
void ReverseList3() {
	Node1 *prev = nullptr, *next = nullptr, *c = top3;
    while (c != nullptr) {
        next = c->next;
		c->next = prev;
		prev = c;
		c = next;
	}
	top3 = prev;
	memo3->Lines->Add("已反轉串列堆疊");
	PrintList3();
}
// 清空單向串列
void ClearList1() {
	while (top1 != nullptr) {
		Node1* temp = top1;
		top1 = top1->next;
		delete temp;
	}
	memo1->Lines->Add("已清空單向串列");
}
void ClearList2() {
    while (top2 != nullptr) {
		Node2* temp = top2;
		top2 = top2->next;
		delete temp;
	}
	memo2->Lines->Add("雙向鏈表已清空");
}
void ClearList3() {
	while (top3 != nullptr) {
		Node1* temp = top3;
		top3 = top3->next;
        delete temp;
    }
	memo3->Lines->Add("已清空串列堆疊");
}
// 堆疊
void push(int value) {
	Node1* newNode = new Node1(value);
	newNode->next = top3;
	top3 = newNode;
	memo3->Lines->Add("已將 " + IntToStr(value) + " 推入堆疊");
}
void pop() {
	if (top3 == nullptr) {memo3->Lines->Add("堆疊為空");return;}
	int popValue = top3->data;
	Node1* temp = top3;
	top3 = top3->next;
	delete temp;
	memo3->Lines->Add("已將 " + IntToStr(popValue) + " 從堆疊中彈出");
	return;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {
	memo1 = Memo1;
	memo2 = Memo2;
	memo3 = Memo3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) InsertAsLast1(StrToInt(Edit1->Text));
	else if (PageControl1->ActivePage == TabSheet2) InsertAsLast2(StrToInt(Edit1->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) InsertAsFirst1(StrToInt(Edit1->Text));
	else if (PageControl1->ActivePage == TabSheet2) InsertAsFirst2(StrToInt(Edit1->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) search1(StrToInt(Edit2->Text));
	else if (PageControl1->ActivePage == TabSheet2) search2(StrToInt(Edit2->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) DeleteNode1(StrToInt(Edit2->Text));
	else if (PageControl1->ActivePage == TabSheet2) DeleteNode2(StrToInt(Edit2->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) InsertAfterValue1(StrToInt(Edit3->Text),StrToInt(Edit2->Text));
	else if (PageControl1->ActivePage == TabSheet2) InsertAfterValue2(StrToInt(Edit3->Text),StrToInt(Edit2->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) InsertBeforeValue1(StrToInt(Edit3->Text),StrToInt(Edit2->Text));
	else if (PageControl1->ActivePage == TabSheet2) InsertBeforeValue2(StrToInt(Edit3->Text),StrToInt(Edit2->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text), r = StrToInt(Edit5->Text);
	while(n--){
		int randomValue = Random(r + 1);
			 if (PageControl1->ActivePage == TabSheet1) InsertAsLast1(randomValue);
		else if (PageControl1->ActivePage == TabSheet2) InsertAsLast2(randomValue);
		else                                            push(randomValue);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	if (PageControl1->ActivePage == TabSheet3) push(StrToInt(Edit6->Text));
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	if (PageControl1->ActivePage == TabSheet3) pop();
	else ShowMessage("當前頁面無此功能！");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) PrintList1();
	else if (PageControl1->ActivePage == TabSheet2) PrintList2();
	else 											PrintList3();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) ReverseList1();
	else if (PageControl1->ActivePage == TabSheet2) ReverseList2();
	else 											ReverseList3();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
		 if (PageControl1->ActivePage == TabSheet1) ClearList1();
	else if (PageControl1->ActivePage == TabSheet2) ClearList2();
	else                                            ClearList3();
}
//---------------------------------------------------------------------------
