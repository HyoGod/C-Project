#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 200

void line(FILE *file, int line);
void data(char *buf, char *who);
void save(char* input, char* output, char* user_name); 
char* alloc(int len);									   
char* fileee(char *buf, int max, FILE *file);				  
char* search(char *input, int teach);			 
void  print_answer(char *output);					     
void  teacher(char *buf);						    					  
		      
int main() {
	int i, j, k,teach;
	char *output,*buf,*input;
	
	char user_name[50];
	buf = alloc(SIZE);
	srand((unsigned)time(NULL));
	data(user_name, "Your Name is ?");				
	

	
	while (true) {
		teach = 0;

		data(buf, user_name);                  
		input = alloc(strlen(buf) + 1);            
		strcpy(input, buf);                         



		if (!strcmp("잘가", input)) {			
			break;
		}
 		if (!strncmp(input, "/t ", 3)) {           
			input = input + 3;                    
			teach = 1;
		}
 

		strcpy(buf, search(input, teach));    
		output = alloc(strlen(buf) + 1);            
		strcpy(output, buf);                     
 

 
		if (strcmp(output, "")) {                   
	
			if (teach == 1) {                    
				printf("이미 심심이가 알고있습니다.\n\n");
				input = input - 3;                 
			}
			else {
				save(input, output,user_name); 
			}

			print_answer(output);                    
		
		}
		else {                                
			printf("심심이에게 단어를 알려주세요.\n\n");
			teacher(input);               
			if (teach == 1) input = input - 3;      
		}
 
		free(input);
		free(output);
	
	}

}


 void  data(char *buf, char *who) {
	fflush(stdin);                           
	while (true) {                             		 
	 printf("%s : ", who);
     fileee(buf, SIZE, stdin);
		printf("\n");

		if (strcmp(buf, "")) break;                  
	}
 
}
void line(FILE *file, int line) {
	int i;
	for (i = 0; i < line; i++) {
		while (!feof(file))
		{
			if (fgetc(file) == '\n') break;
		}
	}
}

 void save(char* input, char* output, char* user_name){
	FILE *fp;
	fp = fopen("save.txt", "a");
	fprintf(fp, "%s : %s \n심심이 : %s\n", user_name, input, output);
	fclose(fp);
}
 
char* fileee(char *buf, int max, FILE *file) {
	fgets(buf, max, file);                        
	buf[strlen(buf) - 1] = '\0';                 
	return buf;                             
}


char* alloc(int len) {
	return (char*)malloc(sizeof(char)*len);            
}
 
 

 
char* search(char *input, int teach) {
	FILE *fp;
	int output_num, random, check = 0, i;
	char *buf;
	char *similar;
	buf = alloc(SIZE);
	similar = alloc(SIZE);
	if ((fp = fopen("simsimdata.txt", "r")) == NULL) 
	return "";  
 
 
	for (i = 0; i < 2; i++) { 
		while (!feof(fp)) {                       
			fscanf(fp, "%d", &output_num);           
		fileee(buf, SIZE, fp);                  
 
			if (i == 0 && !strcmp(input, buf)) check = 1;
 
			if (i == 1 && strlen(buf) > 3 && strstr(input, buf) != NULL) { 
				check = 1;
				if (teach == 0) 
				printf("\n /t를 통해 답변을 만드실 수 있습니다.\n\n");
			}
 
			if (check == 1)                       
			{
				random = rand() % output_num;          
				line(fp, random);              
				fileee(buf, SIZE, fp);          
				fclose(fp);
				return buf;                      
			}
			line(fp, output_num + 1);            
		if (teach == 1) break;
		rewind(fp);                             
	}
 
	fclose(fp);
	return "";
}
}
 

void   print_answer(char *output) { 
	printf("심심이 :  %s\n", output);
}
 
 

void  teacher(char *input) {
	char buf[SIZE];
	int num, i;
	FILE *fp;
	fp = fopen("simsimdata.txt", "a");
 
 	printf("몇 가지 알려주실건가요?\n >>");
	
	scanf("%s", &buf);
	num = atoi(buf);

	if (num == 0) {
		fclose(fp);
		return ;
	}
	fprintf(fp, "%d%s\n", num, input);      
	for (i = 0; i < num; i++) {        
		data(buf, "TEACH");     
		fprintf(fp, "%s\n", buf);      
	}
	fprintf(fp, " \n");             
 
	fclose(fp);
}

