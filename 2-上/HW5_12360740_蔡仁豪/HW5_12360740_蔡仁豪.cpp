//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "HW5_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

int top=-1;
String stack[10000];

void push(String s) {
	if (top < 9999) stack[++top] = s;
}
void push(char s) {
	if (top < 9999) stack[++top] = s;
}
String pop() {
	if (top == -1) return "";
	return stack[top--];
}



int oper(String op) {
	if (op == "(" || op == ")") return 1;
	if (op == "+" || op == "-") return 2;
	if (op == "*" || op == "/") return 3;
	if (op == "^") return 4;
	return 0;
}
int oper(char op) {
	if (op == '(' || op == ')') return 1;
	if (op == '+' || op == '-') return 2;
	if (op == '*' || op == '/') return 3;
	if (op == '^') return 4;
	return 0;
}

String swap_r_l(String S) {
	for (auto&c:S){
		switch(c){
			case'(':c = ')';break;
			case')':c = '(';break;
		}
	}
	return S;
}

String in_to_pre_or_post(String S, int n){
	String ans="",x;
	push('#');
	// n==0 前序:反轉過後的後序 再反轉
	if(n==0) {
		std::reverse(S.begin(), S.end());
		S = swap_r_l(S); // 左右括號轉換
	}
	for(char c:S){
		if(oper(c)){
			if (c == ')') while ((x=pop()) != "(") ans+=x;
			else {
				if (c != '(') while (oper(stack[top]) >= oper(c)) ans+=pop();
				push(c);
			}
		}
		else ans+=c;
	}
	while (stack[top] != '#') ans += pop();
	if (n==0) std::reverse(ans.begin(), ans.end());
	return ans;
}

String post_to_pre_or_in(String S, int n) {
    for (char c : S) {
		if (oper(c)) {
			String o1 = pop(), o2 = pop();
			if (n) push("(" + o2 + c + o1 + ")");
			else   push(String() + c + o2 + o1);
		}
		else push(c);
	}
	return pop();
}


String pre_to_in_or_post(String S, int n){
	std::reverse(S.begin(), S.end());

	String ans = post_to_pre_or_in(S,!n); // 借用後序轉前序、中序

	std::reverse(ans.begin(), ans.end()); // 反轉後即是後序、中序
	ans = swap_r_l(ans);

	return ans;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	String s = Edit1->Text;
	Memo1->Lines->Add(s + "的中序轉前序：" + in_to_pre_or_post(s,0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String s = Edit1->Text;
	Memo1->Lines->Add(s + "的中序轉後序：" + in_to_pre_or_post(s,1));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	String s = Edit2->Text;
	Memo1->Lines->Add(s + "的前序轉中序：" + pre_to_in_or_post(s,0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	String s = Edit2->Text;
	Memo1->Lines->Add(s + "的前序轉後序：" + pre_to_in_or_post(s,1));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	String s = Edit3->Text;
	Memo1->Lines->Add(s + "的後序轉前序：" + post_to_pre_or_in(s,0));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 	String s = Edit3->Text;
	Memo1->Lines->Add(s + "的後序轉中序：" + post_to_pre_or_in(s,1));
}
//---------------------------------------------------------------------------


