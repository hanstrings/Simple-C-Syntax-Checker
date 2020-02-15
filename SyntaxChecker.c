#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>   
#include<time.h>   

#define MAX_LINE_LENGTH 100 // maximum length of a line in C code
#define MAX_LINE_IN_FILE 1000 // maximum line in a C program

//user define types
typedef struct{
	int  line_no;
	int  line_len; // actual line length
	char line_type[25];
	char line_text[MAX_LINE_LENGTH];
}ccodeline_t;

// global variables
ccodeline_t *ccode, *ccode_ws;
char w[32][10]={"int","float","double","break","case","char","const","continue","default","do","else","enum","extern","for","goto","if","long","register","return","short","struct","signed","sizeof","static","switch","typedef","union","unsigned","void","volatile","while","FILE"};

//function prototypes
int read_c_code_from_file(const char *filename);//user defined functions
int readingcharacters(const char *filename,int nooflines); //user defined functions
int keywords(const char *filename);//user defined functions
int paranthesis(const char *filename);//user defined functions
int displayallsinglelinecomments  (const char *filename,int nooflines);//user defined functions
int displayallmulticomments  (const char *filename,int nooflines);
void delay(unsigned int mseconds);

int main(void){ // add command line arguments later
	int nooflines;
	int i,choice,comments;   
	char ch;
	
    ccode = (ccodeline_t *) malloc (MAX_LINE_IN_FILE * sizeof(ccodeline_t)); // allocate space for global variable
    ccode_ws = (ccodeline_t *) malloc (MAX_LINE_IN_FILE * sizeof(ccodeline_t)); // allocate space for global variable

	nooflines = read_c_code_from_file("quadratic.c");
	if (nooflines == -1){
	   puts("Error reading file binary_search.c in your program directory. Copy file.");
	   return 1; // unable to read file.
    }   
	puts("\n\n\t\t\t\tWELCOME to our Syntax Checker it is coded by the team MOB\n\nWhose member's names are listed below: \n\n1. Basit Ali(16K-3762)\n2. Munir Hassan(16K-3761)\n3. Malik Obaid(16K-3767)\n\n"); 	
	printf("\n\t\t\t\t\t\tOur program is all about...\n\n\n");
    printf("1. Show code loaded from file.\n2. Displaying whole code character by character.\n3. Number of keywords\n4. Paranthesis Matching.\n5. Display All comments\n6. Exit.\n\nEnter your choice : ");
    scanf("%d",&choice);
    while(choice!=-1){
    	switch(choice){
	    	case 1:
	    	    system("cls");
	    	    printf("\nLine #(Ch)\t\tCode in line\n");
	    	    printf("--------------------------------------------------------------------------------------\n");
		        for (i = 0; i < nooflines; i++){
			    	printf("Line %d(%d): %s\n", ccode[i].line_no, ccode[i].line_len,ccode[i].line_text);
				}
				printf("--------------------------------------------------------------------------------------\n");
				break;
	    	case 2:
	    		system("cls");
	    		readingcharacters("quadratic.c",nooflines);
	    	    break;
	    	case 3:
	    		system("cls");
	    		keywords("quadratic.c");
	    		break;
	    	case 4:
	    		system("cls");
	    		paranthesis("quadratic.c");
	    		break;
	    	case 5:
	    		system("cls");
    		    printf("\n\n\n\t\t1.Single line Comments.\n\n\t\t2.Multi Line Comments.\n\n\t\tEnter you choice : ");
    		    scanf("%d",&comments);
    		    switch(comments){
    			case 1:
    				system("cls");
    				displayallsinglelinecomments ("quadratic.c",nooflines);	
    				break;
    			case 2: 
    			    system("cls");
    			    displayallmulticomments  ("quadratic.c",nooflines);
    			    break;
    			}
    			break;
	    	case 6:
	            printf("\nThanks for using the Program..\n");
	            printf("\nExiting in 5 second...\n\n\n");
	            delay(5000);
	            return 0;
	            
			default:
				system("cls");
				printf("\nOption not available.\n");
				break;
		}
		printf("\n\n1. Show code loaded from file.\n2. Displaying whole code character by character.\n3. Number of keywords\n4. Paranthesis Matching.\n5. Display All comments\n6. Exit.\n\nEnter your choice : ");
    	scanf("%d",&choice);
	}
	free(ccode);
	free(ccode_ws);
	return 0;
}

int read_c_code_from_file (const char *filename){
	FILE *ptr_file;
	char string[MAX_LINE_LENGTH]; // max line length for reading 
	int line=1, i=0;
    ccodeline_t *c;
    
	ptr_file =fopen(filename,"r");
	if (!ptr_file) return -1; // just return -1 for all type of file reading errors

	while (fgets(string,MAX_LINE_LENGTH, ptr_file) != NULL){
		ccode[i].line_no = line;
		strcpy(ccode[i].line_text,string);
		ccode[i].line_len = strlen(string);
		line++; // for line numbers
		i++; // no traversing the array
	}
	line--; // adjust line
	fclose(ptr_file);
    return line; // return no of line read from file.
}

int readingcharacters(const char *filename,int nooflines){
	FILE *fptr;
	int i=0,j=0,line,counter=0,counter1=0;
	char string[nooflines][100],ch; // max line length for reading
	fptr =fopen(filename,"r");
	if (!fptr) return -1; // just return -1 for all type of file reading errors
    ch=fgetc(fptr);
    while(!feof(fptr)){
	    for(i=0;i<nooflines;i++){
	    	string[i][j]=ch;
	    	for(j=0;j<100;j++){
	    		if(ch=='\n'|| ch==EOF){
	    			break;
				}
				if(ch==32){
					printf("\nLine no --> (%d) character no -->(%d) is : space ",i+1,j+1);
					ch=fgetc(fptr);
	    			string[i][j]=ch;
				}	
				if(ch==9){
					printf("\nLine no --> (%d) character no -->(%d) is : tab ",i+1,j+1);
					ch=fgetc(fptr);
	    			string[i][j]=ch;
				}
				printf("\nLine no --> (%d) character no -->(%d) is : %c ",i+1,j+1,ch);
	    		ch=fgetc(fptr);
	    		string[i][j]=ch;			
			}
			ch=fgetc(fptr);
		}
	}	
}

int keywords(const char *filename){
	FILE *fptr;
	int i=0,total_ch=0,j=0,k,l,line,keywordscounter=0;
	char keywords[10000][50],ch;
	fptr =fopen(filename,"r");
	if (!fptr) return -1; // just return -1 for all type of file reading errors
	ch=fgetc(fptr);
	while(!feof(fptr)){
	    fscanf(fptr,"%s",keywords[i]);
		for(j=0;j<33;j++){
			if (strcmp(keywords[i],w[j]) == 0){
				keywordscounter++;
				break;
			}
		}
		i++;
	}
	printf("\n\nResult : There are %d keywords in the code.\n\n ",keywordscounter);
}

int paranthesis(const char *filename){
	FILE *fptr;
	int i=0,total_ch=0,j=0,line,counter=0,counter1=0;
	char ch;
	fptr =fopen(filename,"r");
	if (!fptr) return -1; // just return -1 for all type of file reading errors
    ch=fgetc(fptr);
    while(!feof(fptr)){
    	if(ch=='{' || ch== '(' || ch=='['){
			counter++;
			}
		if(ch=='}' || ch== ')' || ch==']'){
			counter1++;
		}
		ch=fgetc(fptr);
    }
	if(counter==counter1){
		printf("\n\nResult : Paranthesis are syntactically in order.\n\n");
	}
	else{
		printf("\n\nResult : Paranthesis are syntactically disordered.\n\n");	
	}
}

int displayallsinglelinecomments  (const char *filename,int nooflines){
	FILE *fptr;
	int i=0,j=0,line,counter=0,counter1=0,z=0;
	char string[nooflines][100],ch; // max line length for reading f
	
	fptr =fopen(filename,"r");
	if (!fptr) return -1; // just return -1 for all type of file reading errors
        ch=fgetc(fptr);
        printf("\n\n---------------SINGLE LINE COMMENTS SUMMARY----------------\n\n");
    	while(!feof(fptr)){
    		for(i=0;i<nooflines;i++){
    			string[i][j]=ch;
    			for(j=0;j<100;j++){
    				if(ch=='\n'|| ch==EOF){
    					break;
					}	
					if(ch=='/'){
						ch=fgetc(fptr);
    				    string[i][j]=ch;
						if(ch=='/'){
							printf("\nThere is a single Comment in line no %d which is : //",i+z+1);
							while(ch!='\n'){
								ch=fgetc(fptr);
    				            string[i][j]=ch;
    				            printf("%c",ch);
							}
							z++;
						}
					}
    				ch=fgetc(fptr);
    				string[i][j]=ch;
    				
				}
				ch=fgetc(fptr);
			}
		}
		printf("\n\nIn total there are %d single line comments in code . \n\n",z);
}


int displayallmulticomments  (const char *filename,int nooflines){
	FILE *fptr;
	int i=0,j=0,line,z=0,k;
	char string[nooflines][100],ch; // max line length for reading f
	
	fptr =fopen(filename,"r");
	if (!fptr) return -1; // just return -1 for all type of file reading errors
        ch=fgetc(fptr);
        printf("\n\n---------------MULTI LINE COMMENTS SUMMARY----------------\n\n");
    	while(!feof(fptr)){
    		for(i=0;i<nooflines;i++){
    			string[i][j]=ch;
    			for(j=0;j<100;j++){	
    			    if(ch=='\n'|| ch==EOF){
    					break;
					}
					if(ch=='/'){
						ch=fgetc(fptr);
    				    string[i][j]=ch;
						if(ch=='*'){
							k=i+1;
							printf("\nMulti line comment is  : /* ");
							while(ch!='/'){
								if(ch=='\n'){
									i++;
								}
								ch=fgetc(fptr);
    				            string[i][j]=ch;
    				            printf("%c",ch);
							}
							printf("\n\nThe multi line comment is from line no %d to line no %d\n\n",k,i+1);
							z++;
						}
					}
    				ch=fgetc(fptr);
    				string[i][j]=ch;
    				
				}
				ch=fgetc(fptr);
			}
		}
		printf("\n\nIn total there are %d multi line comments  in code. \n\n",z);
}

void delay (unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


