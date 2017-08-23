#include <iostream>

#include <stdio.h>

using namespace std;

/*
 * http://blog.csdn.net/hguisu/article/details/7776068
 */

void print(int a[], int n ,int i){
    //cout << "第" <<i <<"趟:";
    for(int j= 0; j < n; j++){
        cout<<a[j] <<" ";
    }
    cout<<endl;
}

// 直接插入排序
void InsertSort(int a[], int n)
{
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){               //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j= i-1;
            int x = a[i];        //复制为哨兵，即存储待排序元素
            a[i] = a[i-1];           //先后移一个元素
            while(x < a[j]){  //查找在有序表的插入位置
                a[j+1] = a[j];
                j--;         //元素后移
            }
            a[j+1] = x;      //插入到正确位置
        }
        //打印每趟排序的结果
        print(a,n,i);
    }

}

// 希尔排序
/*
 * dk为增量
 */
void ShellInsertSort(int a[], int n, int dk)
{
    for(int i= dk; i<n; ++i){
        if(a[i] < a[i-dk]){          //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j = i-dk;
            int x = a[i];           //复制为哨兵，即存储待排序元素
            a[i] = a[i-dk];         //首先后移一个元素
            while(x < a[j]){     //查找在有序表的插入位置
                a[j+dk] = a[j];
                j -= dk;             //元素后移
            }
            a[j+dk] = x;            //插入到正确位置
        }
        print(a, n,i );
    }

}
/**
 * 先按增量d（n/2,n为要排序数的个数进行希尔排序
 *
 */
void shellSort(int a[], int n){

    int dk = n/2;
    while( dk >= 1 ){
        ShellInsertSort(a, n, dk);
        dk = dk/2;
    }
}

// 选择排序
/**
 * 数组的最小值
 *
 * @return int 数组的键值
 */
int SelectMinKey(int a[], int n, int i)
{
    int k = i;
    for(int j=i+1 ;j< n; ++j) {
        if(a[k] > a[j]) k = j;
    }
    return k;
}

/**
 * 选择排序
 *
 */
void selectSort(int a[], int n){
    int key, tmp;
    for(int i = 0; i< n; ++i) {
        key = SelectMinKey(a, n,i);           //选择最小的元素
        if(key != i){
            tmp = a[i];  a[i] = a[key]; a[key] = tmp; //最小元素与第i位置元素互换
        }
        print(a,  n , i);
    }
}

/*
 * 二元选择排序
 */
 void SelectSort(int r[],int n) {
    int i ,j , min ,max, tmp;
    for (i=1 ;i <= n/2;i++) {
        // 做不超过n/2趟选择排序
        min = i; max = i ; //分别记录最大和最小关键字记录位置
        for (j= i+1; j<= n-i; j++) {
            if (r[j] > r[max]) {
                max = j ; continue ;
            }
            if (r[j]< r[min]) {
                min = j ;
            }
      }
      //该交换操作还可分情况讨论以提高效率
      tmp = r[i-1]; r[i-1] = r[min]; r[min] = tmp;
      tmp = r[n-i]; r[n-i] = r[max]; r[max] = tmp;

    }
}

/*
 * 交换排序
 * 冒泡排序
 */
void bubbleSort(int a[], int n){
    for(int i =0 ; i< n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            if(a[j] > a[j+1])
            {
                int tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;
            }
        }
    }
}

/*
 * 冒泡排序的改进
 */
void Bubble_1 (int r[], int n) {
    int i= n -1;  //初始时,最后位置保持不变
    while ( i> 0) {
        int pos= 0; //每趟开始时,无记录交换
        for (int j= 0; j< i; j++)
            if (r[j]> r[j+1]) {
                pos= j; //记录交换的位置
                int tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
            }
        i= pos; //为下一趟排序作准备
     }
}

/*
 * 交换排序
 * 快速排序
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int a[], int low, int high)
{
    int privotKey = a[low];                             //基准元素
    while(low < high){                                   //从表的两端交替地向中间扫描
        while(low < high  && a[high] >= privotKey) --high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
        swap(&a[low], &a[high]);
        while(low < high  && a[low] <= privotKey ) ++low;
        swap(&a[low], &a[high]);
    }
    //print(a,10);
    return low;
}
void quickSort(int a[], int low, int high){
    if(low < high){
        int privotLoc = partition(a,  low,  high);  //将表一分为二
        quickSort(a,  low,  privotLoc -1);          //递归对低子表递归排序
        quickSort(a,   privotLoc + 1, high);        //递归对高子表递归排序
    }
}

/*
 * 归并排序
 */
 //将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
void Merge(int *r,int *rf, int i, int m, int n)
{
    int j,k;
    for(j=m+1,k=i; i<=m && j <=n ; ++k){
        if(r[j] < r[i]) rf[k] = r[j++];
        else rf[k] = r[i++];
    }
    while(i <= m)  rf[k++] = r[i++];
    while(j <= n)  rf[k++] = r[j++];
}

int main(){
	int a[8] = {3,1,4,56,76,7,8,9};

	InsertSort(a,8);
	print(a,8,8);

	shellSort(a,8);
	print(a,8,8);

	selectSort(a, 8);
	print(a,8,8);

	int b[10] = {3,1,5,7,2,4,9,6,10,8};
    quickSort(b,0,9);

	return 0;
}

