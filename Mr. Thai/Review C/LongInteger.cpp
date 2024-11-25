#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *numbers;
	int size;
	int negative; // kiem tra dau am
}LongInteger;

void read(LongInteger *num, char n){
	char c[1000];
	printf("Enter number %c :  ", n);
	fgets(c, 1000, stdin);
	c[strlen(c)-1] = '\0'; 
	
	//kiem tra dau am 
	if(c[0] == '-') {
		num->negative = 1;
		num->numbers = (char*)malloc(strlen(c));
		strcpy(num->numbers, c + 1); //bo dau - va sao chep phan con lai
	} else {
		num->negative = 0;
		num->numbers = (char*)malloc(strlen(c + 1 ));
		strcpy(num->numbers, c);
	}
	num->size = strlen(num->numbers); 
}

void display(LongInteger num) {
	if(num.negative){
		printf("-"); 
	}
	printf("%s", num.numbers);
}

//dao nguoc chuoi 
void reverse(char *num, int size){
	int left = 0, right = size - 1; 
    while (left < right ) {
        char tmp = num[left];
        num[left] = num[right];
        num[right] = tmp;
        left++;
        right--;
    }
}
int compareNumbers(char *a, char *b, int lenA, int lenB) {
    if (lenA != lenB) {
        return lenA - lenB; 
    }
    return strcmp(a, b); 
}
LongInteger add(LongInteger a, LongInteger b) {
    LongInteger result;
    int maxSize = (a.size > b.size) ? a.size : b.size;
    result.numbers = (char *)malloc(maxSize + 2); // +1 cho ky tu nho và +1 cho ky tu ket thuc
    result.size = 0;

    reverse(a.numbers, a.size);
    reverse(b.numbers, b.size);

    int memory = 0;
    for (int i = 0; i < maxSize; i++) {
        int numberA = (i < a.size) ? a.numbers[i] - '0' : 0;
        int numberB = (i < b.size) ? b.numbers[i] - '0' : 0;
        int sum = numberA + numberB + memory;
        result.numbers[result.size++] = (sum % 10) + '0';
        memory = sum / 10;
    }
	if (memory) {
        result.numbers[result.size++] = memory + '0';
    }
	result.numbers[result.size] = '\0';
	reverse(result.numbers, result.size);
	return result;
}
LongInteger subtract(LongInteger a, LongInteger b) {
    LongInteger result;
    int maxSize = (a.size > b.size) ? a.size : b.size;
    result.numbers = (char *)malloc(maxSize + 1);
    result.size = 0;

    reverse(a.numbers, a.size);
    reverse(b.numbers, b.size);

    int borrow = 0;
    for (int i = 0; i < maxSize; i++) {
        int numberA = (i < a.size) ? a.numbers[i] - '0' : 0;
        int numberB = (i < b.size) ? b.numbers[i] - '0' : 0;

        int diff = numberA - numberB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.numbers[result.size++] = diff + '0';
    }

    // Loai bo cac so 0 thua khi ma xau truoc có chu so lon hon chu so xâu sau
    while (result.size > 1 && result.numbers[result.size - 1] == '0') {
        result.size--;
    }

    result.numbers[result.size] = '\0';
    reverse(result.numbers, result.size);
	return result;
}

LongInteger sum(LongInteger a, LongInteger b) {
    LongInteger result;

    if (a.negative == b.negative) {
    	result = add(a, b);
        result.negative = a.negative; 
    } else {
        if (compareNumbers(a.numbers, b.numbers, a.size, b.size) >= 0) {
            result = subtract(a, b);
            result.negative = a.negative; 
        } else {
            result = subtract(b, a);
            result.negative = b.negative; 
        }
    }
    return result;
}
LongInteger sub(LongInteger a, LongInteger b){
    LongInteger result;
    reverse(a.numbers, a.size);
	reverse(b.numbers, b.size);
    if(a.negative == 0 && b.negative == 0){
        // a,b duong
        if(compareNumbers(a.numbers, b.numbers, a.size, b.size) >= 0){
            result = subtract(a,b);
            result.negative = 0;
        }
        else{
            result = subtract(b,a);
            result.negative = 1;
        }
        
    }
    else if(a.negative != b.negative){
        // a,b khac dau
        if(a.negative == 1 && b.negative == 0){
            // a âm, b duong
            a.negative = 0;
            result = sum(a,b);
            result.negative = 1;
        }
        else if(a.negative == 0 && b.negative == 1){
            // a duong, b am
            b.negative = 0; 
            result = sum(a,b);
            result.negative = 0;
        }
    }
    else{
        // a,b âm
        if(compareNumbers(a.numbers, b.numbers, a.size, b.size) >= 0){
            result = subtract(a,b);
            result.negative = 1;
        }
        else{
            result = subtract(b,a);
            result.negative = 0;
        }
    }
    reverse(a.numbers, a.size);
    reverse(b.numbers, b.size);
    return result;
}
int main(){
	LongInteger a, b, result;     
	read(&a, 'a');     
	read(&b, 'b');     
	 
	result = sum(a, b);     
	printf("a + b = ");     
	display(result);     
	printf("\n");    
	   
	free(result.numbers);     
	result = sub(a, b);     
	printf("a - b = ");     
	display(result);     
	printf("\n");    
	
	//Giai phong bo nho     
	free(a.numbers);    
	free(b.numbers);    
	free(result.numbers); 
}



