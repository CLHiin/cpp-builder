//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW5_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <VclTee.Series.hpp>

TForm1 *Form1;

int Len;
int size;
int randRange;
int maxDistance;
int noConnValue;
clock_t t0, tx;

struct Edge {
	int u, v, w;
	Edge(){}
	Edge(int a, int b, int c):u(a),v(b),w(c){}
};
Edge heap[10000];
int heapSize;
//ShowMessage();
void push(Edge node) {
	int i = heapSize++;
	while (i > 1 && node.w < heap[i/2].w) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = node;
}
Edge pop() {
	Edge min = heap[1], last = heap[heapSize--];
	int i = 1, child;
	while ( (child=i*2) <= heapSize) {
		if (child < heapSize && heap[child+1].w < heap[child].w) child++;
		if (last.w <= heap[child].w) break;
		heap[i] = heap[child];
		i = child;
	}
	heap[i] = last;
	return min;
}
int parent[100];

int find(int x) {
	if (parent[x] != x) parent[x] = find(parent[x]);  // 路徑壓縮
	return parent[x];
}

void unite(int x, int y) {
	parent[find(x)] = find(y);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("時間比較");
	Chart1->BottomAxis->Title->Caption = "建樹演算法";
	Chart1->LeftAxis->Title->Caption = "CPU 時間 (秒)";

	TBarSeries *selSortSeries = new TBarSeries(this);
	Chart1->AddSeries(selSortSeries);
	Chart1->Series[0]->Title = "Kruskal 演算法";

	TBarSeries *bubSortSeries = new TBarSeries(this);
	Chart1->AddSeries(bubSortSeries);
	Chart1->Series[1]->Title = " Prim 演算法";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	size        = StrToInt(Edit1->Text);
	randRange   = StrToInt(Edit2->Text);
	maxDistance = StrToInt(Edit3->Text);
	noConnValue = StrToInt(Edit4->Text);

	PageControl1->ActivePage = TabSheet1;

	StringGrid1->RowCount = size + 1;
	StringGrid1->ColCount = size + 1;

	StringGrid2->RowCount = size * (size - 1) / 2 + 1;

	// 設定標題列與標題欄
	StringGrid2->Cells[0][0] = "起點";
	StringGrid2->Cells[1][0] = "終點";
	StringGrid2->Cells[2][0] = "距離";
	StringGrid1->Cells[0][0] = "距離\\當前點";
	for (int i = 1; i <= size; ++i) {
		StringGrid1->Cells[i][0] = IntToStr(i - 1); // 上排標籤
		StringGrid1->Cells[0][i] = IntToStr(i - 1); // 左側標籤
	}

	Len = 1;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			int value = Random(randRange) + 1;
			if (value>maxDistance || i>=j) value = noConnValue;
			StringGrid1->Cells[i][j] = value;
			if (value != noConnValue) {
				StringGrid2->Cells[0][Len] = i-1;
				StringGrid2->Cells[1][Len] = j-1;
				StringGrid2->Cells[2][Len++] = value;
			}
		}
	}
	StringGrid2->Cells[0][Len] = "到此結束";
	StringGrid2->Cells[1][Len] = "多的是";
	StringGrid2->Cells[2][Len] = "之前資料";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet2;

	int totalWeight = 0;
	int count = 0;
	heapSize = 1; // 初始化heap
	Memo1->Lines->Add("生成("+IntToStr(size)+"x"+IntToStr(size)+")最小延展樹:");

	t0 = clock();//計時
	for (int i=1; i < Len; i++) {
		int u = StrToInt(StringGrid2->Cells[0][i]),
			v = StrToInt(StringGrid2->Cells[1][i]),
			w = StrToInt(StringGrid2->Cells[2][i]);
		push(Edge(u,v,w));
	} // 用 min-heap 堆疊資料，耗時:O(E*log E)
	for (int i = 0; i < size; i++) parent[i] = i; // 初始化指標，耗時: O(N)
	while (count < size-1 && heapSize > 1) {
		Edge e = pop();               // O(log E)
		if (find(e.u) != find(e.v)) { // O(α(N)) ≈ O(1)
			unite(e.u, e.v);          // O(α(N)) ≈ O(1)
			totalWeight += e.w;
			count++;
			if(CheckBox1->Checked)
				Memo1->Lines->Add("邊("+IntToStr(e.u)+","+IntToStr(e.v)+")="+IntToStr(e.w));
		}
	} // 最多執行E次，耗時: O(Elog E)
	tx = clock();
	double sortTime = float(tx-t0)/CLOCKS_PER_SEC;
	if(CheckBox2->Checked)
		Chart1->Series[0]->AddXY(size,sortTime,"Kruskal ("+IntToStr(size)+ ")",clRed);
	Memo1->Lines->Add("總距離: "+IntToStr(totalWeight));
	Memo1->Lines->Add("總邊數: "+IntToStr(count)+"(邊數要等於n-1才有最小樹)");
	Memo1->Lines->Add("---------------------");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet4;

	int graph[100][100] = {0}; // 鄰接矩陣初始化
	int key[100];     // 最短邊
	bool inMST[100];  // 是否已在最小生成樹內
	int count = 0, totalWeight = 0;;

	Memo2->Lines->Add("Prim ("+IntToStr(size)+"x"+IntToStr(size)+")最小延展樹:");

	t0 = clock();
    for (int i = 1; i < Len; i++) {
		int u = StrToInt(StringGrid2->Cells[0][i]);
		int v = StrToInt(StringGrid2->Cells[1][i]);
		int w = StrToInt(StringGrid2->Cells[2][i]);
		graph[u][v] = w;
		graph[v][u] = w;
	} // 用 graph[][] 矩陣處理資料
	for (int i = 0; i < size; i++) {
		key[i] = noConnValue;
		inMST[i] = false;
		parent[i] = -1;
	} // 初始化數值
	key[0]=0; //隨意找一起點
	while(count < size - 1){
		int u=-1,minKey=noConnValue;
		for (int i = 0; i < size; i++)
			if (!inMST[i] && key[i] < minKey)
				minKey = key[u=i];

		if (u == -1) break; // 無最短邊可用
		inMST[u] = true;    // 將對應點放入MST
		count++;            // 樹節點+1

		int v= parent[u];
		if (v != -1) {
			totalWeight += graph[u][v];
			if (CheckBox1->Checked)
				Memo2->Lines->Add("邊("+IntToStr(v)+","+IntToStr(u)+")="+IntToStr(graph[u][v]));
		}
		for (int v = 0; v < size; v++) {
			if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
				key[v] = graph[u][v]; // 更新最短邊權重
				parent[v] = u;        // v的連結點為u
			}
		} // while迴圈最多E-1次，for跑E次，耗時: O(E^2)
	}
	tx = clock();
	double sortTime = float(tx-t0)/CLOCKS_PER_SEC;
	if(CheckBox2->Checked)
		Chart1->Series[1]->AddXY(size,sortTime,"Prim ("+IntToStr(size)+")",clBlue);
	Memo2->Lines->Add("總距離: "+IntToStr(totalWeight));
	Memo2->Lines->Add("總邊數: "+IntToStr(count)+"(邊數要等於n-1才有最小樹)");
	Memo2->Lines->Add("---------------------");
}
//---------------------------------------------------------------------------
// Kruskal 比 Prim 慢的原因說明(chatGPT)
// 手寫的最小堆插入[成本較高] 用push一筆一筆插入，邊多時效率不如一次排序
// 反覆呼叫push vs 一次sort	用標準庫 std::sort 一次排序效率更好
// 圖很小時 Prim 更適合，Kruskal overhead較大	Kruskal必須初始化堆、union-find，起手式較重
