//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW3_12360740_������.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
struct BST_Node{
	int data;
	BST_Node *R,*L;
};
struct StackNode {
	BST_Node* node;
	StackNode* next;
};
struct QueueNode{
	BST_Node* node;
	QueueNode* next;
};
struct TreeNode{
    char data;
	TreeNode* L;
	TreeNode* R;
	TreeNode(char val) : data(val), L(nullptr), R(nullptr) {}
};

BST_Node *root;
StackNode *top;
QueueNode *front,*queueEnd;

String Tree_Str;

void push(BST_Node* node) {
	StackNode* newNode = new StackNode;
	newNode->node = node;
	newNode->next = top;
	top = newNode;
}
BST_Node* pop() {
	if (top == NULL) return NULL;
	BST_Node* treeNode = top->node;
	StackNode* temp = top;
	top = top->next;
	delete temp;
	return treeNode;
}
void push_2(BST_Node* node) {
	QueueNode* newNode = new QueueNode;
	newNode->node = node;
	newNode->next = NULL;
	if (queueEnd == NULL) front = queueEnd = newNode;
	else {
		queueEnd->next = newNode;
		queueEnd = newNode;
	}
}
BST_Node* pop_2() {
	if (front == NULL) return NULL;
	BST_Node *node = front->node;
	QueueNode* temp = front;
	front = front->next;
	if (front == NULL) queueEnd = NULL;
	delete temp;
	return node;
}

BST_Node* �Ыظ`�I(int n){
	BST_Node *node = new BST_Node;
	node->data = n;
	node->L = node->R = NULL;
	return node;
}
BST_Node* �M��`�I(BST_Node *&node,int n){
	if(node == NULL || node->data == n) return node;
	if(node->data < n) return �M��`�I(node->R, n);
	else 			   return �M��`�I(node->L, n);
}
BST_Node* �M��`�I_2(BST_Node *node,int n){
	while(node != NULL && node->data != n){
		if(node->data < n) node = node->R;
		else 			   node = node->L;
	}
	return node;
}
void �s�W�`�I(BST_Node *&node, int n) {
	if (!node) node = �Ыظ`�I(n);
	else if (node->data < n) �s�W�`�I(node->R, n);
	else 					 �s�W�`�I(node->L, n);
}
void �s�W�`�I_2(BST_Node *&node,int n){
	// ��������** �A*current���Vnode�Acurrent���V &node(�`�I����)
	// **��§@���ŧi
	BST_Node **current = &node;
	while(*current!=NULL){
		// current���V [�`�I����]�A�ҥHcurrent = &(node->R/L)
		if((*current)->data < n) current = &((*current)->R);
		else 			   	     current = &((*current)->L);
	}
	*current = �Ыظ`�I(n);
}
BST_Node* ��̤p��(BST_Node* node) {
	while (node->L != NULL) node = node->L;
	return node; // node(�ƥ�)->L���¬O���V�쥻�A�ҥH�L���[&
}
bool �R���`�I(BST_Node*& node, int n) {
	if (node == NULL) return false;
		 if (n < node->data) return �R���`�I(node->L, n);
	else if (n > node->data) return �R���`�I(node->R, n);
	else {
		if (node->L == NULL && node->R == NULL) {
			  delete node;
			  node = NULL;
		} // �L���k�A�O�̧���
		else if (node->L == NULL || node->R == NULL) {
			BST_Node* temp = (node->L != NULL) ? node->L : node->R;
			delete node;
			node = temp;
		} // �@���@�L�A��L�����W
		else {
			BST_Node* temp = ��̤p��(node->R);
			node->data = temp->data;
			�R���`�I(node->R, temp->data);
		}
		// ��̬Ҧ��A��@�Ӹ�ƻ\���A�A�h�R�����Ӹ��
		/* ���M��ı�o����OK�A��p�ڦ�2��40���`�I�b�k�l�𩳤U�A
			21
		  /   \
		 0    40
			/   \
		   40   50
		�o�˪����p�U�ڧR��21�A�N�|�]����2�Ӥl��ӥh�k���̥���40�C
		�M��ڤS�n�h�k��R��40�A�]���ڷ|�R����ĤG�h��40
		�P�ɤS�|�]�����ئ�2�Ӹ`�I�ӥh50���ا�̤p�C
		�p�G�𦳼ƦʭӬۦP�Ʀr���`�I�A���L�N�|���ƶ]�n�X���o�Ө��
		*/
		return true;
	}
}
bool �R���`�I_2(BST_Node*& node, int n){
	BST_Node **current = &node;
	while(*current != NULL && (*current)->data != n){
		if((*current)->data < n) current = &((*current)->R);
		else 			   		 current = &((*current)->L);
	}
	if (*current == NULL) return false;
	if ((*current)->L == NULL && (*current)->R == NULL) {
		delete (*current);
		(*current) = NULL;
	}
	else if ((*current)->L == NULL || (*current)->R == NULL) {
		BST_Node* temp = ((*current)->L != NULL) ? (*current)->L : (*current)->R;
		delete (*current);
		(*current) = temp;
	} // �@���@�L�A��L�����W
	else{
		BST_Node* temp = ��̤p��((*current)->R);
		(*current)->data = temp->data;
		�R���`�I_2((*current)->R, temp->data);
	}
	return true;
}
void ���Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	���Ǩ��X(node->L);
	Tree_Str += IntToStr(node->data) + "_";
	���Ǩ��X(node->R);
}
void ���Ǩ��X_2(BST_Node* node) {
	BST_Node* current = node;
	while (current != NULL || top != NULL) {
		while (current != NULL) {
			push(current);
			current = current->L;
		}
		// �u�n���]while�A�N�@�w�|�]��U�����{���X�A�ٲ��h�l��if�P�_
		current = pop();
		Tree_Str += IntToStr(current->data) + "_"; // �O���ƾ�
		current = current->R; // ���X�k�l��
	}
}
void �e�Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	Tree_Str += IntToStr(node->data) + "_";
	�e�Ǩ��X(node->L);
	�e�Ǩ��X(node->R);
}
void �e�Ǩ��X_2(BST_Node* node) {
	if (node == NULL) return;
	push(node);
	while (top != NULL) {
		BST_Node* current = pop();
		Tree_Str += IntToStr(current->data) + "_";
		if (current->R) push(current->R);
		if (current->L) push(current->L);
	}
}
void ��Ǩ��X(BST_Node *node){
	if(node == NULL) return ;
	��Ǩ��X(node->L);
	��Ǩ��X(
	node->R);
	Tree_Str += IntToStr(node->data) + "_";
}
void ��Ǩ��X_2(BST_Node* node) {
	BST_Node* current = node, *peek, *temp;
	while (current != NULL || top != NULL) {
		while (current != NULL) {
			push(current);
			current = current->L;
		}
		peek = top->node;
		if(peek->R != NULL && peek->R != temp){
			current = peek->R;
		}
		else {
			Tree_Str += IntToStr(peek->data) + "_";
			temp = pop();
		}
	}
}
void ���h���X(BST_Node* node) {
	if (node == NULL) return;
	push_2(node);
	while (front != NULL) {
		BST_Node* current = pop_2();
		Tree_Str += IntToStr(current->data) + "_";
		if (current->L != NULL) push_2(current->L);
		if (current->R != NULL) push_2(current->R);
	}
}

TreeNode* �c�y�G����_�e�Ǥ���(AnsiString pr, AnsiString in) {
	if (pr.IsEmpty() || in.IsEmpty()) return NULL;
	int rootIndex = in.Pos(pr[1]);
	int Len = in.Length() - rootIndex;

	// ���Τ��ǹM��
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// ���Ϋe�ǹM��
	AnsiString LP = pr.SubString(2, rootIndex - 1);
	AnsiString RP = pr.SubString(1+ rootIndex,Len);
	// ���k�إߥ��k�l��
	TreeNode* r = new TreeNode(pr[1]);
	r->L = �c�y�G����_�e�Ǥ���(LP, LI);
	r->R = �c�y�G����_�e�Ǥ���(RP, RI);
	return r;
}
TreeNode* �c�y�G����_���ǫ��(AnsiString in, AnsiString po) {
	if (po.IsEmpty() || in.IsEmpty()) return NULL;
	char rootVal = po[po.Length()];  // ��ǹM���̫�@�Ӥ����O��
	int rootIndex = in.Pos(rootVal);  // ����m
	int Len = po.Length() - rootIndex;// �k�l�����

	// ���Τ��ǹM��
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// ���Ϋ�ǹM��
	AnsiString LP = po.SubString(1, rootIndex - 1);
	AnsiString RP = po.SubString(   rootIndex,Len);
	// ���k�B�z���k�l��
	TreeNode* r = new TreeNode(rootVal);
	r->L = �c�y�G����_���ǫ��(LI, LP);
	r->R = �c�y�G����_���ǫ��(RI, RP);
    return r;
}
TreeNode* �c�y�G����_���Ǽh��(AnsiString in, AnsiString level) {
	if (in.IsEmpty() || level.IsEmpty()) return NULL;
	char rootVal = level[1];  // �ڸ`�I
	int rootIndex = in.Pos(rootVal); // �ڸ`�I��m
	int Len = in.Length() - rootIndex;

	// ���Τ��ǹM��
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// �h���M��������L�`�I�����Ǵ��J���B�k�l��
	AnsiString Llevel = "", Rlevel = "";
	for (int i = 2; i <= level.Length(); i++) {
		char currentVal = level[i];
		if (LI.Pos(currentVal)) Llevel += currentVal;  // �ݩ󥪤l��
		else Rlevel += currentVal;  // �ݩ�k�l��
	}
	// ���k�c�إ��k�l��
	TreeNode* r = new TreeNode(rootVal);
	r->L = �c�y�G����_���Ǽh��(LI, Llevel);
	r->R = �c�y�G����_���Ǽh��(RI, Rlevel);

	return r;
}

void ��ܾ�(TreeNode* node, TTreeView* TreeView, TTreeNode* parent = NULL) {
	if (!node) return;
	TTreeNode* newNode;
	if (!parent) newNode = TreeView->Items->Add       (NULL, node->data); // �[��ڸ`�I
	else         newNode = TreeView->Items->AddChild(parent, node->data); // �[��l�`�I
	// ���j�K�[���l��P�k�l��
	��ܾ�(node->L, TreeView, newNode);
	��ܾ�(node->R, TreeView, newNode);
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
	�s�W�`�I(root, value);
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
		�s�W�`�I(root, Random(n) + 1);
	}
	Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int value = StrToInt(Edit1->Text);
	�s�W�`�I_2(root, value);
	Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
	Edit1->Text = IntToStr(value + 10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int value = StrToInt(Edit3->Text);
	if(�M��`�I(root, value)) Memo1->Lines->Add(IntToStr(value) + "�w���");
	else                      Memo1->Lines->Add(IntToStr(value) + "�����");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int value = StrToInt(Edit3->Text);
	if(�M��`�I_2(root, value)) Memo1->Lines->Add(IntToStr(value) + "�w���");
	else                        Memo1->Lines->Add(IntToStr(value) + "�����");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text);
	for (int i = 0; i < TrackBar1->Position; i++) {
		�s�W�`�I_2(root, Random(n) + 1);
	}
	Tree_Str = "";
	���Ǩ��X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int value = StrToInt(Edit4->Text);
	if(�R���`�I(root, value)) Memo1->Lines->Add(IntToStr(value) + "�w�R��");
	else                      Memo1->Lines->Add(IntToStr(value) + "�S�k�R��");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
	int value = StrToInt(Edit4->Text);
	if(�R���`�I_2(root, value)) Memo1->Lines->Add(IntToStr(value) + "�w�R��");
	else                      	Memo1->Lines->Add(IntToStr(value) + "�S�k�R��");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
	Tree_Str = "";
	���Ǩ��X_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
	Tree_Str = "";
	�e�Ǩ��X_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
	Tree_Str = "";
	��Ǩ��X_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
	Tree_Str = "";
	���h���X(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	TreeNode* r = �c�y�G����_�e�Ǥ���(Edit5->Text, Edit6->Text);
	��ܾ�(r, TreeView1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button18Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	TreeNode* r = �c�y�G����_���ǫ��(Edit6->Text, Edit7->Text);
	��ܾ�(r, TreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    TreeView1->Items->Clear();
	TreeNode* r = �c�y�G����_���Ǽh��(Edit6->Text, Edit8->Text);
	��ܾ�(r, TreeView1);
}
//---------------------------------------------------------------------------
