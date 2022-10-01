#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2)); // creating an empty character array with size of substring 
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i]; // assigning str to substring
   subStr[right - left + 1] = '\0';  // assignin last index of substring to end of file string
   return (subStr);
}

void detectTokens(char* filename){
		FILE *d; // the file pointer
	int index =0;  // index value
	char* name = (char*)malloc(500); // 100 memory allocations
	if((d=fopen(filename,"r"))==NULL) {  // opening file 
		printf("dosya acilamadi.");
	}
	else {
	
		while(!feof(d)) {  // reading data from file
			char a = fgetc(d);
			
			if(a != '\n'){  // skipping the /n character and throwing the read data into array
				name[index] = a;
				index +=1;
				
			}
			
		}
		
		fclose(d); // closing the file
		
		
		char* name1 = subString(name,0,index-2);
		int right = 0;
		int left = 0;
		
		
		while(name1[right] != '\0'){
			int b = 1;
			if(name1[right] == '/'){				
				right++;
				if(name1[right] == '*'){
					right++;
					while(b == 1 || name1[right] != EOF){
						if(name1[right] == '*'){
							right++;
							if(name1[right] == '/'){
								b = 0;
								break;
								
							}
						}
						right++;
					}
					
					
					if(name1[right] == EOF){
						printf("ERROR");
					}	
				}
			
			
			}else if(name1[right]=='['){
				
				int c = 1;
				right++;
				
				char* renk;
				
				while(name1[right] != ']') { 	
								
					if(name1[right] != '|') {
						right++;
					}
					else {
						c = 0;
						int first = right+2;
						while(name1[right] != ']') {
							right++;
						}
						 
						char* label = subString(name1, left+1, right-1);
						char* file_name = subString(name1, first, right-1); 
						
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

						SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
													
						printf("%s\n",label);
						int x;
						printf("Linke girmek icin 1 giriniz:\n");
						scanf("%d", &x);  
						
						
						if(x == 1){
							
							
								printf("------------------------new file (%s)--------------------------------\n",file_name);
								detectTokens(file_name);
						}else{
							printf("yanlis sayi girdiniz!!!!\n");
						}
					}					
				}
				
				
				if(c == 1) {
					renk = subString(name1,left+1,right-1);
					int lenght = right-left-1;
					left += right-left+2;
					while(name1[right] != '[') {
						right++;
					}
					char* text;
					text = subString(name1,left,right-1);
					if(strcmp(renk,"red")==0){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

						SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
													
						printf("%s\n",text);

					}else if(strcmp(renk,"blue")==0) {
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

						SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
													
						printf("%s\n",text);
					}
					else if(strcmp(renk,"green")==0) {
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

						SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
													
						printf("%s\n",text);
					}
					
					right += (5 + lenght);
				}
				
				
				
			}
			right++;
			left = right;
			
		}
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
		if(strcmp(filename, "dosya.txt") != 0)
		
		
		printf("------------------------end of new file (%s)--------------------------------\n",filename);
	return 0;

}	
		
}

int main(int argc, char *argv[]) {
	char* filename = "dosya.txt";
	detectTokens(filename);
	
}

