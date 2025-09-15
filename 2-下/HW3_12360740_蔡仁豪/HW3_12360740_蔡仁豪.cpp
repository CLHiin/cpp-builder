//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW3_12360740_蔡仁豪.h"
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

BST_Node* 創建節點(int n){
	BST_Node *node = new BST_Node;
	node->data = n;
	node->L = node->R = NULL;
	return node;
}
BST_Node* 尋找節點(BST_Node *&node,int n){
	if(node == NULL || node->data == n) return node;
	if(node->data < n) return 尋找節點(node->R, n);
	else 			   return 尋找節點(node->L, n);
}
BST_Node* 尋找節點_2(BST_Node *node,int n){
	while(node != NULL && node->data != n){
		if(node->data < n) node = node->R;
		else 			   node = node->L;
	}
	return node;
}
void 新增節點(BST_Node *&node, int n) {
	if (!node) node = 創建節點(n);
	else if (node->data < n) 新增節點(node->R, n);
	else 					 新增節點(node->L, n);
}
void 新增節點_2(BST_Node *&node,int n){
	// 雙重指標** ，*current指向node，current指向 &node(節點指標)
	// **單純作為宣告
	BST_Node **current = &node;
	while(*current!=NULL){
		// current指向 [節點指標]，所以current = &(node->R/L)
		if((*current)->data < n) current = &((*current)->R);
		else 			   	     current = &((*current)->L);
	}
	*current = 創建節點(n);
}
BST_Node* 找最小值(BST_Node* node) {
	while (node->L != NULL) node = node->L;
	return node; // node(副本)->L依舊是指向原本，所以無須加&
}
bool 刪除節點(BST_Node*& node, int n) {
	if (node == NULL) return false;
		 if (n < node->data) return 刪除節點(node->L, n);
	else if (n > node->data) return 刪除節點(node->R, n);
	else {
		if (node->L == NULL && node->R == NULL) {
			  delete node;
			  node = NULL;
		} // 無左右，是最尾端
		else if (node->L == NULL || node->R == NULL) {
			BST_Node* temp = (node->L != NULL) ? node->L : node->R;
			delete node;
			node = temp;
		} // 一有一無，選無的接上
		else {
			BST_Node* temp = 找最小值(node->R);
			node->data = temp->data;
			刪除節點(node->R, temp->data);
		}
		// 兩者皆有，選一個資料蓋掉，再去刪除那個資料
		/* 雖然我覺得不太OK，比如我有2個40的節點在右子樹底下，
			21
		  /   \
		 0    40
			/   \
		   40   50
		這樣的狀況下我刪除21，就會因為有2個子樹而去右邊找最左的40。
		然後我又要去右邊刪除40，因此我會刪除到第二層的40
		同時又會因為那裏有2個節點而去50那裏找最小。
		如果樹有數百個相同數字的節點，那他將會重複跑好幾次這個函數
		*/
		return true;
	}
}
bool 刪除節點_2(BST_Node*& node, int n){
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
	} // 一有一無，選無的接上
	else{
		BST_Node* temp = 找最小值((*current)->R);
		(*current)->data = temp->data;
		刪除節點_2((*current)->R, temp->data);
	}
	return true;
}
void 中序走訪(BST_Node *node){
	if(node == NULL) return ;
	中序走訪(node->L);
	Tree_Str += IntToStr(node->data) + "_";
	中序走訪(node->R);
}
void 中序走訪_2(BST_Node* node) {
	BST_Node* current = node;
	while (current != NULL || top != NULL) {
		while (current != NULL) {
			push(current);
			current = current->L;
		}
		// 只要有跑while，就一定會跑到下面的程式碼，省略多餘的if判斷
		current = pop();
		Tree_Str += IntToStr(current->data) + "_"; // 記錄數據
		current = current->R; // 走訪右子樹
	}
}
void 前序走訪(BST_Node *node){
	if(node == NULL) return ;
	Tree_Str += IntToStr(node->data) + "_";
	前序走訪(node->L);
	前序走訪(node->R);
}
void 前序走訪_2(BST_Node* node) {
	if (node == NULL) return;
	push(node);
	while (top != NULL) {
		BST_Node* current = pop();
		Tree_Str += IntToStr(current->data) + "_";
		if (current->R) push(current->R);
		if (current->L) push(current->L);
	}
}
void 後序走訪(BST_Node *node){
	if(node == NULL) return ;
	後序走訪(node->L);
	後序走訪(
	node->R);
	Tree_Str += IntToStr(node->data) + "_";
}
void 後序走訪_2(BST_Node* node) {
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
void 階層走訪(BST_Node* node) {
	if (node == NULL) return;
	push_2(node);
	while (front != NULL) {
		BST_Node* current = pop_2();
		Tree_Str += IntToStr(current->data) + "_";
		if (current->L != NULL) push_2(current->L);
		if (current->R != NULL) push_2(current->R);
	}
}

TreeNode* 構造二元樹_前序中序(AnsiString pr, AnsiString in) {
	if (pr.IsEmpty() || in.IsEmpty()) return NULL;
	int rootIndex = in.Pos(pr[1]);
	int Len = in.Length() - rootIndex;

	// 分割中序遍歷
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// 分割前序遍歷
	AnsiString LP = pr.SubString(2, rootIndex - 1);
	AnsiString RP = pr.SubString(1+ rootIndex,Len);
	// 遞歸建立左右子樹
	TreeNode* r = new TreeNode(pr[1]);
	r->L = 構造二元樹_前序中序(LP, LI);
	r->R = 構造二元樹_前序中序(RP, RI);
	return r;
}
TreeNode* 構造二元樹_中序後序(AnsiString in, AnsiString po) {
	if (po.IsEmpty() || in.IsEmpty()) return NULL;
	char rootVal = po[po.Length()];  // 後序遍歷最後一個元素是根
	int rootIndex = in.Pos(rootVal);  // 找到位置
	int Len = po.Length() - rootIndex;// 右子樹長度

	// 分割中序遍歷
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// 分割後序遍歷
	AnsiString LP = po.SubString(1, rootIndex - 1);
	AnsiString RP = po.SubString(   rootIndex,Len);
	// 遞歸處理左右子樹
	TreeNode* r = new TreeNode(rootVal);
	r->L = 構造二元樹_中序後序(LI, LP);
	r->R = 構造二元樹_中序後序(RI, RP);
    return r;
}
TreeNode* 構造二元樹_中序層次(AnsiString in, AnsiString level) {
	if (in.IsEmpty() || level.IsEmpty()) return NULL;
	char rootVal = level[1];  // 根節點
	int rootIndex = in.Pos(rootVal); // 根節點位置
	int Len = in.Length() - rootIndex;

	// 分割中序遍歷
	AnsiString LI = in.SubString(1, rootIndex - 1);
	AnsiString RI = in.SubString(1+ rootIndex,Len);
	// 層次遍歷中的其他節點按順序插入左、右子樹
	AnsiString Llevel = "", Rlevel = "";
	for (int i = 2; i <= level.Length(); i++) {
		char currentVal = level[i];
		if (LI.Pos(currentVal)) Llevel += currentVal;  // 屬於左子樹
		else Rlevel += currentVal;  // 屬於右子樹
	}
	// 遞歸構建左右子樹
	TreeNode* r = new TreeNode(rootVal);
	r->L = 構造二元樹_中序層次(LI, Llevel);
	r->R = 構造二元樹_中序層次(RI, Rlevel);

	return r;
}

void 顯示樹(TreeNode* node, TTreeView* TreeView, TTreeNode* parent = NULL) {
	if (!node) return;
	TTreeNode* newNode;
	if (!parent) newNode = TreeView->Items->Add       (NULL, node->data); // 加到根節點
	else         newNode = TreeView->Items->AddChild(parent, node->data); // 加到子節點
	// 遞迴添加左子樹與右子樹
	顯示樹(node->L, TreeView, newNode);
	顯示樹(node->R, TreeView, newNode);
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
	新增節點(root, value);
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
		新增節點(root, Random(n) + 1);
	}
	Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int value = StrToInt(Edit1->Text);
	新增節點_2(root, value);
	Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
	Edit1->Text = IntToStr(value + 10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int value = StrToInt(Edit3->Text);
	if(尋找節點(root, value)) Memo1->Lines->Add(IntToStr(value) + "已找到");
	else                      Memo1->Lines->Add(IntToStr(value) + "未找到");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int value = StrToInt(Edit3->Text);
	if(尋找節點_2(root, value)) Memo1->Lines->Add(IntToStr(value) + "已找到");
	else                        Memo1->Lines->Add(IntToStr(value) + "未找到");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text);
	for (int i = 0; i < TrackBar1->Position; i++) {
		新增節點_2(root, Random(n) + 1);
	}
	Tree_Str = "";
	中序走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int value = StrToInt(Edit4->Text);
	if(刪除節點(root, value)) Memo1->Lines->Add(IntToStr(value) + "已刪除");
	else                      Memo1->Lines->Add(IntToStr(value) + "沒法刪除");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
	int value = StrToInt(Edit4->Text);
	if(刪除節點_2(root, value)) Memo1->Lines->Add(IntToStr(value) + "已刪除");
	else                      	Memo1->Lines->Add(IntToStr(value) + "沒法刪除");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
	Tree_Str = "";
	中序走訪_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
	Tree_Str = "";
	前序走訪_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
	Tree_Str = "";
	後序走訪_2(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
	Tree_Str = "";
	階層走訪(root);
	Memo1->Lines->Add(Tree_Str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	TreeNode* r = 構造二元樹_前序中序(Edit5->Text, Edit6->Text);
	顯示樹(r, TreeView1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button18Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	TreeNode* r = 構造二元樹_中序後序(Edit6->Text, Edit7->Text);
	顯示樹(r, TreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    TreeView1->Items->Clear();
	TreeNode* r = 構造二元樹_中序層次(Edit6->Text, Edit8->Text);
	顯示樹(r, TreeView1);
}
//---------------------------------------------------------------------------
