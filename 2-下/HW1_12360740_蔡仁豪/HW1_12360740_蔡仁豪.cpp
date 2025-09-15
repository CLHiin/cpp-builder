//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW1_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct BST_Node{
	int data;
	BST_Node *R,*L;
};
BST_Node *root;
String Tree_Str;

BST_Node* 創建節點(int n){
	BST_Node *node = new BST_Node;
	node->data = n;
	node->L = node->R = NULL;  // 確保左右子節點是 NULL
	return node;
}
BST_Node* 尋找節點(BST_Node *node,int n){
	if(node == NULL || node->data == n) return node;
	if(node->data < n) return 尋找節點(node->R, n);
	return 尋找節點(node->L, n);
}
BST_Node* 新增節點(BST_Node *node,int n){
	if(node == NULL) return 創建節點(n);
	if(node->data < n) node->R = 新增節點(node->R, n);
	else 			   node->L = 新增節點(node->L, n);
	return node;
}

void 中序走訪(BST_Node *node){
	if(node == NULL) return ;
	中序走訪(node->L);
	Tree_Str += IntToStr(node->data) + "_";
	中序走訪(node->R);
}
void 前序走訪(BST_Node *node){
	if(node == NULL) return ;
	Tree_Str += IntToStr(node->data) + "_";
	前序走訪(node->L);
	前序走訪(node->R);
}
void 後序走訪(BST_Node *node){
	if(node == NULL) return ;
	後序走訪(node->L);
	後序走訪(node->R);
	Tree_Str += IntToStr(node->data) + "_";
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int value = StrToInt(Edit1->Text);
	root = 新增節點(root, value);
	Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
    Edit1->Text = IntToStr(value + 10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Tree_Str = "";
	前序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Tree_Str = "";
	後序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	int value = TrackBar1->Position;
	Label2->Caption = "生成：" + IntToStr(value);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text);
	for (int i = 0; i < TrackBar1->Position; i++) {
		root = 新增節點(root, Random(n) + 1);
	}
    Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
