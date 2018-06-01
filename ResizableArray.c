#include <stdio.h>
#include <stdlib.h>

//#define BLOCK_SIZE 10
#define RUN_TIMES 6

typedef struct Array_{
	int *array;
	int size;
}Array;

Array create_array(int init_size);
void free_array(Array *a);
int* get_unit(Array *a);
void set_unit(Array *a);
void set_array(Array *a);
void inflate_array(Array *a,int incr_size);
void output_array(const Array *a);
int  array_size(const Array *a);
void display_menu();

int main(){
	int init_size,index;
	printf("enter array_size to initialize:");
	scanf("%d",&init_size);
	getchar();
	Array a=create_array(init_size);
	
	int k=-1,op;
	while(++k<RUN_TIMES){
		display_menu();
		scanf("%d",&op);
		system("cls");
		
		switch(op){
			case 1:	
					printf("set each array's unit's value:\n");
					set_array(&a);
					break;	
			case 2:	
					printf("enter a index to get the unit's value\n");
					printf("this unit's value=%d\n",*get_unit(&a));
					break;
			case 3:
					printf("enter a index to set the unit's value\n");
					set_unit(&a);
					break;
			case 4:	
					printf("array:\n");
					output_array(&a);
					break;
			case 5:
					printf("enter a size to inflate the array\n");
					int incr_size;
					scanf("%d",&incr_size);
					inflate_array(&a,incr_size);
					break;
			case 6:	
					printf("array size=%d\n",array_size(&a));
					break;
			default:
					printf("invalid option!\n");
					break;
		}
	}
	
	free_array(&a);
	system("pause");
	return 0;
}

Array create_array(int init_size){
	Array a;
	a.size=init_size;
	a.array=(int*)malloc(sizeof(int)*init_size);
	return a;
}

void free_array(Array *a){
	free(a->array);
	a->array=NULL;
	a->size=0;
}

int* get_unit(Array *a){
	int index;
	scanf("%d",&index);
	if(index>=0&&index<=a->size-1)
		return &a->array[index];
	else{
		printf("invalid index,try again!\n");
		//if it is this form:get_unit(Array *a,int index)
		//when index>=0
		//do inflate_array here
		// int block_num=0;
		// if(intdex%BLOCK_SIZE!=0)
			// block_num=index/BLOCK_SIZE+1;
		// else
			// block_num=index/BLOCK_SIZE;
		// int *p=(int*)malloc(sizeof(int)*BLOCK_SIZE*block_num);
		//simplified means this:inflate_array(a,BLOCK_SIZE*((index/BLOCK_SIZE)+1)-a->size)
		get_unit(a);
	}
}

void set_unit(Array *a){
	int index;
	scanf("%d",&index);
	if(index>=0&&index<=a->size-1)
		scanf("%d",&a->array[index]);
	else{
		printf("invalid index, try again!\n");
		set_unit(a);
	}
}

void set_array(Array *a){
	int i;
	for(i=0;i<a->size;i++){
		scanf("%d",&a->array[i]);
	}
}

void output_array(const Array *a){
	int i=0;
	while(i<a->size){
		printf("%d ",a->array[i++]);
	}
	printf("\n");
}

void inflate_array(Array *a,int incr_size){
	int *p=(int*)malloc(sizeof(int)*(a->size+incr_size));
	int i;
	for(i=0;i<a->size;i++){
		p[i]=a->array[i];
	}
	free(a->array);
	a->array=p;
	a->size+=incr_size;
}

int array_size(const Array *a){
	return a->size;
}

void display_menu() 
{ 
	 printf("\t*******************************************************\n"); 
	 printf("\t**   1.set each array's unit's value                 **\n"); 
	 printf("\t**   2.enter a index to get the unit's value         **\n"); 
	 printf("\t**   3.enter a index to set the unit's value         **\n"); 
	 printf("\t**   4.output the array                              **\n"); 
	 printf("\t**   5.enter a size to inflate the array             **\n"); 
	 printf("\t**   6.see the array's size                          **\n"); 
	 printf("\t*******************************************************\n"); 
}