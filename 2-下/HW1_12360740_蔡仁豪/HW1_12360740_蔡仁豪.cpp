//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW1_12360740_������.h"
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

BST_Node* �Ыظ`�I(int n){
	BST_Node *node = new BST_Node;
	node->data = n;
	node->L = node->R = NULL;  // �T�O���k�l�`�I�O NULL
	return node;
}
BST_Node* �M��`�I(BST_Node *node,int n){
	if(node == NULL || node->data == n) return node;
	if(node->data < n) return �M��`�I(node->R, n);
	return �M��`�I(node->L, n);
}
BST_Node* �s�W�`�I(BST_Node *node,int n){
	if(node == NULL) return �Ыظ`�I(n);
	if(node->data < n) node->R = �s�W�`�I(node->R, n);
	else 			   node->L = �s�W�`�I(node->L, n);
	return node;
}

void ���Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	���Ǩ��X(node->L);
	Tree_Str += IntToStr(node->data) + "_";
	���Ǩ��X(node->R);
}
void �e�Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	Tree_Str += IntToStr(node->data) + "_";
	�e�Ǩ��X(node->L);
	�e�Ǩ��X(node->R);
}
void ��Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	��Ǩ��X(node->L);
	��Ǩ��X(node->R);
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
	root = �s�W�`�I(root, value);
	Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
    Edit1->Text = IntToStr(value + 10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Tree_Str = "";
	�e�Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Tree_Str = "";
	��Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	int value = TrackBar1->Position;
	Label2->Caption = "�ͦ��G" + IntToStr(value);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text);
	for (int i = 0; i < TrackBar1->Position; i++) {
		root = �s�W�`�I(root, Random(n) + 1);
	}
    Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
